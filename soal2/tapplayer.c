#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <termios.h>
#include <pthread.h>

#define PORT 8080

int space_scanner = 0;
int space_pressed = 0;
int sock = 0, valread;
int running_game = 0;
int screen = 1;

static struct termios old, new;

void initTermios(int echo) //digunakan untuk menghidupkan scanner spasi
{
  tcgetattr(0, &old);
  new = old;
  new.c_lflag &= ~ICANON;
  new.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &new);
}
 
void resetTermios(void) //untuk dikembalikan stdin nya ke keadaan semula
{
  tcsetattr(0, TCSANOW, &old);
}

char getch()
{
  char ch;
  initTermios(0);
  ch = getchar();
  resetTermios();
  return ch;
}

void *spaceScanner() //thread untuk nangkap inputan sejumlah 1 karakter
{
  while(running_game)
    while(space_scanner)
    {
      if (getch() == 32) //kalo getch nya ngereturn spasi
      {
        space_pressed = 1;
        space_scanner = 0; 
      }
    }
  pthread_exit(0);
}

void *runGame()
{
  running_game = 1;
  while(1)
  {
    space_scanner = 1; //lagi butuh space scanner
    char buffer[1024] = {0};
    char new_buffer[64] = "kosong";

    if (space_pressed)  //kalo kepencet spasi dia kirim buffer hit ke server
    {
      char hit[10] = "hit !!";
      strcpy(new_buffer, hit);
      space_pressed = 0; //spasi udah dipencet
    }

    send(sock, new_buffer, strlen(new_buffer), 0 ); //ngirim buffer apa aja ke server
    memset(new_buffer, 0, sizeof(new_buffer));
    valread = read(sock, buffer, 1024);
    if (strcmp(buffer, "kosongs") != 0 && strcmp(buffer, "Game berakhir kamu kalah") != 0 && strcmp(buffer, "Game berakhir kamu menang") != 0) // kondisi pada saat server ngirim nyawa
      puts(buffer); //terus di print nyawa nya

    if (strcmp(buffer, "Game berakhir kamu kalah") == 0 || strcmp(buffer, "Game berakhir kamu menang") == 0) //kondisi pada saat ada yang menang dan ada yg kalah
    {
      puts(buffer); //terus di print pesan nya
      screen = 2; //terus kembali ke screen 2 karena permainan sudah selesai
      break;
    }
  }
  space_scanner = 0; // tanda gak perlu lagi nge scan
  running_game = 0; // tanda game berakhir
  pthread_exit(0);
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in serv_addr; 
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1)
    {
      if (screen == 1) //awal program berjalan akan masuk ke screen 1
      {
        char cmd[100];
        memset(cmd, 0, sizeof(cmd)); 
        printf("1. Login\n");
        printf("2. Register\n");
        printf("   Choices : ");
        
        scanf("%s", cmd);
        
        send(sock, cmd , strlen(cmd), 0 );
        valread = read(sock, buffer, 1024);

        if (strcmp(buffer, "login") == 0 || strcmp(buffer, "register") == 0) // kalo login atau register
        {
          char userpass[1024] = {0};
          char username[128];
          char password[128];
          int f;
          printf("   Username : ");
          scanf("%d", &f);
          memset(username, 0, sizeof(username));
          scanf("%[^\n]", username); //supaya input bisa dianggap sebagai inputan sampai enter

          printf("   Password : ");
          memset(password, 0, sizeof(password));
          scanf("%d", &f);
          scanf("%[^\n]", password);

          sprintf(userpass, "%s - %s\n", username, password);
          
          send(sock, userpass, strlen(userpass), 0 );
          
          read(sock, buffer, 1024);

          if(strcmp(buffer, "Auth success") == 0) //kondisi pada saat dia berhasil login
          {
            printf("   Login success\n");
            screen = 2; //kalo berhasil login, pindah ke screen 2
          }
          else if(strcmp(buffer, "Auth failed") == 0) //kalo dia gagal login
            printf("   Login failed\n");
          else 
            printf("   Register success\n"); //registrasi sukses
            
          memset(buffer, 0, sizeof(buffer));
        }      
        else
        {
          printf("   %s\n", buffer); //ngeprint invalid command yang diterima dari server
          memset(buffer, 0, sizeof(buffer));
        }


      }
      
      if (screen == 2) //kondisi masuk ke screen 2
      {
        char cmd[100];
        printf("1. Find Match\n2. Logout\n   Choices : ");
        scanf("%s", cmd);
        if (strcmp(cmd, "find") == 0)
        {
          send(sock, cmd , strlen(cmd), 0 ); //send find ke server
      
          memset(buffer, 0, sizeof(buffer)); 
          valread = read(sock, buffer, 1024); //read dari server apakah masih nunggu player atau sudah bisa dimulai

          if(strcmp(buffer, "Waiting for player ...") == 0)
            printf("   %s\n", buffer);
          
          while(1)
          {
            if(strcmp(buffer, "Game dimulai silahkan tap tap secepat mungkin !!") == 0)
             break;
            else
              read(sock, buffer, 1024); // untuk nerima sampai keluar pesan game sedang dimulai
          }
          screen = 3; // masuk ke screen 3 yang artinya mulai main
        }
        else if (strcmp(cmd, "logout") == 0) //kondisi kalau logout
        {
          send(sock, cmd , strlen(cmd), 0 );
          screen = 1; //kembali ke screen 
        }
        else
          puts("invalid command"); 
      }

      if (screen == 3)
      {
        printf("   %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
        
        space_scanner = 1; //ngehidupin space scanner untuk supaya minta spasi
        pthread_t threads[2]; //deklarasi array of thread
        pthread_create(&threads[0], NULL, runGame, NULL); //buat thread untuk menjalankan fungsi runGame
        pthread_create(&threads[1], NULL, spaceScanner, NULL); //buat thread untuk menjalankan fungsi spaseScanner

        pthread_join(threads[0], NULL); //nunggu thread[0] selesai
        pthread_cancel(threads[1]); // buat matiin thread[1]
        resetTermios(); 
        read(sock, buffer, 1024);
        memset(buffer, 0, sizeof(buffer));
      }
    }
}
