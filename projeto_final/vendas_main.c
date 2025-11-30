#include "vendas.h"

int main ()
{
    Arv *a1;
    a1 = CriaArvore();
    Dados A;
    int num, num2, total_vendas, ordem, id_remove, buscaid=0;
    int vendas=0, valores1=0, valores2=0;
    float valor, faturamento;
    char buscado[50];

     do {
            do {
                line(); tab(); tab();
                printf("VENDAS");
                line(); tab();
                printf("1. Insira uma nova venda.\n\n");
                tab();
                printf("2. Imprimir todas as vendas.\n\n");
                tab();
                printf("3. Buscar as vendas de um determinado vendedor.\n\n");
                tab();
                printf("4. Visualizar as vendas acima ou abaixo de um determinado valor.\n\n");
                tab();
                printf("5. Visualizar estatisticas das vendas.\n\n");
                tab();
                printf("6. Remover uma venda.\n\n");
                tab();
                printf("7. Finalizar o sistema.");
                line(); tab();
                printf("Insira sua opcao: ");
                scanf("%d", &num);
                limpa();
                } while (num<1 || num>7);

        switch (num) {
            case 1:
                titulo("CADASTRO");

                A.id = gera();
                tab();
                printf("ID da venda: %d\n", A.id);

                tab();
                printf("Nome do vendedor: ");
                scanf("%s", A.vendedor);
                strupr(A.vendedor);

                srand(time(NULL));
                geraCodigo(A.numvendedor, 'V');
                tab();
                printf("Codigo gerado: %s\n", A.numvendedor);

                tab();
                printf("Nome do cliente: ");
                scanf("%s", A.cliente);
                strupr(A.cliente);

                tab();
                printf("Data da transacao:\n ");
                tab();
                printf("| Dia: ");
                scanf("%d", &A.trans.dia);
                while (A.trans.dia < 1 || A.trans.dia > 31)
                {
                    tab();
                    printf("  Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.dia);
                }
                tab();
                printf("| Mes: ");
                scanf("%d", &A.trans.mes);
                while (A.trans.mes < 1 || A.trans.mes > 12)
                {
                    tab();
                    printf("  Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.mes);
                }
                tab();
                printf("| Ano: ");
                scanf("%d", &A.trans.ano);
                while (A.trans.ano < 1900 || A.trans.ano > 2025)
                {
                    tab();
                    printf("  Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }

                tab();
                printf("Valor da transacao: R$");
                scanf("%f", &A.valor);
                while (A.trans.ano < 0)
                {
                    tab();
                    printf("Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.ano);
                }
                titulo("SALVO!");
                fflush(stdin);
                getchar();
                limpa();
                insere(a1, A);
                break;

            case 2:
                titulo("IMPRESSAO");
                if(a1->raiz == NULL)
                {
                    tab();
                    printf("Nao ha vendas cadastradas.");
                    limpa();
                    break;
                }
                do{
                        tab();
                        printf("Digite o formato de impressao:\n");
                        tab();
                        printf("[1] Ordem crescente\n");
                        tab();
                        printf("[2] Ordem decrescente\n");
                        tab();
                        printf("Opcao: ");
                        scanf("%d", &ordem);
                }while(ordem!=1 && ordem!=2);
                if(ordem == 1)
                {
                    Crescente(a1->raiz);
                }
                else
                {
                    Decrescente(a1->raiz);
                }
                fflush(stdin);
                getchar();
                limpa();
                break;

            case 3:
                titulo("BUSCA");
                if(a1->raiz == NULL)
                {
                    tab();
                    printf("Nao ha vendas cadastradas.");
                    limpa();
                    break;
                }
                tab();
                printf("Nome do vendedor que deseja buscar as vendas: ");
                scanf("%s", buscado);
                strupr(buscado);
                vendas=0;
                header_vendas();
                BuscaVendas(a1->raiz, buscado, &vendas);
                if(vendas == 0)
                {
                    tab();
                    printf("O vendedor buscado nao realizou nenhuma venda");
                }
                fflush(stdin);
                getchar();
                limpa();
                break;

            case 4:
                titulo("VENDAS");
                if(a1->raiz == NULL)
                {
                    tab();
                    printf("Nao ha vendas cadastradas.");
                    limpa();
                    break;
                }
                tab();
                printf("Digite o valor: ");
                scanf("%f", &valor);
                tab();
                do {
                        printf("Qual lista deseja visualizar:\n");
                        tab();
                        printf("[1] Lista de vendas abaixo do valor\n");
                        tab();
                        printf("[2] Lista de vendas acima do valor\n");
                        tab();
                        printf("Opcao: ");
                        scanf("%d", &num2);
                } while(num2!=1 && num2!=2);

                if(num2==1)
                {
                    ValoresAbaixo(a1->raiz, valor, &valores1);
                    if(valores1 == 0)
                    {
                        tab();
                        printf("Nao ha vendas abaixo desse valor.");
                    }
                }
                else
                {
                    ValoresAcima(a1->raiz, valor, &valores2);
                    if(valores2 == 0)
                    {
                        tab();
                        printf("\nNao ha vendas acima desse valor.");
                    }
                }
                fflush(stdin);
                getchar();
                limpa();
                break;

            case 5:
                titulo("ESTATISTICAS");
                if(a1->raiz == NULL)
                {
                    tab();
                    printf("Nao ha vendas cadastradas.");
                    limpa();
                    break;
                }
                total_vendas = TotalVendas(a1->raiz);
                tab();
                printf("Numero total de vendas = %d\n", total_vendas);
                faturamento = TotalFaturamento(a1->raiz);
                tab();
                printf("Soma total do faturamento = %.2f", faturamento);
                limpa();
                break;

            case 6:
                titulo("REMOCAO");
                if(a1->raiz == NULL)
                {
                    tab();
                    printf("Nao ha vendas cadastradas.");
                    limpa();
                    break;
                }
                tab();
                printf("Digite o ID da venda que deseja remover: ");
                scanf("%d", &id_remove);
                if(BuscaID(a1->raiz, id_remove, buscaid)==1)
                {
                    a1 = remover(a1, id_remove);
                }
                else
                {
                    tab();
                    printf("O ID nao existe.");
                }
                limpa();
                break;

        }
    } while (num!=7);
    libera_estrutura(a1);
    return 0;
}
