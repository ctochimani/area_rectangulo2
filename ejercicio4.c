#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n) 
{
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int main() 
{
    int status_D, status_E, status_F;
    float retorno_D, retorno_E, retorno_F, resultado;
    resultado = 0;
    
    pid_t pid_D, pid_E, pid_F;

    pid_D = fork();
    
    if (pid_D == 0) 
    {
        retorno_D = 2;
        exit(retorno_D);	
    }

    pid_E = fork();
    
    if (pid_E == 0) 
    {
        retorno_E = 13;
        exit(retorno_E);
    }

    pid_F = fork();
    
    if (pid_F == 0) 
    {
        retorno_F = 14;
        exit(retorno_F);
    }

    waitpid(pid_D, &status_D, 0);
    waitpid(pid_F, &status_F, 0);	
    waitpid(pid_E, &status_E, 0);

    if (WIFEXITED(status_D)) {
        retorno_D = WEXITSTATUS(status_D);
        resultado = (retorno_D * 2) -1;
    }
    if (WIFEXITED(status_F)) 
    {
        retorno_F = WEXITSTATUS(status_F);
        resultado = resultado + retorno_F/100;
    }
    if (WIFEXITED(status_E)) 
    {
        retorno_E = WEXITSTATUS(status_E);
        resultado = resultado + (retorno_E + 3)/10000;
    }

    printf("El resultado es: %.4f\n", resultado);

    return 0;
}
