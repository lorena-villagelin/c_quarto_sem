#ifndef fila_h_include
#define fila_h_included

typedef struct Nos
{
    int info;
    struct Nos *prox;
}nos;

typedef struct Fila
{
    nos * ini;
    nos * fim;
}fila;

int vaziafila(fila* f)
{
    if (f->ini == NULL) return 1;
    return 0;
}

fila* criafila()
{
    fila* f = (fila*)malloc(sizeof(fila));
    f->ini = f->fim = NULL;
}

nos* ins_fim(nos *fim, int A)
{
    nos *p = (nos*)malloc(sizeof(nos));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL)
    fim->prox = p;
    return p;
}

void inserefila(fila* f, int v)
{
    f->fim = ins_fim(f->fim, v);
    if (f->ini == NULL)
    f->ini = f->fim;
}

nos* retira_ini(nos* ini)
{
    nos* p = ini->prox;
    free(ini);
    return p;
}

int retirafila(fila* f)
{
    int v;
    if (vaziafila(f))
    {
        printf("fila vazia :(\n");
        exit(0);
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if(f->ini == NULL)
    return v;
}

void imprimefila(fila* f)
{
    nos* q;
    for (q=f->ini; q!=NULL; q=q->prox)
    {
        printf("| %d |", q->info);
    }
    printf("\n");
}

fila* liberafila(fila* f)
{
    nos* q = f->ini;
    while (q!=NULL)
    {
        nos* t = q->prox;
        free(q);
    }
    free(f);
    return NULL;
}
#endif // fila_h_include
