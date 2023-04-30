#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex; 
int count = 0; 

void* hilo(void* arg) 
{
    int i;
    for (i = 0; i < 100; i++) {
        pthread_mutex_lock(&mutex); 
        count++; 
        pthread_mutex_unlock(&mutex); 
    }
    pthread_exit(NULL);
}

int main() 
{
    pthread_t t1, t2, t3, t4, t5;
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  
    pthread_create( &t1, NULL, hilo, NULL );
    pthread_create( &t2, NULL, hilo, NULL );
    pthread_create( &t3, NULL, hilo, NULL );
    pthread_create( &t4, NULL, hilo, NULL );
    pthread_create( &t5, NULL, hilo, NULL );
  
     pthread_join( t1, NULL);
     pthread_join( t2, NULL);
     pthread_join( t3, NULL);
     pthread_join( t4, NULL);
     pthread_join( t5, NULL);
  
    printf("El valor final de count es %d\n", count);

    pthread_mutex_destroy(&mutex); 
    return 0;
}