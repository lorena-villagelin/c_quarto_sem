/*Elabore um programa em C que leia um número inteiro e
determine quantos dígitos 7 possui esse número*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, soma=0, resto=0;
    printf("\nDigite um valor inteiro: ");
    scanf("%d", &num);

    while (num > 0)
    {
        resto=num%10;
        num=num/10;
        if (resto == 7)
        {
            soma++;
        }
    }

    printf("\nO numero contem %d numero(s) '7'.", soma);
    return 0;
}
