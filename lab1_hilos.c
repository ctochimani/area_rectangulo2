#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

double part1, part2, part3;

void* thread01( void *args )
{
	part1=1*2*3;
	pthread_exit( NULL );
}

void* thread02( void *args )
{
	part2=4*5*6;
	pthread_exit( NULL );
}

void* thread03( void *args )
{
	part3=7*8*9;
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
    
    	result=part1*part2*part3;
    	printf("El factorial 9! es: %f \n", result);
    	exit(0);
}


