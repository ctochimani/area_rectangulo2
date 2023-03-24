#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler_a(int signum)
{
	printf("\nAlarma recibida\n");
	exit(1);
}
int main() 
{
    signal(SIGALRM, signal_handler_a);
    int status;
    
    pid_t pid_B, pid_C;
    
    pid_B = fork();
   
    if( pid_B == 0 )
    {
    
    	sleep(1);
    	
    	pid_C = fork();
    	if( pid_C == 0 )
    	{
        	while(1) 
        	printf("Esperando una senal\n");
        	sleep(1);
        	return 0;
    	}
    	if( pid_C > 0 )
    	{
    		sleep(1);
    		kill(pid_C, SIGKILL);
    		pause();
    		return 0;
    	}
    }
    if( pid_B > 0 )
    {
    	alarm(5);
        waitpid(pid_B, &status, 0);
        return 0;
    }
}
