/*Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.*/

#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        return v[n-1]+soma(v, n-1);
    }
}
int main ()
{
    int v[5], i;
    printf("preencha o vetor de 5 variaveis: ");
    for (i=0; i<5; i++)
    {
        scanf("%d", &v[i]);
    }
    soma(v, 5);
    printf("soma: %d", soma(v, 5));
    return 0;
}
