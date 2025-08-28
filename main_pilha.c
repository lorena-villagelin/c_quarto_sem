#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int removeelemento (pilha *p, int v)
{
    int x;
    no *aux = p -> topo, *anterior = NULL;
    while (aux != NULL)
    {
        if (v == aux -> info)
        {
            anterior -> prox = aux -> prox;
            free(aux);
            return 1;
        }
        anterior = aux;
        aux = aux -> prox;
    }
    return 0;
}

int main()
{
    pilha* pilha1;
    pilha1 = cria();

    int op, num, qt;
    char r;

    do
    {
        printf("\n\n----- MENU -------\n");
        printf("| 1. inserir     |\n\n"); //ok
        printf("| 2. remover     |\n\n"); //ok
        printf("| 3. imprimir    |\n\n"); //ok
        printf("| 4. contar      |\n\n"); //ok
        printf("| 5. inverter    |\n\n");
        printf("| 6. remover     |\n");
        printf("     elemento    \n");
        printf("|    selecionado |\n\n");
        printf("| 7. sair        |\n");//ok
        printf("------------------\n");
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
        case 4:
            qt = contador(pilha1);
            printf("a pilha tem %d elementos", qt);
        break;
        case 5:
            pilha1 = inverte(pilha1);
        break;
        case 6:
            printf("qual valor deseja remover? ");
            scanf("%d", &num);
            if (removeelemento(pilha1, num))
            {
                printf("elemento removido!");
            }
            else
            {
                printf("o elemento nao existe!");
            }

        break;
        }
    }while(op != 7);
    libera(pilha1);
}
