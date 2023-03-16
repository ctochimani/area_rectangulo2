#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    int status_D, status_E, status_F;
    float return_D, return_E, return_F, res;
    res = 0;
    
    pid_t pid_D, pid_E, pid_F;
SS
    pid_D = fork();
    
    if (pid_D == 0) 
    {
        return_D = 2;
        exit(return_D);	
    }

    pid_E = fork();
    
    if (pid_E == 0) 
    {
        return_E = 13;
        exit(return_E);
    }

    pid_F = fork();
    
    if (pid_F == 0) 
    {
        return_F = 14;
        exit(return_F);
    }

    waitpid(pid_D, &status_D, 0);
    waitpid(pid_F, &status_F, 0);	
    waitpid(pid_E, &status_E, 0);

    if (WIFEXITED(status_D)) {
        return_D = WEXITSTATUS(status_D);
        res = (return_D * 2) -1;
    }
    if (WIFEXITED(status_F)) 
    {
        return_F = WEXITSTATUS(status_F);
        res = res + return_F/100;
    }
    if (WIFEXITED(status_E)) 
    {
        return_E = WEXITSTATUS(status_E);
        res = res + (return_E + 3)/10000;
    }

    printf("El resultado es: %.4f\n", res);

    return 0;
}
