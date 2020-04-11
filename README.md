# SoalShiftSISOP20_modul3_C07

##### Fandi Wahyu R - 05111840000108, Brananda Denta WP - 05111840000143

### Outline
+ [Soal 1](#soal-1)
    * [1a](#1a)
    * [1b](#1b)
+ [Soal 2](#soal-2)
+ [Soal 3](#soal-3)
+ [Soal 4](#soal-4)
    * [4a](#4a)
    * [4b](#4b)
    * [4c](#4c)

## Soal 1
### Soal
1. Poke*ZONE adalah sebuah game berbasis text terminal mirip dengan Pokemon GO.
Ketentuan permainan sebagai berikut:
a. Menggunakan IPC-shared memory, thread, fork-exec.
b. Kalian bebas berkreasi dengan game ini asal tidak konflik dengan
requirements yang ada. (Contoh: memberi nama trainer, memberi notifikasi
kalau barang di shop sudah penuh, dan lain-lain).
c. Terdapat 2 code yaitu soal2_traizone.c dan soal2_pokezone.c.
d. soal2_traizone.c mengandung fitur:
i. Normal Mode (3 Menu)
1. Cari Pokemon
a. Jika diaktifkan maka setiap 10 detik akan memiliki
60% chance untuk menemui pokemon bertipe normal,
rare, legendary dengan encounter rate sesuai pada
tabel di bawah (Gunakan Thread).
b. Cari pokemon hanya mengatur dia menemukan
pokemon atau tidak. Untuk tipe pokemon dan pokemon
tersebut shiny atau tidak diatur oleh soal2_pokezone.c.
c. Opsi “Cari Pokemon” akan berubah jadi “Berhenti
Mencari” ketika state mencari pokemon aktif.
d. State mencari pokemon hanya bisa dihentikan ketika
pokemon sudah ditemukan atau trainer memilih untuk
berhenti pada menu.
e. Jika menemui pokemon maka akan masuk ke Capture
Mode.
f. Untuk mempermudah boleh menambah menu go to
capture mode untuk berpindah dari mode normal ke
mode capture setelah menemukan pokemon dari
thread Cari Pokemon.

2. Pokedex
a. Melihat list pokemon beserta Affection Point (AP) yang
dimiliki.
b. Maksimal 7 pokemon yang dimiliki.
c. Jika menangkap lebih dari 7 maka pokemon yang baru
saja ditangkap akan langsung dilepas dan
mendapatkan pokedollar sesuai dengan tabel dibawah.
d. Setiap pokemon yang dimiliki, mempunyai Affection
Point (AP) dengan initial value 100 dan akan terus
berkurang sebanyak -10 AP/10 detik dimulai dari
waktu ditangkap (Gunakan Thread).
e. Jika AP bernilai 0, maka pokemon tersebut memiliki
90% chance untuk lepas tanpa memberikan pokedollar
ke trainer atau 10% chance untuk reset AP menjadi 50
AP.
f. AP tidak akan berkurang jika dalam Capture Mode.

g. Di Pokedex trainer juga bisa melepas pokemon yang
ditangkap dan mendapat pokedollar sesuai dengan
tabel dibawah.
h. Bisa memberi berry ke semua pokemon yang dimiliki
untuk meningkatkan AP sebesar +10 (1 berry untuk
semua pokemon yang ada di pokedex).

3. Shop
a. Membeli item dari soal2_pokezone.
b. Maksimal masing-masing item yang dapat dibeli dan
dipunya oleh trainer adalah 99.

ii. Capture Mode (3 Menu)
1. Tangkap → Menangkap menggunakan pokeball. Berhasil
ditangkap maupun tidak, pokeball di inventory -1 setiap
digunakan.
2. Item → Menggunakan item sesuai dengan tabel item dibawah
(hanya lullaby powder).
3. Keluar → Keluar dari Capture Mode menuju Normal Mode.
● Pokemon tersebut memiliki peluang untuk lari dari trainer
sesuai dengan persentase escape rate pada tabel dibawah
(gunakan thread).
e. soal2_pokezone.c mengandung fitur:
i. Shutdown game → Mematikan program soal2_pokezone dan
soal2_traizone (Gunakan fork-exec).
ii. Jual Item (Gunakan Thread)
1. Stock awal semua item adalah 100.
2. Masing-masing item akan bertambah +10 item/10 detik.
3. Maximum item yang dalam shop adalah 200.
4. List item ada pada tabel dibawah.



15 - No Yes

5. Gunakan thread untuk implementasi lullaby powder dibuatkan
masing-masing 1 thread.

iii. Menyediakan Random Pokemon (Gunakan Thread)
1. Setiap tipe pokemon memiliki peluang 1/8000 untuk jadi shiny
pokemon. (Random dulu antara normal, rare, legendary sesuai
rate mereka, baru setelah itu di random dengan peluang
1/8000 untuk tahu dia shiny atau tidak).
2. Shiny Pokemon meningkatkan escape rate sebesar +5%
(misal: tipe normal jadi 10%), capture rate berkurang menjadi
-20% (misal: tipe rare jadi 30%), dan pokedollar dari melepas
+5000 (misal: tipe legendary jadi 5200 pokedollar).
3. Setiap 1 detik thread ini akan mengkalkulasi random ulang lagi
untuk nantinya diberikan ke soal2_traizone.

## Soal 2
Qiqi adalah sahabat MamMam dan Kaka. Qiqi , Kaka dan MamMam sangat senang
bermain “Rainbow six” bersama-sama , akan tetapi MamMam sangat Toxic ia selalu
melakukan Team killing kepada Qiqi di setiap permainannya. Karena Qiqi orang yang
baik hati, meskipun marah Qiqi selalu berkata “Aku nggk marah!!”. Kaka ingin
meredam kemarahan Qiqi dengan membuatkannya sebuah game yaitu TapTap
Game. akan tetapi Kaka tidak bisa membuatnya sendiri, ia butuh bantuan mu. Ayo!!
Bantu Kaka menenangkan Qiqi.
TapTap Game adalah game online berbasis text console. Terdapat 2 program yaitu
tapserver.c dan tapplayer.c
Syarat :
- Menggunakan Socket, dan Thread
Hint :
- fwrite, fread
Spesifikasi Game :

CLIENT SIDE

Screen 1 :
1. Login
2. Register
Choices : {your input}
★ Pada screen 1 kalian dapat menginputkan “login”, setelah menekan enter
anda diminta untuk menginputkan username dan password seperti berikut
Screen 1 :
1. Login
2. Register
Choices : login
Username : { ex : qiqi }
Password : { ex : aku nggak marah!! }
★ Jika login berhasil maka akan menampilkan pesan “login success”, jika gagal
akan menampilkan pesan “login failed” (pengecekan login hanya mengecek
username dan password, maka dapat multi autentikasi dengan username dan
password yang sama)
★ Pada screen 1 kalian juga dapat menginputkan “register”, setelah menekan
enter anda diminta untuk menginputkan username dan password sama
halnya seperti login
★ Pada register tidak ada pengecekan unique username, maka setelah register
akan langsung menampilkan pesan “register success” dan dapat terjadi
double account
★ Setelah login berhasil maka anda berpindah ke screen 2 dimana
menampilkan 2 fitur seperti berikut.

Screen 2 :
1. Find Match
2. Logout
Choices : {your input}
★ Pada screen 2 anda dapat menginputkan “logout” setelah logout anda akan
kembali ke screen 1
★ Pada screen 2 anda dapat menginputkan “find”, setelah itu akan
menampilkan pesan “Waiting for player ...” print terus sampai menemukan
lawan
★ Jika menemukan lawan maka akan menampilkan pesan “Game dimulai
silahkan tap tap secepat mungkin !!”
★ Pada saat game dimulai diberikan variable health = 100,dan anda dapat
men-tap (menekan space pada keyboard tanpa harus menekan enter)
★ Pada saat anda men-tap maka akan menampilkan pesan “hit !!”, dan pada
lawan healthnya akan berkurang sebanyak 10 kemudian pada lawan
menampilkan pesan status healthnya sekarang. (conclusion : anda tidak bisa
melihat status health lawan)
★ Jika health anda <= 0 maka akan menampilkan pesan “Game berakhir kamu
kalah”, apabila lawan anda healthnya <= 0 maka akan menampilkan pesan
”Game berakhir kamu menang”
★ Setelah menang atau kalah maka akan kembali ke screen 2

SERVER SIDE

★ Pada saat program pertama kali dijalankan maka program akan membuat file
akun.txt jika file tersebut tidak ada. File tersebut digunakan untuk menyimpan
username dan password
★ Pada saat user berhasil login maka akan menampilkan pesan “Auth success” jika
gagal “Auth Failed”
★ Pada saat user sukses meregister maka akan menampilkan List account yang
terdaftar (username dan password harus terlihat)

### tapserver
membuat fungsi untuk mengecek ketika login di cek apakah sudah ada data nya atau belum di daftar registrasi
```c
int accountExist(char userpass[]) //fungsi untuk mengecek login apakah sudah ada data registrasinya atau belum
{
  FILE *file = fopen("akun.txt", "r");
  if ( file != NULL )
  {
    char line[256];
    while (fgets(line, sizeof line, file) != NULL)
    {
      if (strcmp(line, userpass) == 0)
      {
        fclose(file);
        return 1;
      }
    }
    fclose(file);
  }

  return 0;
}
```
membuat fungsi untuk menghandle client
```c
void *createServer(void* arg) //fungsi untuk meng handle client client yang ada
{
  int player_id = *(int*)arg;

  int new_socket;

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  int state_login = -1;

  char buffer[1024] = {0};
  char new_buffer[1024] = "login";
  while(1)
  {
    char userpass[1024] = {0};

    memset(buffer, 0, sizeof(buffer)); 
    valread = read(new_socket, buffer, 1024);
    char value_now[1024];

    if(strcmp(buffer, "login") == 0) //kondisi saat client minta login
    {
      send(new_socket, new_buffer, strlen(new_buffer), 0);
      read(new_socket, buffer, 1024);
      
      char login_message[100];
      if(accountExist(buffer))
        strcpy(login_message, "Auth success"); //print auth success
      else
        strcpy(login_message, "Auth failed"); //print auth failed
      puts(login_message);

      send(new_socket, login_message, strlen(login_message), 0); 
      memset(buffer, 0, sizeof(buffer)); 
      state_login = 1; 
    }
    else if(strcmp(buffer, "register") == 0) //kondisi pada saat server minta login
    {
      fp = fopen ("akun.txt", "a"); //meng append file akun.txt
      
      send(new_socket, buffer, strlen(buffer), 0);
      memset(buffer, 0, sizeof(buffer)); 
      
      read(new_socket, buffer, 1024);
      fputs(buffer, fp); //masukin data register ke file akun.txt
      fclose(fp);

      char register_success[100] = "register success"; 
      send(new_socket, register_success, strlen(register_success), 0); //send register success

      fp = fopen ("akun.txt", "r"); 
      char c = fgetc(fp); 
      while (c != EOF) //untuk ngeprint file akun.txt sampai semua
      { 
        printf ("%c", c); 
        c = fgetc(fp); 
      }
      fclose(fp);

      state_login = 0;
    }
    else if(strcmp(buffer, "find") == 0)
    {
      // puts(buffer);
      int enemy = -1;
      int waiting = 0;
      char status[100] = "Waiting for player ...";
      // puts(status);
      
      while((enemy == -1 || enemy == player_id) && matchup[player_id] == -1) //while untuk nunggu apakah sudah ada lawan atau belum
      {
        if(isEmpty(queue))
          enqueue(queue, player_id);
        else
          enemy = dequeue(queue);

        if(enemy != player_id && enemy != -1) //kondisi ketika menemukan musuh
        {
          matchup[player_id] = enemy; //dicocokkan agar terjadi match up dengan lawan
          matchup[enemy] = player_id;
          
          while(queue->front == player_id || queue->front == enemy)
            dequeue(queue);
          break;
        }
        else
        {
          if(waiting == 0)
          {
            send(new_socket, status, sizeof(status), 0);
            waiting = 1;
          }
        }
        sleep(1);
      }

      health[player_id] = 100;
      enemy = matchup[player_id];

      while(health[enemy] != 100); //nunggu lawan ready
      strcpy(status, "Game dimulai silahkan tap tap secepat mungkin !!");
      send(new_socket, status, sizeof(status), 0); //ketika lawan ready, maka send game dimulai 

      memset(status, 0, sizeof(status));
      int current_health = health[player_id];
      while(health[player_id] && health[enemy]) //loop untuk berjalan nya game
      {
        char new_status[1024] = "kosongs";
        read(new_socket, buffer, 1024);

        if(strcmp(buffer, "hit !!") == 0) //kondisi kalo hit berarti health nya -10
        {
          // printf("%d vs %d\n", health[player_id], health[enemy]);
          health[enemy] -= 10;
          memset(buffer, 0, sizeof(buffer));
        }
        else
          strcpy(new_status, "kosongs");

        if(health[player_id] != current_health)
        {
          current_health = health[player_id]; //ngeupdate nyawa
          sprintf(new_status, "%d", current_health);
        }

        send(new_socket, new_status, sizeof(new_status), 0); //kirim update nyawa

      }
      if (health[player_id]) //kalo nyawanya masih ada berarti menang
        strcpy(status, "Game berakhir kamu menang");
      else
        strcpy(status, "Game berakhir kamu kalah"); //kalo nyawa habis berarti kalah
      send(new_socket, status, sizeof(status), 0);
      matchup[player_id] = -1;
    }
    else if (strcmp(buffer, "logout") == 0) //kondisi kalau log out
    {
      state_login = -1;
    }
    else
    {
      strcpy(buffer, "invalid command");
      send(new_socket, buffer, sizeof(buffer), 0);
      memset(buffer, 0, sizeof(buffer)); 
    }
  }
}
```
lalu dalam int main, membuat deklarasi thread of array sebanyak pemain yang bisa bermain. lalu dijalankan thread nya
```c
  pthread_t threads[100]; //deklarasi array of thread untuk menghandle banyak pemain
  for (int i = 0; i < 100; i++)
  {
    int *new_val = &i;
    pthread_create(&threads[i], NULL, createServer,  (void *)new_val); //menjalankan fungsi untuk menghandle pemain
  }
  
  for (int i = 0; i < 100; i++)  
    pthread_join(threads[i], NULL); 

```


### tapplayer
membuat fungsi untuk supaya ketika memencet spasi, langsung dianggap sebagai inputan tanpa memencet enter
```c
void initTermios(int echo)
{
  tcgetattr(0, &old);
  new = old;
  new.c_lflag &= ~ICANON;
  new.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &new);
}
```
membuat fungsi untuk menangkap input sejumlah 1 karakter
```c
void *spaceScanner() //thread untuk nangkap inputan sejumlah 1 karakter
{
  while(running_game)
    while(space_scanner)
    {
      if (getch() == 32) //kalo getch nya ngereturn spasi
      {
        space_pressed = 1; //tanda kalo spasi dipencet
        space_scanner = 0; 
      }
    }
  pthread_exit(0);
}
```
membuat fungsi untuk ketika run game
```c
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
```
lalu di dalam while yang ada pada int main, membuat kondisi pada screen 1 yang menghandle ketika login atau register
```c
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
```
lalu membuat kondisi screen 2 pada saat dia find match dan logout
```c
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
```
lalu saya bikin screen ke 3 yang berguna untuk menjalankan permainkan
```c
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
```

## Soal 3
### Soal
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
directory ketika program kategori tersebut dijalankan.

● Semisal program dijalankan:
# File kategori terletak di /home/izone/kategori

$ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip

#Hasilnya adalah sebagai berikut

/home/izone

|-jpg

|--file1.jpg

|-c

|--file2.c

|-zip

|--file3.zi

● Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
dikategorikan sebanyak yang user inginkan seperti contoh di atas.

● Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.

● Program kategori ini juga menerima perintah (*) seperti di bawah;
$ ./kategori \*

● Artinya mengkategori seluruh file yang ada di working directory ketika
menjalankan program C tersebut.

● Selain hal itu program C ini juga menerima opsi -d untuk melakukan kategori
pada suatu directory. Untuk opsi -d ini, user hanya bisa menginput 1 directory
saja, tidak seperti file yang bebas menginput file sebanyak mungkin.
$ ./kategori -d /path/to/directory/

● Hasilnya perintah di atas adalah mengkategorikan file di /path/to/directory dan
hasilnya akan disimpan di working directory di mana program C tersebut
berjalan (hasil kategori filenya bukan di /path/to/directory).

● Program ini tidak rekursif. Semisal di directory yang mau dikategorikan, atau
menggunakan (*) terdapat folder yang berisi file, maka file dalam folder
tersebut tidak dihiraukan, cukup file pada 1 level saja.

● Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan
secara paralel sehingga proses kategori bisa berjalan lebih cepat. Dilarang
juga menggunakan fork-exec dan system.

● Silahkan download soal3.zip sebagai percobaan. Namun silahkan
dicoba-coba sendiri untuk kemungkinan test case lainnya yang mungkin
belum ada di soal3.zip.

### penyelesaian
Deklarasi terlebih dahulu `pthread_t tid[100]` serta `char wdasal[1024]`

membuat fungsi yang berguna untuk membedakan directory dengan file biasa
```
int cekfile(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
```

lalu membuat fungsi void untuk perintah -d yang merupakan fungsi untuk memindahkan file dari direktori a ke direktori tempat file dituju
```
void* pindahd(void *arg) {
	char *path;
	char format[100], dirname[100], a[100], b[100], namafile[100];
	path = (char *) arg;
	
	strcpy(a, arg);
	strcpy(b, arg);
	char *split1, *split2, *titik[5], *slash[5];
	int n = 0;
	split1 = strtok(path, ".");
	while(split1 != NULL) {
		titik[n] = split1;
		n++;
		split1 = strtok(NULL, ".");
	}

	if(n != 1) {
		int a;
		for(a = 0; a < strlen(titik[n-1]); a++) {
			format[a] = tolower(titik[n-1][a]);
		}
	}
	else if (n == 1) {
		strcpy(format, "Unknown");
	}

	n = 0;
	split2 = strtok(b, "/");
	while(split2 != NULL) {
		slash[n] = split2;
		n++;
		split2 = strtok(NULL, "/");
	}
	strcpy(namafile, slash[n-1]);

	strcpy(dirname, wdasal);
	strcat(dirname, "/");
	strcat(dirname, format);

	memset(format, 0, 100);
	mkdir(dirname, 0777);

	FILE *psrc, *ptjn;

	psrc = fopen(a, "r");
	strcat(dirname, "/");
	strcat(dirname, namafile);
	ptjn = fopen(dirname, "w");
	if(!psrc) {
		printf("error\n");
	}
	if(!ptjn) {
		printf("error\n");
	}

	int ch;
	
	while ((ch = fgetc(psrc)) != EOF) {
		fputc(ch, ptjn);
	}

	fclose(psrc);
	fclose(ptjn);
	remove(a);

	return NULL;
}
```

untuk mengambil extensi nya, digunakan `strtok` yang biasa digunakan untuk memisahkan string setelah `.`
```
	split1 = strtok(path, ".");
	while(split1 != NULL) {
		titik[n] = split1;
		n++;
		split1 = strtok(NULL, ".");
	}
```

karena disoal tidak berlaku case sensitive, yang artinya tidak memperdulikan bahwa huruf kapital dan biasa akan dianggap sama, maka digunakan `tolower` untuk menconvert huruf kapital menjadi huruf kecil.
```
	if(n != 1) {
		int a;
		for(a = 0; a < strlen(titik[n-1]); a++) {
			format[a] = tolower(titik[n-1][a]);
		}
	}
```

lalu membuat kondisi ketika ada file yang tidak punya extensi akan dimasukkan ke dalam folder bernama unknown
```
	else if (n == 1) {
		strcpy(format, "Unknown");
	}
```

Untuk mendapatkan nama file yang diinginkan menggunakan
```
	split2 = strtok(b, "/");
	while(split2 != NULL) {
		slash[n] = split2;
		n++;
		split2 = strtok(NULL, "/");
	}
	strcpy(namafile, slash[n-1]);
```

Selanjutnya untuk mengambil alamat cwd serta proses untuk memindahkan file dalam bahasa c menggunakan,
```
	strcpy(dirname, wdasal);
	strcat(dirname, "/");
	strcat(dirname, format);

	memset(format, 0, 100);
	mkdir(dirname, 0777);

	FILE *psrc, *ptjn;
	//psrc itu source
	//ptjn itu tujuan
	psrc = fopen(a, "r");
	strcat(dirname, "/");
	strcat(dirname, namafile);
	ptjn = fopen(dirname, "w");
	if(!psrc) {
		printf("error\n");
	}
	if(!ptjn) {
		printf("error\n");
	}

	int ch;
	//memindahkan file di c
	while ((ch = fgetc(psrc)) != EOF) {
		fputc(ch, ptjn);
	}
	fclose(psrc);		//menutup file yang ditunjuk pointer psrc
	fclose(ptjn);		//menutup file yang ditunjuk pointer ptjn
	remove(a);
```

Sedangkan untuk fungsi `pindah` disini untuk mengecek serta memindahkan file digunakan untuk perintah -f dan *
```
void* pindah(void *arg) {
	char *path;
	char format[100], dirname[100], a[100], b[100], namafile[100];
	
	path = (char *) arg;
	strcpy(a, arg);
	strcpy(b, arg);
	
	char *split1, *split2, *titik[5], *slash[5];
	int n = 0;

	split1 = strtok(path, ".");
	while(split1 != NULL) {
		titik[n] = split1;
		n++;
		split1 = strtok(NULL, ".");
	}
    
	if(n != 1) {
		int a;
		for(a = 0; a < strlen(titik[n-1]); a++) {
		    format[a] = tolower(titik[n-1][a]);
	    }
	}
	else if (n == 1) {
		strcpy(format, "Unknown");
	}

	n = 0;
	split2 = strtok(b, "/");
	while(split2 != NULL) {
		slash[n] = split2;
		n++;
		split2 = strtok(NULL, "/");
	}
	strcpy(namafile, slash[n-1]);

	char wdtujuan[1024];
	getcwd(wdtujuan, sizeof(wdtujuan));
	strcpy(dirname, wdtujuan);
	strcat(dirname, "/");
	strcat(dirname, format);

	memset(format, 0, 100);
	mkdir(dirname, 0777);

	FILE *psrc, *ptjn;

	psrc = fopen(a, "r");
	strcat(dirname, "/");
	strcat(dirname, namafile);
	ptjn = fopen(dirname, "w");

	if(!psrc) {
		printf("error\n");
	}
	if(!ptjn) {
		printf("error\n");
	}

	int ch;
	while ((ch = fgetc(psrc)) != EOF) {
		fputc(ch, ptjn);
	}

	fclose(psrc);
	fclose(ptjn);
	remove(a);

	return NULL;
}
```

Untuk penjelasan kedua fungsi diatas sama saja strukturnya. Sebenarnya fungsi `pindah` dan `pindahd` bisa digabung, namun karena dua command `-f` dan `\*` itu bekerja di direktori sendiri, sedangkan untuk comman `-d` itu bekerja di beda direktori. Perbedaannya pada fungsi `pindahd` terdapat `char wdasal[1024]` yang dideclare sebagai variabel global, sedangkan pada fungsi `pindah` terdapat `char wdtujuan[1024]` yang dideclare didalam fungsi itu sendiri.

Selanjutnya masuk ke program driver untuk menguji fungsi di atas
```
int main(int argc, char *argv[]) {

	getcwd(wdasal, sizeof(wdasal));

	// if(getcwd(wdasal, sizeof(wdasal)) != NULL) {
	// 	printf("%s\n", wdasal);		//untuk ngeprint directorynya
	// }

	int i;
	// jika command yang dimasukkan -f
	if(strcmp(argv[1], "-f") == 0) {
		for(i = 2; i < argc; i++) {
			if(cekfile(argv[i])) {
				pthread_create(&(tid[i-2]), NULL, pindah, (void *)argv[i]);
			}
		}
		for(i = 0; i < argc - 2; i++) {
			pthread_join(tid[i], NULL);
		}
	}
	// jika command yang dimasukkan \*
	else if(strcmp(argv[1], "*") == 0 && argc == 2) {
		DIR *dr;
		struct dirent *d;
		dr = opendir(".");

		if (dr == NULL) {
			printf("Direktori tidak dapat ditemukan" );
		}
		else {
			i = 0;
			char workd[1024], subdir[1024];
			getcwd(workd, sizeof(workd));
			while((d = readdir(dr)) != NULL){	//mengambil file dan direktori sampai tidak null
				if(cekfile(d->d_name)) {	//diseleksi lagi untuk yang diambil nanti hanya file saja
					strcpy(subdir, workd);
					strcat(subdir, "/");
					strcat(subdir, d->d_name);
					pthread_create(&(tid[i]), NULL, pindah, (void *)subdir); //membuat thread
					pthread_join(tid[i], NULL);				 //join thread
					i++;
				}
			}
			closedir(dr);
		}
	}
	// jika command yang dimasukkan -d
	else if(strcmp(argv[1], "-d") == 0 && argc == 3) {
		chdir(argv[2]);
		DIR *dr;
		struct dirent *d;
		dr = opendir(".");
		if (dr == NULL) {
			printf("Direktori tidak dapat ditemukan" );
		}
		else {
		i = 0;
			char workd[1024], subdir[1024];
			getcwd(workd, sizeof(workd));
			while((d = readdir(dr)) != NULL){
				if(cekfile(d->d_name)) {
					strcpy(subdir, workd);
					strcat(subdir, "/");
					strcat(subdir, d->d_name);
					pthread_create(&(tid[i]), NULL, pindahd, (void *)subdir);  //membuat thread
					pthread_join(tid[i], NULL);				   //join thread
					i++;
				}
			}
			closedir(dr);
		}
	}
	//jika argumen yang diinputkan tidak sesuai
	else {
		printf("argumen yang diinput salah\n");
	}

	return 0;
}
```

## Soal 4
### Soal
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri
jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap
pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan
setiap batunya memiliki warna yang berbeda.
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat
mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di
pilar tersebut. Norland menghampiri setiap pilar secara bergantian.
- Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada
batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:
1. Buatlah program C dengan nama "4a.c", yang berisi program untuk
melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
2. Tampilkan matriks hasil perkalian tadi ke layar.

- Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya
adalah:

1. Buatlah program C kedua dengan nama "4b.c". Program ini akan
mengambil variabel hasil perkalian matriks dari program "4a.c" (program
sebelumnya), dan tampilkan hasil matriks tersebut ke layar.
(Catatan!: gunakan shared memory)
2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan
format seperti matriks.

Contoh: misal array [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...],

maka:

1 2 6 24
120 720 ... ...
...

(Catatan! : Harus menggunakan Thread dalam penghitungan
faktorial)
- Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan
teka-teki berikut!

1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak
memiliki hubungan terhadap program yang lalu.
2. Pada program ini, Norland diminta mengetahui jumlah file dan
folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
IPC, Norland mengerjakannya dengan semangat.
(Catatan! : Harus menggunakan IPC Pipes)
Begitu batu terakhir berhasil didapatkan. Gemuruh yang semakin lama semakin
besar terdengar. Seluruh tempat berguncang dahsyat, tanah mulai merekah. Sebuah
batu yang di atasnya terdapat kotak kayu muncul ke atas dengan sendirinya.

Sementara batu tadi kembali ke posisinya. Tanah kembali menutup, seolah tidak
pernah ada lubang merekah di atasnya satu detik lalu.
Norland segera memasukkan tiga buah batu mulia Emerald, Amethys, Onyx pada
Peti Kayu. Maka terbukalah Peti Kayu tersebut. Di dalamnya terdapat sebuah harta
karun rahasia. Sampai saat ini banyak orang memburu harta karun tersebut.
Sebelum menghilang, dia menyisakan semua petunjuk tentang harta karun tersebut
melalui tulisan dalam buku catatannya yang tersebar di penjuru dunia. "One Piece
does exist".

### 4a
```
#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main () {
	key_t key = 1234;
    int *value;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);
	int matrix1[4][2];
	int matrix2[2][5];
	int hsl[10][10];
	int sum,i,j,k;
	int r1=4;
	int c1=2;
	int r2=2;
	int c2=5;
	
	matrix1[0][0]=1;
	matrix1[0][1]=2;
	matrix1[1][0]=2;
	matrix1[1][1]=2;
	matrix1[2][0]=1;
	matrix1[2][1]=2;
	matrix1[3][0]=1;
	matrix1[3][1]=1;
	
	matrix2[0][0]=2;
	matrix2[0][1]=2;
	matrix2[0][2]=2;
	matrix2[0][3]=1;
	matrix2[0][4]=1;
	matrix2[1][0]=2;
	matrix2[1][1]=1;
	matrix2[1][2]=2;
	matrix2[1][3]=1;
	matrix2[1][4]=2;
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<c1;k++){
				sum = sum + matrix1[i][k] * matrix2[k][j];
			}
			hsl[i][j] = sum;
			sum = 0;
		}
	}
	
	for(i = 0; i < r1; i++){
		for (j = 0; j< c2; j++){
			*value = hsl[i][j];
			sleep(1);
			printf("%d ", hsl[i][j]);
		}
		printf("\n");
	}
	
	shmdt(value);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}
```

Penjelasan
```
key_t key = 1234;
    int *value;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);
```
syntax diatas digunakan untuk shared memory

```
int matrix1[4][2];
	int matrix2[2][5];
	int hsl[10][10];
	int sum,i,j,k;
	int r1=4;
	int c1=2;
	int r2=2;
	int c2=5;
	
	matrix1[0][0]=1;
	matrix1[0][1]=2;
	matrix1[1][0]=2;
	matrix1[1][1]=2;
	matrix1[2][0]=1;
	matrix1[2][1]=2;
	matrix1[3][0]=1;
	matrix1[3][1]=1;
	
	matrix2[0][0]=2;
	matrix2[0][1]=2;
	matrix2[0][2]=2;
	matrix2[0][3]=1;
	matrix2[0][4]=1;
	matrix2[1][0]=2;
	matrix2[1][1]=1;
	matrix2[1][2]=2;
	matrix2[1][3]=1;
	matrix2[1][4]=2;
```
inisialisasi variable dan matriks

```
for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<c1;k++){
				sum = sum + matrix1[i][k] * matrix2[k][j];
			}
			hsl[i][j] = sum;
			sum = 0;
		}
	}
```
looping untuk menghitung perkalian matriks

```
for(i = 0; i < r1; i++){
		for (j = 0; j< c2; j++){
			*value = hsl[i][j];
			sleep(1);
			printf("%d ", hsl[i][j]);
		}
		printf("\n");
	}
```
looping untuk menaruh data ke shared memory dan untuk print hasil perklaian matriks ke layar

```
for(i=0; i<20; i++){
        pthread_join(tid[i], NULL);
    }
    
    shmdt(value);
  	shmctl(shmid, IPC_RMID, NULL);
}
```
untuk join thread dan shared memory

### 4b
```
#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void *thread(int temp) {

    int i, fact = 0;
    for (i=temp; i>0; i--) {
        fact += i;
    }
    printf("%d", fact);
}

int main (int argc, char* argv[]) {
    
    key_t key = 1234;
  	int *value;
  	int hasil[20];
	int i;
  	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
  	value = shmat(shmid, NULL, 0);
  	int temp;
    
    pthread_t tid[20];
 
    for(i=0; i<20; i++){
    	hasil[i]=*value;
    	temp=hasil[i];
    	//printf("ini temp %d\n", temp);
        pthread_create(&(tid[i]), NULL, &thread, (void*)temp);
        sleep(1);
        if(i%5==4 && i>0){
            printf("\n");
        }
        else{
            printf("\t");
        }
    }
    
    for(i=0; i<20; i++){
        pthread_join(tid[i], NULL);
    }
    
    shmdt(value);
  	shmctl(shmid, IPC_RMID, NULL);
}
```

Penjelasan
```
void *thread(int temp) {

    int i, fact = 0;
    for (i=temp; i>0; i--) {
        fact += i;
    }
    printf("%d", fact);
}
```
fungsi diatas untuk menghitung plus faktorial

```
key_t key = 1234;
  	int *value;
  	int hasil[20];
	int i;
  	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
  	value = shmat(shmid, NULL, 0);
  	int temp;
```
inisialisasi variabel dan shared memory

```
for(i=0; i<20; i++){
    	hasil[i]=*value;
    	temp=hasil[i];
    	//printf("ini temp %d\n", temp);
        pthread_create(&(tid[i]), NULL, &thread, (void*)temp);
        sleep(1);
        if(i%5==4 && i>0){
            printf("\n");
        }
        else{
            printf("\t");
        }
    }
    
    for(i=0; i<20; i++){
        pthread_join(tid[i], NULL);
    }
    
    shmdt(value);
  	shmctl(shmid, IPC_RMID, NULL);
}
```
membuat 20 thread untuk menghitung plus faktorial secara paralel, lalu thread dijoin 

### 4c
```
#include <stdio.h> 
#include <unistd.h> 
#define MSGSIZE 16 
  
int main() 
{
    int i; 
	pid_t pp;
	int p[2];
	char* msg1[] = {"ls", "/mnt/c/Users/Windows 10/Documents/INFORMATICS/Sisop/Modul3", NULL};; 
	char* msg2[] = {"wc", "-l", NULL};
    
    if (pipe(p)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
   
    pp = fork(); 
  
    if (pp < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    // Parent process 
    else if (pp > 0) 
    { 
        dup2(p[0], 0);
		close(p[1]);
		execvp("wc", msg2);
    } 
  
    // child process 
    else
    { 
        dup2(p[1], 1);
		close(p[0]);
	  	execvp("ls", msg1); 
    }  
}  
```

Penjelasan
```
int i; 
	pid_t pp;
	int p[2];
	char* msg1[] = {"ls", "/mnt/c/Users/Windows 10/Documents/INFORMATICS/Sisop/Modul3", NULL};; 
	char* msg2[] = {"wc", "-l", NULL};
```
inisialisasi variabel dan pipe

```
if (pipe(p)==-1) 
    { 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
```
kondisi jika pipe tidak berhasil

```
p = fork(); 
  
    if (pp < 0) 
    { 
        fprintf(stderr, "fork Failed" ); 
        return 1; 
    } 
  
    // Parent process 
    else if (pp > 0) 
    { 
        dup2(p[0], 0);
		close(p[1]);
		execvp("wc", msg2);
    } 
  
    // child process 
    else
    { 
        dup2(p[1], 1);
		close(p[0]);]
	  	execvp("ls", msg1); 
    }  
}  
```
pipe difork, lalu parent memproses variabel msg1 dan child memproses variabel msg2
