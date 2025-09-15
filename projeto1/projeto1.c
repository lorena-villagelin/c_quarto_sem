#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct dados
{
    char nome[50];
    int idade;
    int id;
    char especie[30];
    int prior;
    Data aniv;
}Dados;

typedef struct no
{
    struct no *prox;
    Dados info;
}No;

typedef struct lista
{
    No* ini;
    No* fim;
}Fila;

Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int vaziaFila(Fila* f)
{
    if (f->ini == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

No* ins_fim(No *fim, char nome[50], char idade, char especie[30], int prior, int dia, int mes, int ano)
{
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->info.nome, nome);
    novo->info.idade = idade;
    strcpy(novo->info.especie, especie);
    novo->info.prior = prior;
    novo->info.aniv.dia = dia;
    novo->info.aniv.mes = mes;
    novo->info.aniv.ano = ano;
    novo->prox = NULL;
    if (fim != NULL)
    {
        fim->prox = novo;
    }
    return novo;
}

void insere(Fila *f, char nome[50], int idade, char especie[30], int prior, int dia, int mes, int ano)
{
    f->fim = ins_fim(f->fim, nome, idade, especie, prior, dia, mes, ano);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}

No* ret_ini(No* ini)
{
    No *p = ini -> prox;
    free(ini);
    return p;
}

void retira(Fila *f, Fila *atendidos)
{
    No* aux = f->ini;
    insere(atendidos, aux->info.nome, aux->info.idade, aux->info.especie, aux->info.prior, aux->info.aniv.dia, aux->info.aniv.mes, aux->info.aniv.ano);
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL)
    {
        f->fim = NULL;
    }
}

void imprime_prox(Fila *f)
{
    No* aux = f->ini;
    printf("\n%s | ", aux->info.nome);
    printf("%s | ", aux->info.especie);
    printf("%d | ", aux->info.prior);
}

int busca(Fila *f, char nome[50])
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        if (strcmp(aux->info.nome, nome)==0)
        {
            printf("\nO animal buscado está cadastrado!");
            printf("\n%s | ", aux->info.nome);
            printf("%s | ", aux->info.especie);
            printf("%d | ", aux->info.prior);
            return 1;
        }
        else
        {
            aux = aux->prox;
            //return 0;
        }
    }
    return 0;
}

void imprime(Fila *f)
{
    No* aux = f->ini;
    while (aux != NULL)
    {
        printf("\n%s | ", aux->info.nome);
        printf("%s | ", aux->info.especie);
        printf("%d | ", aux->info.idade);
        printf("%d/%d/%d | ", aux->info.aniv.dia, aux->info.aniv.mes, aux->info.aniv.ano);
        printf("%d ", aux->info.prior);
        aux = aux->prox;
    }
}

int main()
{
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
        } while (num<1 || num>7);
        switch (num) {
            case 1:
                printf("\nFicha de cadastro - ");
                printf("\nNome do pet: ");
                scanf("%s", nome);
                //printf("\nID do pet: ");
                // scanf("%d", &id);
                printf("\nIdade do pet: ");
                scanf("%d", &idade);
                printf("\nEspécie do pet: ");
                scanf("%s", especie);
                printf("\nData de nascimento: ");
                printf("\nDia: ");
                scanf("%d", &dia);
                printf("Mês: ");
                scanf("%d", &mes);
                printf("Ano: ");
                scanf("%d", &ano);
                printf("\nPrioridade do pet (0 – Emergência, 1- Normal): ");
                scanf("%d", &prior);
                if (prior==0)
                {
                    insere(emerg, nome, idade, especie, prior, dia, mes, ano);
                }
                else
                {
                    insere(normal, nome, idade, especie, prior, dia, mes, ano);
                }
                    insere(geral, nome, idade, especie, prior, dia, mes, ano);
                break;
            case 2:
                if (vaziaFila(emerg)==1)
                {
                    retira(normal, atendidos);
                }
                else
                {
                    retira(emerg, atendidos);
                }
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
                 break;
             case 4:
                printf("Emergência: ");
                imprime(emerg);
                printf("\nAtendimento normal: ");
                imprime(normal);
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
                break;
             case 6:
                 imprime(atendidos);
                 break;

        }
    } while (num!=7);
    return 0;
}
