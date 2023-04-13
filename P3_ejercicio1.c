#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t pid_Q, pid_V, pid_R, pid_P, pid_M;

void signal_handler(int signum) 
{
	if( signum == SIGUSR1 )
	{
    		printf("Señal SIGUSR1 recibida");
    	}
	if( signum == SIGUSR2 )
	{
    		printf("Señal SIGUSR2 recibida");
    		exit(1);
    	}
}

int main(void) 
{
    signal(SIGALRM, signal_handler);

    pid_V = fork();
    
    if (pid_V == 0) 
    { 
        alarm (8);
        kill(pid_M, SIGUSR1);

        pid_R = fork();
        
        if (pid_R == 0) 
        {
        	while (1)
        	{
        		 printf("ID: %d", getpid());
        	}	
         exit(2);
        }
        
        pid_P = fork();
        if (pid_P == 0) 
        {
        	while(1)
        	{
        		printf("ID: %d", getpid());
        	}
         	exit(2);
        } 
    } 
    
    pid_Q = fork();
    
    if(pid_Q == 0)
    {
     	alarm(8);
     	kill(pid_M, SIGUSR1);
    }
   
    else 
    { 

        pause(); 

        waitpid(pid_Q, NULL, 0); 
        waitpid(pid_V, NULL, 0); 

        printf("Mis hijos han terminado\n");
    }

    return 0;
}


