#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "biblioteca_projeto1.h"

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    Fila* emerg;
    Fila* normal;
    Fila* atendidos;
    Fila* geral;
    emerg = CriaFila();
    normal = CriaFila();
    atendidos = CriaFila();
    geral = CriaFila();
    int num, id, idade, prior, dia, mes, ano, busca_resul;
    char nome[50], buscado[50];
    char especie[30];

    do {
        do {
            printf("-----------------------------------------------------\n");
            printf("\t\t\tMENU\n");
            printf("-----------------------------------------------------\n\n");
            printf("1. Insira um pet na fila de atendimento.\n\n");
            printf("2. Atender um pet.\n\n");
            printf("3. Buscar um pet.\n\n");
            printf("4. Imprimir relatório dos pets na fila.\n\n");
            printf("5. Imprimir próximo pet a ser atendido. \n\n");
            printf("6. Imprimir todos os pets que já foram atendidos. \n\n");
            printf("7. Finalizar o sistema. \n\n");
            printf("-----------------------------------------------------\n\n");
            printf("Insira sua opção: ");
            scanf("%d", &num);
            system("cls");
        } while (num<1 || num>7);
        switch (num) {
            case 1:
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");
                printf("\nNome do pet: ");
                scanf("%s", nome);

                //printf("\nID do pet: ");
                // scanf("%d", &id);


                printf("\nIdade do pet: ");
                scanf("%d", &idade);
                while (idade < 0 || idade > 25)
                {
                    printf("Valor invalido, digite novamente: ");
                    scanf("%d", &idade);
                }

                printf("\nEspécie do pet: ");
                scanf("%s", especie);

                printf("\nData de nascimento: ");
                printf("\n Dia: ");
                scanf("%d", &dia);
                while (dia < 1 || dia > 31)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &dia);
                }
                printf(" Mês: ");
                scanf("%d", &mes);
                while (mes < 1 || mes > 12)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &mes);
                }

                printf(" Ano: ");
                scanf("%d", &ano);
                while (ano < 2000 || ano > 2025)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &ano);
                }

                printf("\nPrioridade do pet [0: Emergência | 1: Normal]: ");
                scanf("%d", &prior);

                if (prior==0)
                {
                    insere_pet(emerg, nome, idade, especie, prior, dia, mes, ano);
                }
                else
                {
                    insere_pet(normal, nome, idade, especie, prior, dia, mes, ano);
                }
                    insere_pet(geral, nome, idade, especie, prior, dia, mes, ano);
                system("cls");
                break;

            case 2:
                if (vaziaFila(emerg)==1)
                {
                    atende(normal, atendidos);
                }
                else
                {
                    atende(emerg, atendidos);
                }
                system("cls");
                break;

            case 3:
                printf("\nNome do animal que deseja buscar: ");
                scanf("%s", buscado);
                busca_resul = busca(geral, buscado);
                if (busca_resul == 0)
                {
                    printf("\nO animal procurado não está cadastrado.");
                }
                else
                {
                    busca_resul = busca(atendidos, buscado);
                    if (busca_resul==1)
                    {
                        printf("Já foi atendido");
                    }
                    else
                    {
                        printf("Não foi atendido");
                    }
                }
                system("cls");
                break;

            case 4:
                printf("Emergência: ");
                imprime(emerg);
                printf("\nAtendimento normal: ");
                imprime(normal);
                system("cls");
                break;

            case 5:
                if (vaziaFila(emerg)==1)
                {
                    imprime_prox(normal);
                }
                else
                {
                    imprime_prox(emerg);
                }
                system("cls");
                getchar();
                getchar();
                break;
            case 6:
                 imprime(atendidos);
                 system("cls");
                 break;
        }
    } while (num!=7);
    return 0;
}
