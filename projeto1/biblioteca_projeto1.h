#ifndef lib_h_include
#define lib_h_included

#include <ctype.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct dados
{
    char nome[50];
    int idade;
    int id;
    char especie[30];
    int prior;       // 0 = emergência, 1 = normal
    Data aniv;       // data de nascimento
} Dados;

//guarda os dados de cada pet
typedef struct no
{
    struct no *prox; // ponteiro para o próximo nó
    Dados info;      // informações do pet
} No;


//fila -> guarda os pets em ordem de chegada
typedef struct lista
{
    No* ini;   // ponteiro para o primeiro nó
    No* fim;   // ponteiro para o último nó
} Fila;


//funções da fila

//cria fila vazia
Fila* CriaFila(void)
{
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

//verifica se está vazia (1=sim e 0=não)
int vaziaFila(Fila* f)
{
    if (f->ini == NULL) return 1;
    else return 0;
}


//insere um nó no fim
No* ins_fim(No *fim, char nome[50], int idade, char especie[30], int prior, int dia, int mes, int ano)
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


//insere um pet
void insere_pet(Fila *f, char nome[50], int idade, char especie[30], int prior, int dia, int mes, int ano)
{
    f->fim = ins_fim(f->fim, nome, idade, especie, prior, dia, mes, ano);
    if (f->ini == NULL)
    {
        f->ini = f->fim;
    }
}


//remove primeiro pet da fila
No* remove_pet(No* ini)
{
    No *p = ini->prox;
    free(ini);   // libera o primeiro nó
    return p;    // retorna o novo início
}

//passa pet para a fila de atendidos
void atende(Fila *f, Fila *atendidos)
{
    No* aux = f->ini;
    // copia o pet removido para a fila de atendidos
    insere_pet(atendidos, aux->info.nome, aux->info.idade, aux->info.especie, aux->info.prior,
           aux->info.aniv.dia, aux->info.aniv.mes, aux->info.aniv.ano);
    f->ini = remove_pet(f->ini);   // remove do início da fila original
    if (f->ini == NULL) {
        f->fim = NULL;   // se esvaziou, ajusta também o fim
    }
}


//imprime próx a ser atendido
void imprime_prox(Fila *f)
{
    No* aux = f->ini;
    printf("\n%s | ", aux->info.nome);
    printf("%s | ", aux->info.especie);
    printf("%d | ", aux->info.prior);
}


//busca pet pelo nome
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
            return 1;   // encontrado
        }
        else
        {
            aux = aux->prox;
        }
    }
    return 0;  // não encontrado
}

//imprime todos os pets pela ordem de chegada
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

#endif // fila_h_include
