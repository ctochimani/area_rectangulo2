#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main (void) 
{
	pid_t pid_B, pid_C;
	int status, m, fd, A[1000];
	
	pid_B = fork();
	
	if (pid_B == 0)
	{
		printf("ID Proceso B: %d. ID padre: %d\n", getpid(), getppid());
		execl("procesoB", "", NULL);
		return 3;
	}
	
	pid_C = fork();
		
	if (pid_C == 0)
	{
		sleep(3);
		printf("ID Proceso C: %d. ID padre: %d\n", getpid(), getppid());
	}
	
	else if (pid_C > 0)
	{
		fd = open("enteros.txt", 0);
		m = read(fd, A, sizeof(A));
		waitpid(pid_B, &status, 0);
		
		if (WIFEXITED(status) != 0)
		{
			printf("Valor de retorno de B: %d\n", WEXITSTATUS(status));
		}
		fd = open("enteros.txt", 0);
		m = read(fd, A, sizeof(A));
		
		for (int i = 0; i < 1000; i++)
		{
			printf("%d: %d \n",i, A[i]);
		}
		}
		
	return 0;
}
