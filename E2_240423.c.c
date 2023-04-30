#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int hello_written = 0;

void* hello(void* arg) 
{
    pthread_mutex_lock(&mutex);
    printf("Hola ");
    hello_written = 1;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* world(void* arg) 
{
    while (1) 
    {
        pthread_mutex_lock(&mutex);
        if (hello_written != 0) 
        {
            printf("mundo!\n");
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() 
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, hello, NULL);
    pthread_create(&thread_2, NULL, world, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_mutex_destroy(&mutex); 
    return 0;
}
