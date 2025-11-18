#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>




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
    char numvendedor[4];
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

/*void imprime(Dados d)
{
    printf("\n\n");
    printf("%d ", d.id);
    printf("%s | ", d.vendedor);
    printf("%s | ", d.cliente);
    printf("%d/%d/%d | ", d.trans.dia, d.trans.mes, d.trans.ano);
    printf("%.2f ", d.valor);
}*/

void imprime(Dados d)
{
    printf("\n\n");
    // ID (Alinha à esquerda em um campo de largura 5)
    printf("%d ", d.id);
    // Vendedor (Alinha à esquerda em um campo de largura 20)
    printf("%-20s | ", d.vendedor);
    // Cliente (Alinha à esquerda em um campo de largura 20)
    printf("%-20s | ", d.cliente);
    // Data (Alinhamento manual: use %02d para garantir 2 dígitos na data)
    printf("%02d/%02d/%04d | ", d.trans.dia, d.trans.mes, d.trans.ano);
    // Valor (Alinha à esquerda em um campo de largura 10, com 2 casas decimais)
    printf("R$%-10.2f ", d.valor);
}


NoArv* remover_aux(NoArv *pai, int num)
{
    if(pai==NULL)
    {
        printf("\n \n não encontrado na árvore");
    }
    else
    {
        if(num > pai->info.id)
        {
            pai->dir= remover_aux(pai->dir,num);
        }
        else
        {
            if(num < pai->info.id)
            {
                pai->esq = remover_aux(pai->esq,num);
            }
            /*else achou o nó a ser removido*/
            {
                if(pai->dir==NULL && pai->esq==NULL) /* No sem filhos */
                {
                    free(pai); pai=NULL;
                }
                else
                {
                    if (pai->esq==NULL) /*so tem filho da direita */
                    {
                        NoArv *aux=pai;
                        pai = pai->dir;
                        free(aux);
                    }
                    else
                    {
                        if(pai->dir==NULL)/* so tem filho da esquerda */
                        {
                            NoArv *aux=pai;
                            pai = pai->esq;
                            free(aux);
                        }
                        else /* tem os dois filhos */
                        {
                            NoArv *aux;
                            aux = pai->esq;
                            while (aux->dir !=NULL)
                            {
                                aux=aux->dir;
                            }
                            pai->info.id = aux->info.id; /* troca as informações */
                            aux->info.id = num;
                            pai->esq = remover_aux(pai->esq,num);
                        }
                    }
                }
            }// achou o nó a ser removido
        }
    } //else do não estar vazio
    return pai;
}



Arv* remover(Arv *RAIZ, int num)
{
    NoArv *aux=RAIZ->raiz;
    if(aux->info.id==num && aux->dir==NULL && aux->esq==NULL)
    {
        free(aux);
        free(RAIZ);
        return NULL;
    }
    RAIZ->raiz = remover_aux(RAIZ->raiz,num);
    return RAIZ;
}

void BuscaVendas(NoArv *pai, char busca[50])
{
    if (pai==NULL) {
        exit(0);
    }
    if (pai->dir != NULL)
    {
        BuscaVendas(pai->dir, busca);
    }
    if (pai->esq != NULL)
    {
        BuscaVendas(pai->esq, busca);
    }
    if(strcmp(pai->info.vendedor,busca)==0)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("%.2f ", pai->info.valor);
    }
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
        Decrescente(pai->esq);
    }
    imprime(pai->info);
    if (pai->dir != NULL)
    {
        Decrescente(pai->dir);
    }
}

void ValoresAbaixo(NoArv *pai, float num)
{
     if (pai->dir != NULL)
    {
        ValoresAbaixo(pai->dir, num);
    }
    if (pai->esq != NULL)
    {
        ValoresAbaixo(pai->esq, num);
    }
    if(pai->info.valor < num)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.vendedor);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("%.2f ", pai->info.valor);
    }
}

void ValoresAcima(NoArv *pai, float num)
{
     if (pai->dir != NULL)
    {
        ValoresAcima(pai->dir, num);
    }
    if (pai->esq != NULL)
    {
        ValoresAcima(pai->esq, num);
    }
    if(pai->info.valor > num)
    {
        printf("\n\n");
        printf("%d ", pai->info.id);
        printf("%s | ", pai->info.vendedor);
        printf("%s | ", pai->info.cliente);
        printf("%d/%d/%d | ", pai->info.trans.dia, pai->info.trans.mes, pai->info.trans.ano);
        printf("R$%.2f ", pai->info.valor);
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
    int numero = 100 + rand() % 900; // gera número de 3 dígitos (100–999)
    sprintf(codigo, "%c%d", letra, numero); // junta a letra e o número
}

void upper(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = toupper(s[i]);
        i++;
    }
}
