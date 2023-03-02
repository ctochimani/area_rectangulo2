#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	pid_t pid_A;
	int status;
	pid_A = fork();
	// Child process
	if( pid_A == 0 )
	{
		execl("/home/cecilia/Documents/write", " ", NULL);
		perror("excecl ha fallado.");
		return 0;
	}
	//Father process
	else
	{
		execl("/home/cecilia/Documents/read", " ", NULL);
		perror("excecl ha fallado.");
	}
	return 0;
}
