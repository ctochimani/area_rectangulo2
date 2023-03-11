#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

int generarAleatorio() {
    srand(time(NULL)); 
    return rand() % 101; 
}


int main()
{
	pid_t pid_M, pid_B, pid_A, pid;
	int status, procesos ;
	pid_M = fork();
// Child process
	if( pid_M == 0 )
	{
		printf("ID de proceso M: %d\n", pid_M);
		int aleatorio = generarAleatorio();
    		printf("El número aleatorio es: %d\n", aleatorio);
		return(5);
	}
	pid_B = fork();
	if( pid_B == 0 )
	{
		printf("ID de proceso B: %d\n", pid_B);
		int aleatorio = generarAleatorio();
    		printf("El número aleatorio es: %d\n", aleatorio);
		return(5);
	}
	pid_A = fork();
	if( pid_A == 0 )
	{
		printf("ID de proceso A: %d\n", pid_A);
		int aleatorio = generarAleatorio();
    		printf("El número aleatorio es: %d\n", aleatorio);
		return(5);
	}
// Father
	if( pid > 0 )
	{
		wait(&status);
		printf("Mi hijo terminó de manera normal y su estado es: %d \n\n", WEXITSTATUS(status)); 
		if (WEXITSTATUS(status) == 0)
		{
		procesos = procesos ++;
		}
		
		return (5);
		
	}
	printf("Número de procesos totales: %d \n", procesos);
	return 0;

	}

