#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int fd2;
	int fd1;
	int array1[]={2,4,6,8,10,12,14,16,18,20};
	int array2[]={1,3,5,7,9,11,13,15,17,19};
	pid_t pid_c;
	pid_t pid_b;
	
	pid_b = fork();
	if(pid_b == 0)
	{
		fd1 = open("datos1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		
		int n1 = write(fd1, &array1, sizeof(array1));
	}
	if (pid_b>0)
	{
		pid_c = fork();
		if (pid_c==0)
		{
			
			fd2 = open("datos2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			
			int n2 = write(fd2, &array2, sizeof(array2));
		}
	}
	
	if (pid_c!=0)
		{
			int resultado;
			for (int i = 0; i<10; i++)
			{
				printf ("\n");
				resultado = array1[i] + array2[i];
				printf("%d  + %d = %d", array1[i], array2[i], resultado);
				printf ("\n");
				
			}
			printf ("\n");
		}
		
		
	
	
	close(fd1);
	close(fd2);
	
	return 0;
}

