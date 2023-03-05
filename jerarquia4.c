#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid_R;
    pid_t pid_W;
    pid_t pid_T;
    pid_t pid_V;
    pid_t pid_L;
    pid_t pid_S;
    pid_t pid_P;
    
    pid_R = getpid();
    printf("ID de proceso R: %d\n", pid_R);
    
    pid_W = fork();
    if (pid_W == 0) 
    {
        printf("ID de Proceso W: %d, ID padre: %d\n", getpid(), pid_R);
        
        pid_L = fork();
        if (pid_L == 0) 
        {
            printf("ID de proceso L: %d, ID padre: %d\n", getpid(), pid_W);
            
            pid_P = fork();
            if (pid_P == 0) 
            {
                printf("ID de proceso P: %d, ID padre: %d\n", getpid(), pid_L);
            }
        } else 
        {
            pid_S = fork();
            if (pid_S == 0) 
            {
                // proceso hijo S
                printf("ID de proceso S: %d, ID padre: %d\n", getpid(), pid_W);
            }
        }
    } else {
        pid_T = fork();
        if (pid_T == 0) 
        {
            // proceso hijo T
            printf("ID de proceso T: %d, ID padre: %d\n", getpid(), pid_R);
            
            pid_V = fork();
            if (pid_V == 0) 
            {
                printf("ID de proceso V: %d, ID padre: %d\n", getpid(), pid_T);
            }
        }
    }
    return 0;
}

