#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum)
{
  printf("El usiario presionó CTRL + C\n");
  sleep(3);
}
 
int main()
{ 
  signal(SIGINT,sig_handler); // Register signal handler
 
  for(int i=1;;i++)
  {
 
    printf("ID: %d \n",getpid());
    sleep(1);  // Delay for 1 second
  }
  return 0;
}

