#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int compara(pilha *p1, pilha *p2)
{
    int q1, q2;
    q1 = contador(p1);
    q2 = contador(p2);

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

    pilha *pilha1 = cria(), *pilha2 = cria();
    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);

    push(pilha2, 4);
    push(pilha2, 5);
    push(pilha2, 6);
    push(pilha2, 7);
    push(pilha2, 8);

    v = compara(pilha1, pilha2);

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
