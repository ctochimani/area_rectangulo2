#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


int found_flag = 0;
int num = 5;

void* thread01( void *args )
{
	int parte_1[4] = {1, 2, 3, 4};
	
	for (int i = 0; i <= 4; i++)
	{
		if (parte_1[i] == num)
		{
			found_flag = 1;
		}
	}
	pthread_exit( NULL );
}

void* thread02( void *args )
{
	int parte_2[4] = {5, 6, 7, 8};
	for (int i = 0; i <= 4; i++)
	{
		if (parte_2[i] == num)
		{
			found_flag = 1;
		}
	}
	pthread_exit( NULL );
}

void* thread03( void *args )
{
	int parte_3[4] = {9, 10, 11, 12};
	for (int i = 0; i <= 4; i++)
	{
		if (parte_3[i] == num)
		{
			found_flag = 1;
		}
	}
	pthread_exit( NULL );
}

int main()
{
	pthread_t thread_1, thread_2, thread_3;
	int state1, state2, state3; 
	double result;
	
	state1 = pthread_create( &thread_1, NULL, thread01, NULL );
	state2 = pthread_create( &thread_2, NULL,thread02, NULL );
    	state3 = pthread_create( &thread_3, NULL, thread03, NULL );
    
    	pthread_join( thread_1, NULL );
    	pthread_join( thread_2, NULL );
    	pthread_join( thread_3, NULL );
    
    	if (found_flag == 1)
    	{
    		printf("El número %d fue encontrado\n", num);
    	}
    	else
    	{
    		printf("El número %d no fue encontrado\n", num);
    	}
    	exit(0);
}


