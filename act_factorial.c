#include<stdio.h>

//Cecilia Soriano Tochimani ID 173633
//Programa que realiza la función factorial de un número

//función que calcula el factorial
int factorial(int n){
    int x,f=1;
    for(x=1;x<=n;x++)
    	f=f*x;
    return f;
}

int main(){
    int resultado,n;
    printf("Inserte un número: ");
    scanf("%d",&n);
    
    resultado = factorial(n);
    
    printf("El factorial de %d es %d",n,resultado);
    return 0;

}