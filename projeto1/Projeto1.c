#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca_projeto1.h"
#include <ctype.h>
#include<time.h>
#include <unistd.h>
#include <conio.h>

void limpa()
{
    fflush(stdin);
    getchar();
    system("cls");
}

int main ()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    Fila* emerg;
    Fila* normal;
    Fila* atendidos;
    Fila* geral;
    Dados A;
    emerg = CriaFila();
    normal = CriaFila();
    atendidos = CriaFila();
    geral = CriaFila();
    int num, id, idade, prior, dia, mes, ano, busca_resul,b, buscado1;
    char nome[50], buscado[50];
    char especie[30];

            printf("\n");
            printf("\t\t       /^ ^\\\n");
            printf("\t\t      / 0 0 \\\n");
            printf("\t\t      V\\ Y /V\n");
            printf("\t\t       / - \\\n");
            printf("\t\t      /     \\\n");
            printf("\t\t     V__) (__V\n");

    do {
            do {
                printf("\n-----------------------------------------------------\n");
                printf("\t\t\tMENU\n");
                printf("-----------------------------------------------------\n\n");
                printf("1. Insira um pet na fila de atendimento.\n\n");
                printf("2. Atender um pet.\n\n");
                printf("3. Buscar um pet.\n\n");
                printf("4. Imprimir relatorio dos pets na fila.\n\n");
                printf("5. Imprimir proximo pet a ser atendido. \n\n");
                printf("6. Imprimir todos os pets que ja foram atendidos. \n\n");
                printf("7. Finalizar o sistema. \n\n");
                printf("-----------------------------------------------------\n\n");
                printf("Insira sua opcao: ");
                scanf("%d", &num);
                limpa();
                } while (num<1 || num>7);

        switch (num) {
            case 1:
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");


                A.id = gera();
                printf("\nID do pet: %d", A.id);

                printf("\n\nNome do pet: ");
                scanf("%s", A.nome);

                printf("\nIdade do pet: ");
                scanf("%d", &A.idade);

                printf("\nEspecie do pet: ");
                scanf("%s", A.especie);

                printf("\nData de nascimento: ");
                printf("\n Dia: ");
                scanf("%d", &A.aniv.dia);
                while (A.aniv.dia < 1 || A.aniv.dia > 31)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.aniv.dia);
                }
                printf(" Mes: ");
                scanf("%d", &A.aniv.mes);
                while (A.aniv.mes < 1 || A.aniv.mes > 12)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.aniv.mes);
                }
                printf(" Ano: ");
                scanf("%d", &A.aniv.ano);
                while (A.aniv.ano > 2025)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.aniv.ano);
                }

                printf("\nPrioridade do pet [0: Emergencia | 1: Normal]: ");
                scanf("%d", &A.prior);

                if (A.prior==0)
                {
                    insere_pet(emerg, A);
                }
                else
                {
                    insere_pet(normal, A);
                }
                insere_pet(geral, A);
                limpa();
                break;

            case 2:
                if (vaziaFila(emerg)==1 && vaziaFila(normal)==1)
                {
                    printf("\nNao ha pets para serem atendidos.\n");
                }
                else if (vaziaFila(emerg)== 0)
                {
                    atende(emerg, atendidos, geral);
                    printf("\n------------------------------------------------------");
                    printf("\n\t\tPet Atendido (Emergencia)\n");
                }
                else
                {
                    atende(normal, atendidos, geral);
                    printf("\n------------------------------------------------------");
                    printf("\n\t\tPet Atendido (Normal)\n");
                }
                limpa();
                break;

            case 3:
                do
                {
                printf("\nComo deseja buscar? [1: ID | 2: Nome]: ");
                    scanf("%d", &b);
                        if(b==1)
                        {
                            printf(" ID do animal que deseja buscar: ");
                            scanf("%d", &buscado1);
                            busca_resul = buscaid(geral, buscado1);
                        }
                        else if(b==2)
                        {
                            printf(" Nome do animal que deseja buscar: ");
                            scanf("%s", buscado);
                            busca_resul = buscanome(geral, buscado);
                        }
                        else
                        {
                            printf("Opcao invalida, digite novamente: ");
                        }
                } while(b<1 || b>2);

                if (busca_resul == 0)
                {
                    printf("\nO animal procurado nao esta cadastrado.");
                }
                fflush(stdin);
                getchar();
                limpa();
                break;

            case 4:
                printf("Relatorio dos pets");
                printf("\n------------------------------------------------------");

                if(vaziaFila(emerg)==1)
                {
                    printf("\nNao ha pets na fila de emergencia ;)");
                }
                else
                {
                    imprime(emerg);
                }
                printf("\n");
                if(vaziaFila(normal)==1)
                {
                    printf("\nNao ha pets na fila normal ;)");
                }
                else
                {
                    imprime(normal);
                }
                limpa();
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
                limpa();
                break;
            case 6:
                if (vaziaFila(atendidos)==1)
                {
                    printf("Nenhum pet foi atendido.");
                }
                else
                {
                    imprime(atendidos);
                }
                limpa();
                break;

        }
    } while (num!=7);
    return 0;
}
