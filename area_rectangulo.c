#include <stdio.h>

// Cecilia Soriano Tochimani ID 173633 
//Programa que obtiene el área de un rectángulo

int main(void) 
{
  int area;
  int base;
  int altura;
  
  printf("Introduzca el valor de la altura: ");
  scanf("%d",&altura );
  printf("\nIntroduzca el valor de la base: ");
  scanf("%d", &base);

  area = base * altura;

  printf("\nEl área es de %d ", area);
  return 0;
}