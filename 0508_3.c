/*O quadrado de um n�mero natural N � dado pela soma dos N
primeiros n�meros �mpares consecutivos.
Elabore um programa que leia um n�mero natural N e calcule o seu quadrado.*/

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
