#include <stdio.h>

int main(void) {
  float arr[5];
  int fd;
  int n, valor;
 
  fd = creat("datos2.txt", 777);
  
  for (int i = 0; i < 5; i++) 
  {
    printf("n = ");
    scanf("%d", &valor);
    n = write(fd, &valor, sizeof(arr));
  }

  close(fd);

  printf("Se escribió el arreglo en el archivo datos2.txt.\n");
  
  return 0;
}