#include <stdio.h>

int main(void) {
  float arr[5] = {1, 2.4, 3.5, 4.5, 5.9};
  int fd;
  int n;
 
  fd = creat("datos.txt", 777);
  
  for (int i = 0; i < 5; i++) 
  {
    n = write(fd, arr, sizeof(arr));
  }

  close(fd);

  printf("Se escribió el arreglo en el archivo datos.txt.\n");
  
  return 0;
}