#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int arr[5] = {0};

void* thread01( void *args )
{
	for (int i = 0; i<=5; i++)
	{
		if (arr[i] != 0)
		{
			printf("Valor distinto de cero: %d\n", arr[i]);
			arr[i] = 0;
		}
		if (i == 5)
		{
			printf("Valor de la última casilla: %d\n", arr[5]);
		}
	}
	pthread_exit( NULL );
}



int main()
{
	pthread_t thread_1;
	int state1;
	int val; 
	
	for (int i = 0; i<=5; i++)
	{
		printf("Ingrese un valor: ");
		scanf("%d",&val);
		arr[i] = val;
	}
	state1 = pthread_create( &thread_1, NULL, thread01, NULL );
    
    	pthread_join( thread_1, NULL );
    	printf("Hemos terminado\n");
    
    	
    	exit(0);
}


