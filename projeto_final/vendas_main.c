#include "vendas.h"


void limpa()
{
    fflush(stdin);
    getchar();
    system("cls");
}

void line()
{
    printf("\n\t\t--------------------------------------------------------------------------------\n");
}


void titulo(const char *nome)
{
    line(); tab(); tab();
    printf("%s\n", nome);
    line();
}

int main ()
{
    Arv *a1;
    a1 = CriaArvore();
    Dados A;
    int num, num2, total_vendas, ordem, id_remove;
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

                } while (num<1 || num>7);

        switch (num) {
            //Insira uma nova venda
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
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.dia);
                }
                tab();
                printf("| Mes: ");
                scanf("%d", &A.trans.mes);
                while (A.trans.mes < 1 || A.trans.mes > 12)
                {
                    tab();
                    printf(" Valor invalido, digite novamente: ");
                    scanf("%d", &A.trans.mes);
                }
                tab();
                printf("| Ano: ");
                scanf("%d", &A.trans.ano);
                while (A.trans.ano < 1900 || A.trans.ano > 2025)
                {
                    tab();
                    printf("Valor invalido, digite novamente: ");
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

                insere(a1, A);

                break;

            //Imprimir todas as vendas
            case 2: // quando a lista ta vazia, precisa de um aviso
                titulo("IMPRESSAO");
                do{
                        tab();
                        printf("Deseja imprimir em ordem crescente (1) ou em ordem descrescente (2)? ");
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
                break;

             //Buscar as vendas de um determinado vendedor
            case 3: // imprimir mensagem quando o vendedor nao tem nenhuma venda
                titulo("BUSCA");
                tab();
                printf("Nome do vendedor que deseja buscar as vendas: ");
                scanf("%s", buscado);
                strupr(buscado);
                BuscaVendas(a1->raiz, buscado);
                break;

            //Visualizar as vendas acima ou abaixo de um determinado valor
            case 4: // imprimir mensagem quando nao tem nenhuma venda abaixo ou acima
                titulo("VENDAS");
                printf("Digite o valor: ");
                scanf("%f", &valor);
                tab();
                printf("Qual lista deseja visualizar:");
                tab();
                printf("[1] Lista de vendas abaixo do valor");
                tab();
                printf("[2] Lista de vendas acima do valor\n");
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
                titulo("ESTATISTICAS");
                total_vendas = TotalVendas(a1->raiz);
                tab();
                printf("Numero total de vendas = %d", total_vendas);
                faturamento = TotalFaturamento(a1->raiz);
                tab();
                printf("Soma total do faturamento = %.2f", faturamento);
                break;

            //Remover uma venda
            case 6: // quando o id nao existe, mostrar mensagem
                titulo("REMOCAO");
                tab();
                printf("Digite o ID da venda que deseja remover: ");
                scanf("%d", &id_remove);
                a1 = remover(a1, id_remove);
            break;

        }
    } while (num!=7); //liberar arvore
    return 0;
}
