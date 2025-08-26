#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct No
{
    int info;
    struct No *prox;
}no;
typedef struct Pilha
{
    no *topo;
}pilha;

//cria a pilha
pilha* cria(void)
{
    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));
    p -> topo = NULL;
return p;
}

//auxiliar de inserção
no* ins_ini (no* t, int a)
{
    no* aux = (no*) malloc(sizeof(no));
    aux -> info = a;
    aux -> prox = t;
return aux;
}

//inserção
void push (pilha* p, int v)
{
    p -> topo = ins_ini(p -> topo,v);
}

//auxiliar de remoção
no* ret_ini (no* aux)
{
    no* p = aux -> prox;
    free(aux);
    return p;
}

//vazia
int vazia(pilha *p)
{
    if(p -> topo == NULL)
    {
        return 1;
    }
    return 0;
}

//remoção
int pop (pilha *p)
{
    int v;
    if (vazia(p))
    {
        printf("pilha vazia!");
        exit(1); //aborta programa
    }
    v = p -> topo -> info;
    p -> topo = ret_ini(p -> topo);
    return v;
}

//imprimir
void imprime (pilha *p)
{
    no *aux = p -> topo;
    if (vazia(p))
    {
        printf("pilha vazia!");
    }
    else
    {
        while (aux != NULL)
        {
            printf("%d", aux -> info);
            aux = aux -> prox;
        }
    }
}

#endif // PILHA_H_INCLUDED
