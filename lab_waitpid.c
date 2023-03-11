#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	pid_t pid_L, pid_D;
	int status;
	
	pid_L = fork();
	
// Child process
	if( pid_L == 0 )
	{
		sleep(3);
		printf("Terminé mi ejecución con ID %d ID de mi padre %d \n",pid_L, getppid());
		return 10;
	}
	else
	{
		pid_D = fork();
		
		if( pid_D == 0 )
		{
			sleep(1);
			printf("Terminé mi ejecución con ID %d ID de mi padre %d \n",pid_D, getppid());
			return 3;
		}
		
	}
	if( pid_L > 0 && pid_D > 0)
	{
		printf("Uno de mis hijos ha termiando su ejecución \n ");
		waitpid(pid_L, &status, 0);
		waitpid(pid_D, &status, 0);
		
	
	}

	return 0;
}
