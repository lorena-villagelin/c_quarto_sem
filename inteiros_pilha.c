//ler inteiro e transformar em pilha, depois imprimir o numero como inteiro novamente

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha *intpilha(int n)
{
    pilha *p = cria();
    for (;n!=0;n=n/10)
    {
        push(p, n%10);
    }
    return p;
}

int inteiro(pilha *p)
{
    pilha *pilha2 = inverte(p);
    no *aux = pilha2 -> topo;
    int v=0, i=1, num=0;
    for(;aux!=NULL;i*=10)
    {
        num=aux->info*i;
        v+=num;
        aux=aux->prox;
    }
    return v;
}


int main()
{
    pilha *pilha1 = cria();
    int num;
    printf("digite um inteiro: ");
    scanf("%d", &num);
    pilha1 = intpilha(num);
    imprime(pilha1);
    num=inteiro(pilha1);
    printf("\n%d", num);
}
