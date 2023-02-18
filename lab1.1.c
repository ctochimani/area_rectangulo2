#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int c_error(int fd, int n, int m)
{
  fd = open("archivo.txt", 1);

  if (n<0)
  {
    if(errno == EACCES)
    {
      printf("Error: Problema con los permisos del archivo\n");
      return -1;
    }
    else if (errno == EAGAIN)
    {
      printf("Error: Archivo bloqueado\n");
      return -1;
    }
    else if(errno == EBADF)
    {
      printf("Error: Mal descriptor de archivo");
      return -1;
    }
    else
    {
      printf("Error desconocido \n");
      return -1;
    }
  }
  else
  {
    printf("Archivo abierto exitosamente\n");
    fclose(fd);
  }
  return 0;
}

int main(int argc, char *argv[]) 
{
  int fd, n, m;
  float value = 47;

  fd = creat("archivo.txt", 777);

  n = write(fd, &value, sizeof(value));
  m = read(fd, &value, sizeof(value));

  printf("%d\n", n);

 c_error(fd, n, m);
 
  return 0;
}