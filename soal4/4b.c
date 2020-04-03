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
            printf("\t\t");
        }
    }
    
    for(i=0; i<20; i++){
        pthread_join(tid[i], NULL);
    }
    
    shmdt(value);
  	shmctl(shmid, IPC_RMID, NULL);
}
