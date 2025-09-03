#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int comparapilha(pilha *p1, pilha *p2)
{
    int q1, q2;
    q1 = contadorpilha(p1);
    q2 = contadorpilha(p2);

    if (q1 == q2)
    {
        return 0;
    }
    if (q1 > q2)
    {
        return 1;
    }
    if (q1 < q2)
    {
        return 2;
    }
}

int main()
{
    int v;

    pilha *pilha1 = criapilha(), *pilha2 = criapilha();
    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);

    push(pilha2, 4);
    push(pilha2, 5);
    push(pilha2, 6);
    push(pilha2, 7);
    push(pilha2, 8);

    v = comparapilha(pilha1, pilha2);

    if(v == 0)
    {
        printf("as pilhas sao iguais");
    }
    if(v == 1)
    {
        printf("a pilha 1 e maior");
    }
    else
    {
        printf("a pilha 2 e maior");
    }
}
