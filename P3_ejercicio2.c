#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int buffer = 0;

void* threadB( void *args )
{
	while (1)
	{
		if (buffer != 0)
		{
			exit(0);
		}
		if (buffer > 0)
		{
			printf("El cuadraro es: %d\n", buffer*buffer);
			buffer = 0;
		}
	}
}


int main()
{
	pthread_t thread_B;
	int stateB;
	 
	while(buffer == 0)
	{
		printf("Ingrese un número: ");
		scanf("%d", &buffer);
	}
    	
    	stateB = pthread_create( &thread_B, NULL, threadB, NULL );
    	pthread_join( thread_B, NULL );

    	exit(0);
}


