#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha* pilha1;
    pilha1 = cria();

    int op, num;
    char r;

    do
    {
        printf("\n\n---- MENU -----\n");
        printf("| 1. inserir  |\n"); //ok
        printf("| 2. remover  |\n"); //ok
        printf("| 3. imprimir |\n"); //ok
        printf("| 4. liberar  |\n"); //ok
        printf("---------------\n");
        printf("Escolha uma acao do menu: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            do
            {
                printf("valor a ser inserido: ");
                scanf("%d", &num);
                push(pilha1, num);
                printf("inserir outro valor? [s/n]: ");
                scanf(" %c", &r);
            }while (r == 's' || r == 'S');
        break;
        case 2:
            num = pop(pilha1);
            printf("valor removido: %d", num);
        break;
        case 3:
            imprime(pilha1);
        break;
        }
    }while(op != 4);
}
