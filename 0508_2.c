/*Construa um programa que leia v�rios n�meros inteiros
positivos. O programa ser� encerrado quando um n�mero
N�O positivo for digitado e ir� calcular:
� A quantidade de n�meros lidos
� A soma dos n�meros que s�o m�ltiplos de 3 maiores que
10
� A quantidade de m�ltiplos de 3
� O percentual de m�ltiplos de 7*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, qt=0, soma=0, qt3=0, qt7=0;
    float per;

    do
    {
        printf("\nnumero: ");
        scanf("%d", &num);
        qt++;
        if (num > 10)
        {
            if (num%3 == 0)
            {
                soma+=num;
            }
        }

        if (num%3 == 0)
        {
            qt3++;
        }

        if (num%7 == 0)
        {
            qt7++;
            per = (qt7*100)/(float)qt;
        }
    } while (num > 0);
    {
        qt--;
        printf("\nQuantidade de numeros lidos: %d", qt);
        printf("\nSoma dos multiplos de 3 maiores que 10: %d", soma);
        printf("\nQuantidade de multiplos de 3: %d", qt3);
        printf("\nPercentual de multiplos de 7: %.3f", per);
    }
}
