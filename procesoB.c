#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main (void)
{
	srand(time(NULL));
	int A[1000] = {0};
	int fd, n;
	fd = creat("enteros.txt", 777);
	
	for (int i = 0; i < 1000; i++)
	{
		A[i] = rand() % 101;
	}
	n = write(fd, A, sizeof(A));
	close(fd);
	return 3;
}
