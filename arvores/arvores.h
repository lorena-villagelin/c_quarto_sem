#ifndef ARVORES_H_INCLUDED
#define ARVORES_H_INCLUDED

//-----estrutura da arvore-----
typedef struct NoArvore
{
    int info; //valor armazenado
    struct NoArvore *esq; //prox no da esquerda
    struct NoArvore *dir; //prox no da direita
}noA;

typedef struct Arvore
{
    noA *raiz; //raiz, no de referencia
}arv;

//-----cria arvore-----
arv *cria_arv()
{
    arv *aux;
    aux=(arv*)malloc(sizeof(arv));
    aux->raiz=NULL;
    return aux;
}

//-----verifica se está vazia-----
int vaziaArv(arv *a)
{
    if(a->raiz==NULL)
    {
        return 1;
    }
    return 0;
}

//-----imprimir arvore-----
void imprimeNo (noA* no)
{
    if(no!=NULL)
    {
        imprimeNo(no->esq); //desce ate o no da esquerda
        printf("| %d |", no->info);
        imprimeNo(no->dir);
    }
}

void imprimeArv(arv* a)
{
    if (a != NULL && a->raiz!=NULL)
    {
        imprimeNo(a->raiz);
    }
    else
    {
        printf("arvore vazia");
    }
}


//-----buscar por valor-----
int buscaArv(noA *pai, int num)
{
    if(pai==NULL) return 0; //se o pai estiver vazio, volta 0
    if(pai->info==num) return 1; //se o numero for igual ao buscado volta 1
    if(num<pai->info)
    {
        return buscaArv(pai->esq, num);
    }
    else
    {
        return buscaArv(pai->dir, num);
    }
}

//-----inserir-----
noA* aux_insere(noA *no, int num)
{
    int flag;
    noA *pai;
    noA *novo=(noA*)malloc(sizeof(noA));
    novo->info=num;
    novo->esq=NULL;
    novo->dir=NULL;
    if(no==NULL)
    {
        return novo;
    }
    else
    {
        pai=no;
        flag=0;
        while(flag==0)
        {
            if(pai->info<num)
            {
                if(pai->dir==NULL)
                {
                    pai->dir=novo;
                    flag=-1;
                }
                else
                {
                    pai=pai->dir;
                }
            }
            else
            {
                if(pai->info>num)
                {
                    if(pai->esq==NULL)
                    {
                        pai->esq=novo;
                        flag=-1;
                    }
                    else
                    {
                        pai=pai->esq;
                    }
                }
            }
        }
    }
    return no;
}

void insere(arv *arvore, int num)
{
    arvore->raiz=aux_insere(arvore->raiz,num);
}

//-----remover-----
noA* remover_aux(noA *pai, int num)
{
    if(pai==NULL) return NULL;
    if(num>pai->info)
    {
        pai->dir=remover_aux(pai->dir, num);
    }
    else if(num<pai->info)
    {
        pai->esq=remover_aux(pai->esq, num);
    }
    else //achou no
    {
        if(pai->dir==NULL && pai->esq==NULL) //nao tem filhos
        {
            free(pai);
            pai=NULL;
        }
        else if(pai->esq==NULL) //so tem filho da direita
        {
            noA *aux=pai->dir;
            free(pai);
            return aux;
        }
        else if(pai->dir==NULL) //só tem filho da esquerda
        {
            noA *aux=pai->esq;
            free(pai);
            return aux;
        }
        else
        {
            noA *aux=pai->esq;
            while(aux->dir!=NULL)
            {
                aux=aux->dir;
            }
            pai->info=aux->info; //copia o maior da esquerda
            pai->esq=remover_aux(pai->esq, aux->info);
        }
    }//nao esta vazio
    return pai;
}

arv* removerArv(arv *r, int num)
{
    if(r==NULL || r->raiz==NULL) return r;
   /* if(r->raiz->info==num  &&  r->raiz->dir==NULL && r->raiz->esq==NULL)
    {
        free(r->raiz);
        free(r);
        return NULL;
    }*/
    r->raiz=remover_aux(r->raiz,num);
    return r;
}


//-----liberar arvore-----
void liberaNo(noA *no)
{
    if(no!=NULL)
    {
        liberaNo(no->esq);
        liberaNo(no->dir);
        free(no);
    }
}

void liberaArv (arv *a)
{
    if(a!=NULL)
    {
        liberaNo(a->raiz);
        free(a);
    }
}



#endif // PILHA_H_INCLUDED
