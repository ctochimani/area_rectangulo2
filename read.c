#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd = open("datos.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit (1);
	}
	
	int array[5];
	int n = sizeof (array) / sizeof(int);
	
	if(read(fd, array, n*sizeof(int)) != n*sizeof(int)) 
	{
		perror("read");
		close(fd);
		exit(1);
	}
	close(fd);
	for (int i = 0; i<n; i++)
	{
		printf("%d", array[i]);
	}
	printf ("\n");
	return 0;
}
