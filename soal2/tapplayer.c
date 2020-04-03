#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 4444
#define LEN 40
#define MAX 100

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char msg[1024];
    char *pesan1 = "Auth success";
    char *pesan2 = "Auth failed";
    char userr[1024], passs[1024];
    char listname[100][40];
    char listpass[100][40];
    
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
// printf("cb\n");
int count = 0;
while(1){
    char username[LEN];
    char pass[LEN];
    char buffer[1024] = {0};
    int i, a;

    scanf("%s", msg);
    send(sock , msg , sizeof(msg) , 0 );
 
    printf("scan berhasil\n");
    if(strcmp(msg, "login")==0){
        printf("Username : ");
        scanf("%s", username);
        printf("password : ");
        scanf("%s", pass);
    for(i = 0; i< count; i++){
        if (strcmp(listname[i], username) == 0 && strcmp(listpass[i], pass) == 0)
        {
            printf("login success\n");
            send(sock , pesan1 , strlen(pesan1) , 0 );
        }
        else 
        {
            printf("login failed\n");
            send(sock , pesan2 , strlen(pesan2) , 0 );
        }
    }
    }
    else if(strcmp(msg, "register")==0){ 
	printf("username : ");
	scanf("%s", listname[count]);
    sprintf(userr, "%s\n", listname[count]);
    send(sock , userr , sizeof(userr) , 0 );
	printf("password : ");
	scanf("%s", listpass[count]);
    sprintf(passs, "%s\n", listpass[count]);
    send(sock , passs , sizeof(passs) , 0 );
	count++;
    printf("register success\n");
    }
    else printf("input yang anda masukkan salah\n");
}
    return 0;
}
