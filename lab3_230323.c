#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t pid_A, pid_C;

void sigalrm_handler(int signum) 
{
    printf("Alarma recibida\n");
    kill(pid_A, SIGUSR1);
}

void signal_handler(int signum) 
{
	if( signum == SIGUSR1 )
	{
    		printf("Señal SIGUSR1 recibida, ID: %d, ID Padre: %d\n", getpid(), getppid());
    	}
	if( signum == SIGUSR2 )
	{
    		printf("Señal SIGUSR2 recibida, ID: %d, ID Padre: %d\n", getpid(), getppid());
    		exit(1);
    	}
}

int main(void) 
{
    signal(SIGALRM, sigalrm_handler);

    pid_A = fork();
    
    if (pid_A == 0) 
    { 
        signal(SIGUSR1, signal_handler);

        pid_C = fork();
        
        if (pid_C == 0) {
         
            signal(SIGUSR2, signal_handler);
            while (1) {} 
        } else 
        { 
            pause(); 
            printf("Proceso A recibió señal SIGUSR1\n");
            kill(pid_C, SIGUSR2);
            wait(NULL); 
        }
    } else 
    { 
        alarm(3);

        pause(); 

        waitpid(pid_A, NULL, 0); 
        waitpid(pid_C, NULL, 0); 

        printf("Mis hijos han terminado\n");
    }

    return 0;
}


