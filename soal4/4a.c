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
