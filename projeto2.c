#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "p2.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    int num;

    do{
        printf("\n\t\tMENU\n");
        printf("--------------------------------------------------------\n");
        printf(" 1| Inserir uma nova venda.\n");
        printf(" 2| Listar todas as vendas.\n");
        printf(" 3| Buscar as vendas de um determinado vendedor.\n");
        printf(" 4| Listar vendas acima ou abaixo de um valor definido.\n");
        printf(" 5| Exibir estatísticas.\n");
        printf(" 6| Remoção de uma venda.\n");
        printf(" 7| Finalizar o sistema.\n");
        printf("--------------------------------------------------------\n");
        printf("  | Digite sua opção");
        scanf("%d", &num);
    } while (num<1 || num>7);





}
