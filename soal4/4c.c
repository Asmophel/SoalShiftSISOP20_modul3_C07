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
