#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd = open("datos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		exit (1);
	}
	
	int array[] = {1, 2, 3, 4, 5};
	int n = sizeof (array) / sizeof(int);
	
	if(write(fd, array, n*sizeof(int)) != n*sizeof(int)) 
	{
		perror("write");
		close(fd);
		exit(1);
	}
	close(fd);
	return 0;
}
