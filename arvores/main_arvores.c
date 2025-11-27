#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

void limpa()
{
    fflush(stdin);
    getchar();
    system("cls");
}

int main()
{
    int op, num, v;
    do
    {
        printf("----- MENU ARVORE-----");
        printf("\n1. Criar"); //ok
        printf("\n2. Inserir"); //ok
        printf("\n3. Imprimir"); //ok
        printf("\n4. Buscar"); //ok
        printf("\n5. Remover"); //ok
        printf("\n6. Liberar"); //
        printf("\n7. Encerrar"); //ok
        printf("\n----------------------------");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        limpa();
        switch(op)
        {
            case 1:
                arv *a = cria_arv();
                noA *ra = a->raiz;
                limpa();
                break;
            case 2:
                printf("numero a ser inserido: ");
                scanf("%d", &num);
                insere(a, num);
                limpa();
                break;
            case 3:
                imprimeArv(a);
                limpa();
                break;
            case 4:
                printf("valor para busca: ");
                scanf("%d", &num);
                v = buscaArv(ra, num);
                if(v==1)
                {
                    printf("valor encontrado!");
                }
                else
                {
                    printf("valor nao encontrado");
                }
                limpa();
                break;
            case 5:
                printf("valor para remocao: ");
                scanf("%d", &num);
                a = removerArv(a, num);
                limpa();
                break;
            case 6:
                liberaArv(a);
                a = cria_arv();  // cria uma árvore nova vazia
                ra = a->raiz;
                limpa();
                break;
        }
    }while (op!=7);
    return 0;
}
