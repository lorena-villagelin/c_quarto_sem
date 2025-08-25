/*O quadrado de um número natural N é dado pela soma dos N
primeiros números ímpares consecutivos.
Elabore um programa que leia um número natural N e calcule o seu quadrado.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;
    printf("numero: ");
    scanf("%d", &num);

    for(i=1; i<num; i+2)
    {
        i+=i;
        num--;
    }
    printf("\nQuadrado: %d", i);
}
