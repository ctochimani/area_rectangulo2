#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd = open("datos.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    float arr[5];
    int n = sizeof(arr) / sizeof(float);

    if (read(fd, arr, n * sizeof(float)) != n * sizeof(float)) {
        perror("read");
        close(fd);
        exit(1);
    }

    close(fd);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}