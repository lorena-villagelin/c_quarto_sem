#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "vendas.h"


void limpa()
{
    fflush(stdin);
    getchar();
    system("cls");
}

int main ()
{
    Arv *a1;
    a1 = CriaArvore();
    Dados A;
    int num, num2, total_vendas, ordem;
    float valor, faturamento;
    char buscado[50];

     do {
            do {
                printf("\n\t\t--------------------------------------------------------------------------------\n");
                printf("\t\t|\t\t\t\tVENDAS                                         |\n");
                printf("\t\t--------------------------------------------------------------------------------\n\n");
                printf("\t\t|\t1. Insira uma nova venda.                                              |\n\n");
                printf("\t\t|\t2. Imprimir todas as vendas.                                           |\n\n");
                printf("\t\t|\t3. Buscar as vendas de um determinado vendedor.                        |\n\n");
                printf("\t\t|\t4. Visualizar as vendas acima ou abaixo de um determinado valor.       |\n\n");
                printf("\t\t|\t5. Visualizar estatisticas das vendas.                                 |\n\n");
                printf("\t\t|\t6. Remover uma venda.                                                  | \n\n");
                printf("\t\t|\t7. Finalizar o sistema.                                                |\n\n");
                printf("\t\t--------------------------------------------------------------------------------\n\n");
                printf("\t\t\tInsira sua opcao: ");
                scanf("%d", &num);

                } while (num<1 || num>7);

        switch (num) {
            //Insira uma nova venda
            case 1:
                printf("-----------------------------------------------------");
                printf("\n\t\tFicha de cadastro\n");
                printf("-----------------------------------------------------");

                A.id = gera();
                printf("\nID da venda: %d", A.id);

                printf("\nNome do vendedor: ");
                scanf("%s", A.numvendedor);
                upper(A.numvendedor);

                srand(time(NULL));

                //char codigo[5]; // 1 letra + 3 números + '\0'
                geraCodigo(A.numvendedor, 'V'); // gera código com a letra V

                printf("Codigo gerado: %s\n", A.numvendedor);

                printf("\n\nNome do cliente: ");
                scanf("%s", A.cliente);
                upper(A.cliente);

                printf("\nData da transacao: ");
                printf("\n Dia: ");
                scanf("%d", &A.trans.dia);
                while (A.trans.dia < 1 || A.trans.dia > 31)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.dia);
                }
                printf(" Mes: ");
                scanf("%d", &A.trans.mes);
                while (A.trans.mes < 1 || A.trans.mes > 12)
                {
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.mes);
                }
                printf(" Ano: ");
                scanf("%d", &A.trans.ano);
                while (A.trans.ano < 1970 || A.trans.ano > 2025)
                {
                    printf("Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }

                printf("\nValor da transacao: ");
                scanf("%f", &A.valor);
                while (A.trans.ano < 0)
                {
                    printf("Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }
                insere(a1, A);
                break;

            //Imprimir todas as vendas
            case 2: // fazer do while pra só conseguir responder 1 e 2
                printf("\nDeseja imprimir em ordem crescente (1) ou em ordem descrescente (2)? ");
                scanf("%d", &ordem);
                if(ordem == 1)
                {
                    Crescente(a1->raiz);
                }
                else
                {
                    Decrescente(a1->raiz);
                }
                break;

             //Buscar as vendas de um determinado vendedor
            case 3: // imprimir mensagem quando o vendedor nao tem nenhuma venda
                printf("Nome do vendedor que deseja buscar as vendas: ");
                scanf("%s", buscado);
                upper(buscado);
                BuscaVendas(a1->raiz, buscado);
                break;

            //Visualizar as vendas acima ou abaixo de um determinado valor
            case 4: // imprimir mensagem quando nao tem nenhuma venda abaixo ou acima
                printf("Digite o valor: ");
                scanf("%f", &valor);
                printf("Qual lista deseja visualizar:");
                printf("\n1 - Lista de vendas abaixo do valor");
                printf("\n2 - Lista de vendas acima do valor\n");
                scanf("%d", &num2);
                // fazer do while pra só conseguir responder 1 e 2
                if(num2==1)
                {
                    ValoresAbaixo(a1->raiz, valor);
                }
                else
                {
                    ValoresAcima(a1->raiz, valor);
                }
                break;

            //Visualizar estatisticas das vendas
            case 5:
                total_vendas = TotalVendas(a1->raiz);
                printf("\nNumero total de vendas = %d", total_vendas);
                faturamento = TotalFaturamento(a1->raiz);
                printf("\nSoma total do faturamento = %.2f", faturamento);
                break;

            //Remover uma venda
            case 6:


        }
    } while (num!=7); //liberar arvore
    return 0;
}
