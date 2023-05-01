#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define NO_ITEMS 10
int buffer = 0;
int board1[10][10];
int board2[10][10];
int count1 = 5;
int count2 = 5;

pthread_mutex_t mutex;
pthread_cond_t cond_consumer, cond_producer;

//print board1 player_1
void print_board1() 
{
  printf("\nBOARD PLAYER 1\n");
  printf("    ");
  for (int i = 0; i < 10; i++) 
  {
      printf("%3d ", i+1);
  }
  printf("\n");
  for (int i = 0; i < 10; i++) 
  {
      printf("%3d ", i+1);
      for (int j = 0; j < 10; j++) 
      {
          printf("%3d ", board1[i][j]);
      }
      printf("\n");
  }
}

//print board2 player_2
void print_board2()
{
  printf("\nBOARD PLAYER 2\n");
  printf("    ");
  for (int i = 0; i < 10; i++) 
  {
      printf("%3d ", i+1);
  }
  printf("\n");
  for (int i = 0; i < 10; i++) 
  {
      printf("%3d ", i+1);
      for (int j = 0; j < 10; j++) 
      {
          printf("%3d ", board2[i][j]);
      }
      printf("\n");
  }
}

//ships from player_1
void ships_1()
{
  int x, y;
  printf("\nPLAYER 1\n");
  for (int i = 0; i <5; i++) 
  {
    printf("\nEnter the position of the ship #%d: ", i+1);
    scanf("%d %d", &x, &y);
    board1[x-1][y-1] = 1;
  }
}

//ships from player_2
void ships_2()
{
  int x, y;
  printf("\nPLAYER 2\n");
  for (int i = 0; i <5; i++) 
  {
    printf("\nEnter the position of the ship #%d: ", i+1);
    scanf("%d %d", &x, &y);
    board2[x-1][y-1] = 1;
  }
}

//check the attack from player1
void check_1()
{
  int x, y;
  printf("\nPLAYER 1\n");
  printf("\nEnter the position to attack: ");
  scanf("%d %d", &x, &y);
  if (board2[x-1][y-1] == 1)
  {
    board2[x-1][y-1] = 0;
    board1[x-1][y-1] = 20;
    printf("\nATTACK\n");
    count2--;
  }
  else
  {
    board1[x-1][y-1] = 10;
    printf("\nWATER\n");
  }
  if(count2 == 0 )
  {
    pthread_kill( pthread_self(), SIGUSR1 );
  }
}

//check the attack from player_2
void check_2()
{
  int x, y;
  printf("\nPLAYER 2\n");
  printf("\nEnter the position to attack: ");
  scanf("%d %d", &x, &y);
  if (board1[x-1][y-1] == 1)
  {
    board1[x-1][y-1] = 0;
    board2[x-1][y-1] = 20;
    printf("\nATTACK\n");
    count1--;
  }
  else
  {
    board2[x-1][y-1] = 10;
    printf("\nWATER\n");
  }
  if(count1 == 0 )
  {
    pthread_kill( pthread_self(), SIGUSR2 );
  }
}

//producer = player1
void* producer(void* arg)
{
  for ( int i=0; i<NO_ITEMS; i++ ) 
  {
    pthread_mutex_lock( &mutex );
    while( buffer != 0 ) // wait until the buffer is free
    {
      // free the mutex and wait the signal 
      pthread_cond_wait( &cond_producer, &mutex );
    }
    buffer = 1;
    printf("\n\n");
    print_board1();
    check_1();
    print_board1();
    printf("\n \n");
    
    // elements in the buffer
    pthread_cond_signal( &cond_consumer );
    pthread_mutex_unlock( &mutex );
  }
  // send the signal that is over 
  pthread_kill( pthread_self(), SIGUSR1 );

  pthread_exit( NULL );
}

//consumer = player_2
void* consumer(void* arg)
{
  for ( int i=0; i<NO_ITEMS; i++ ) 
  {
    pthread_mutex_lock( &mutex );
    // ---------- Región crítica
    while (buffer == 0) // wait until te buffer has info
    {
      // free the mutex and wait the signal
      pthread_cond_wait( &cond_consumer, &mutex );
    }
    printf("\n\n");
    printf("\n\n");
    print_board2();
    check_2();
    print_board2();
  
    buffer = 0;
    
    // clean buffer
    pthread_cond_signal( &cond_producer ); 
    pthread_mutex_unlock( &mutex );
  }

  // send signal that is over 
  pthread_kill( pthread_self(), SIGUSR2 );

  pthread_exit(NULL);
}

void signal_handler(int signum)
{
  if (signum == SIGUSR1) 
  {
    printf("WINNER\n");
    printf("CONGRATULATIONS PLAYER 1\n");
    exit(0);
  }
  else if (signum == SIGUSR2)
  {
    printf("WINNER\n");
    printf("CONGRATULATIONS PLAYER 2\n");
    exit(0);
  }
}

int main()
{
  pthread_t thread_1, thread_2;

  printf("\nWELCOME TO BATTLESHIP\n");
  printf("\nINSTRUCTIONS\n");
  printf("\n1. BOTH PLAYERS WILL CHOOSE THE POSITIONS OF THEIR SHIPS. ALL THE SHIPS ARE FROM THE SAME SIZE (1)\n");
  printf("\n2. EACH PLAYER WILL HAVE 10 ATTEMPTS TO SHOOT DOWN THE OTHER'S SHIPS\n");
  printf("\n1 = ship\n");
  printf("\n20 = attack\n");
  printf("\n0 = downed ship\n");
  printf("\n10 = water\n");

  print_board1();
  ships_1();
  print_board2();
  ships_2();
  
  signal(SIGUSR2, signal_handler);
  signal(SIGUSR1, signal_handler);
  
  pthread_mutex_init( &mutex, 0 );
  pthread_cond_init( &cond_consumer, 0 );
  pthread_cond_init( &cond_producer, 0 );
  
  // create the threads
  pthread_create( &thread_1, NULL, producer, NULL );
  pthread_create( &thread_2, NULL, consumer, NULL );
  
  // wait the threads
  pthread_join( thread_1, NULL);
  pthread_join( thread_2, NULL);

  pthread_mutex_destroy( &mutex );
  pthread_cond_destroy( &cond_consumer );
  pthread_cond_destroy( &cond_producer );
  

  return 0;
}
