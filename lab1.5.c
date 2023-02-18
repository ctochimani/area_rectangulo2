#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  float arr[3];
  int m;

  int fd = open("datos2.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

  m = read(fd, arr, sizeof(arr));


  close(fd);

  printf("Los valores en el archivo son:\n");
  for (int i = 0; i < 3; i++) {
    printf("%f\n", arr[i]);
  }

  return 0;
}