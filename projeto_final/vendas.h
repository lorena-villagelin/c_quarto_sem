#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void limpa()
{
    fflush(stdin);
    getchar();
    system("cls");
}

void tab()
{
    printf("\t\t\t");
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

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct dados
{
    int id;
    char cliente[50];
    char vendedor[50];
    char numvendedor[5];
    Data trans;
    float valor;
}Dados;

typedef struct NoArvore
{
    Dados info;
    struct NoArvore *dir;
    struct NoArvore *esq;
}NoArv;

typedef struct Arvore
{
    NoArv *raiz;
}Arv;

Arv* CriaArvore(void)
{
    Arv *aux;
    aux = (Arv*) malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

int ArvVazia(Arv *arv)
{
    if (arv->raiz == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void insere(Arv *a1, Dados d)
{
    NoArv *novo;
    NoArv *pai=a1->raiz;
    int flag=0;
    novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = d;
    novo->dir = NULL;
    novo->esq = NULL;
    if (a1->raiz == NULL)
    {
        a1->raiz = novo;
        return;
    }
    else
    {
        while (flag==0)
        {
            if (d.id > pai->info.id)
            {
                if (pai->dir != NULL)
                {
                    pai = pai->dir;
                }
                else
                {
                    pai->dir = novo;
                    flag=1;
                }
            }
            else
            {
                if (pai->esq != NULL)
                {
                    pai = pai->esq;
                }
                else
                {
                    pai->esq = novo;
                    flag=1;
                }
            }
        }
    }
}

void header()
{
    printf("\n\n");
    printf("| %-4s | ", "ID");
    printf("%-30s | ", "VENDEDOR");
    printf("%-4s | ", "COD");
    printf("%-30s | ", "CLIENTE");
    printf("%-10s | ", "DATA");
    printf("%-12s |\n", "VALOR");
}

void imprime(Dados d)
{
    header();
    printf("| %4d | ", d.id);
    printf("%-30s | ", d.vendedor);
    printf("%-4s | ", d.numvendedor);
    printf("%-30s | ", d.cliente);
    printf("%02d/%02d/%04d | ", d.trans.dia, d.trans.mes, d.trans.ano);
    printf("R$%-10.2f |\n", d.valor);
}

NoArv* remover_aux(NoArv *pai, int num)
{
    if (pai == NULL)
    {
        return NULL;
    }

    if (num > pai->info.id)
    {
        pai->dir = remover_aux(pai->dir, num);
    }
    else if (num < pai->info.id)
    {
        pai->esq = remover_aux(pai->esq, num);
    }
    else
    {
        if (pai->esq == NULL && pai->dir == NULL)
        {
            free(pai);
            return NULL;
        }
        if (pai->esq == NULL)
        {
            NoArv *aux = pai->dir;
            free(pai);
            return aux;
        }
        if (pai->dir == NULL)
        {
            NoArv *aux = pai->esq;
            free(pai);
            return aux;
        }
        NoArv *aux = pai->esq;
        while (aux->dir != NULL)
            aux = aux->dir;

        pai->info = aux->info;
        pai->esq = remover_aux(pai->esq, aux->info.id);
    }

    return pai;
}

Arv* remover(Arv *RAIZ, int num)
{
    RAIZ->raiz = remover_aux(RAIZ->raiz, num);
    return RAIZ;
}

void header_vendas()
{
    printf("\n\n");
    tab();
    printf("| %-4s | ", "ID");
    printf("%-30s | ", "CLIENTE");
    printf("%-10s | ", "DATA");
    printf("%-12s |\n\n", "VALOR");
}

void BuscaVendas(NoArv *pai, char busca[], int *Vendas)
{
    if (pai!=NULL)
    {
        if (pai->dir != NULL)
        {
            BuscaVendas(pai->dir, busca, Vendas);
        }
        if (pai->esq != NULL)
        {
            BuscaVendas(pai->esq, busca, Vendas);
        }
        if(strcmp(pai->info.vendedor,busca)==0)
        {
            (*Vendas) = 1;
            tab();
            printf("| %4d | ", pai->info.id);
            printf("%-30s | ", pai->info.cliente);
            printf("%02d/%02d/%04d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
            printf("R$%-10.2f |\n", pai->info.valor);
        }
    }
}

void BuscaMat(NoArv *pai, char busca[], int *Vendas)
{
    if (pai!=NULL)
    {
        if (pai->dir != NULL)
        {
            BuscaMat(pai->dir, busca, Vendas);
        }
        if (pai->esq != NULL)
        {
            BuscaMat(pai->esq, busca, Vendas);
        }
        if(strcmp(pai->info.numvendedor,busca)==0)
        {
            (*Vendas) = 1;
            tab();
            printf("| %4d | ", pai->info.id);
            printf("%-30s | ", pai->info.cliente);
            printf("%02d/%02d/%04d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
            printf("R$%-10.2f |\n", pai->info.valor);
        }
    }
}

int BuscaID(NoArv *pai, int id, int resul)
{
    if(pai->info.id == id)
    {
        resul = 1;
    }
    if (pai->dir != NULL)
    {
        resul = BuscaID(pai->dir, id, resul);
    }
    if (pai->esq != NULL)
    {
        resul = BuscaID(pai->esq, id, resul);
    }
    return resul;
}


void Decrescente(NoArv *pai)
{
    if (pai->dir != NULL)
    {
        Decrescente(pai->dir);
    }
    imprime(pai->info);
    if (pai->esq != NULL)
    {
        Decrescente(pai->esq);
    }
}

void Crescente(NoArv *pai)
{
      if (pai->esq != NULL)
    {
        Crescente(pai->esq);
    }
    imprime(pai->info);
    if (pai->dir != NULL)
    {
        Crescente(pai->dir);
    }
}

void ValoresAbaixo(NoArv *pai, float num, int *valores)
{
     if (pai->dir != NULL)
    {
        ValoresAbaixo(pai->dir, num, valores);
    }
    if (pai->esq != NULL)
    {
        ValoresAbaixo(pai->esq, num, valores);
    }
    if(pai->info.valor < num)
    {
        header();
        (*valores) = 1;
        printf("\n\n");
        printf("| %4d | ", pai->info.id);
        printf("%-30s | ", pai->info.vendedor);
        printf("%-4s | ", pai->info.numvendedor);
        printf("%-30s | ", pai->info.cliente);
        printf("%02d/%02d/%04d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("R$%-10.2f |\n", pai->info.valor);
    }
}

void ValoresAcima(NoArv *pai, float num, int *valores)
{
     if (pai->dir != NULL)
    {
        ValoresAcima(pai->dir, num, valores);
    }
    if (pai->esq != NULL)
    {
        ValoresAcima(pai->esq, num, valores);
    }
    if(pai->info.valor > num)
    {
        header();
        (*valores) = 1;
        printf("\n\n");
        printf("| %4d | ", pai->info.id);
        printf("%-30s | ", pai->info.vendedor);
        printf("%-4s | ", pai->info.numvendedor);
        printf("%-30s | ", pai->info.cliente);
        printf("%02d/%02d/%04d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("R$%-10.2f |\n", pai->info.valor);
    }
}

int TotalVendas (NoArv *pai)
{
    int cont = 1;
    if(pai == NULL)
    {
        return 0;
    }
    if (pai->dir != NULL)
    {
        cont = cont + TotalVendas(pai->dir);
    }
    if(pai->esq != NULL)
    {
        cont = cont + TotalVendas(pai->esq);
    }
    return cont;
}

float TotalFaturamento (NoArv *pai)
{
    float soma = pai->info.valor;
    if(pai == NULL)
    {
        return 0;
    }
    if(pai->dir != NULL)
    {
        soma = soma + TotalFaturamento(pai->dir);
    }
    if(pai->esq != NULL)
    {
        soma = soma + TotalFaturamento(pai->esq);
    }
    return soma;
}

int gera (void)
{
    return rand() % 900 + 100;
}

void geraCodigo(char *codigo, char letra) {
    int numero = 100 + rand() % 900;
    sprintf(codigo, "%c%d", letra, numero);
    codigo[4]='\0';
}

void libera_arvore(NoArv *pai)
{
    if (pai != NULL)
    {
        libera_arvore(pai->esq);
        libera_arvore(pai->dir);
        free(pai);
    }
}

void libera_estrutura(Arv *arv)
{
    if (arv != NULL)
    {
        libera_arvore(arv->raiz);
        free(arv);
    }
}
