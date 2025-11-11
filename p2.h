#ifndef ARVORE_H
#define ARVORE_H

typedef struct NoArvore
{
    int info;
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

int Vazia(Arv* aux)
{
    if (aux->raiz == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere(Arv *a1, int num)
{
    NoArv *novo;
    NoArv *pai=a1->raiz;
    int flag=0;
    novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = num;
    novo->dir = NULL;
    novo->esq = NULL;
    if(pai == NULL)
    {
        a1->raiz = novo;
        return;
    }
    while(flag==0)
    {
        if(num > pai->info)
        {
            if(pai->dir != NULL)
            {
                pai = pai->dir;
            }
            else
            {
                pai->dir = novo;
                flag = 1;
            }
        }
        if(num < pai->info)
        {
            if(pai->esq != NULL)
            {
                pai = pai->esq;
            }
            else
            {
                pai->esq = novo;
                flag = 1;
            }
        }
    }
}

void imprime(int num)
{
    printf("%d ", num);
}

void PreOrder (NoArv *pai)
{
        imprime(pai->info);

        if(pai->dir != NULL)
        {
            PreOrder(pai->dir);
        }

        if(pai->esq != NULL)
        {
            PreOrder(pai->esq);
        }
}


int Busca (NoArv *pai, int num)
{
   if(pai->info == num)
   {
       printf("\nElemento encontrado!");
       return 1;
   }
   else
   {
       if (num>pai->info)
       {
           if(pai->dir != NULL)
           {
               return Busca(pai->dir, num);
           }
           else
           {
               printf("\nElemento não existe na árvore!");
               return 0;
           }
       }
       if(num<pai->info)
       {
           if(pai->esq != NULL)
           {
               return Busca(pai->esq, num);
           }
           else
           {
               printf("\nElemento não existe na árvore!");
               return 0;
           }
       }
   }
}

#endif
