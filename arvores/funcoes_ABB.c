#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

//Some o valor dos nós pares
int somapar(noA *pai)
{
    int soma=0;
    if(pai==NULL) return 0;
    if(pai->info%2==0)
    {
        soma+=pai->info;
    }
    soma+=somapar(pai->dir);
    soma+=somapar(pai->esq);
    return soma;
}

//Quantidade de folhas
int qt_folhas(noA *pai)
{
    int qtidade=0;
    if(pai==NULL) return 0;
    if(pai->dir==NULL && pai->esq==NULL)
    {
        qtidade++;
    }
    qtidade+=qt_folhas(pai->dir);
    qtidade+=qt_folhas(pai->esq);
    return qtidade;
}

//Altura de uma árvore
int altura(noA *pai)
{
    int L, R;
    if(pai==NULL) return 0; //se a arvore estiver vazia é zero
    L=altura(pai->esq); //recursão para medir os lados da árvore
    R=altura(pai->dir);
    if(L>R) return 1+ L; //soma a altura da raiz no lado mais alto e retorna
    else return 1+ L;
}

//Nível de um determinado nó, se ele existir na árvore.
int nivel(noA *pai, int no)
{
    int lvl=0;
    if(pai->info==no) return lvl;
    if(pai->dir!=NULL)
    {
        lvl = 1+nivel(pai->dir, no);
    }
    if(pai->esq!=NULL)
    {
        lvl = 1+nivel(pai->esq, no);
    }
}

//Determine o maior nó par da árvore
int maiorpar(noA * pai)
{
    if(pai== NULL) return -1;
    int maior = -1;
    if(pai->info%2==0)
    {
        maior = pai->info;
    }
    int esq = maiorpar(pai->esq);
    if (esq > maior)
    {
        maior = esq;
    }
    int dir = maiorpar(pai->dir);
    if (dir > maior)
    {
        maior = dir;
    }
    return maior;
}

//Quantidade de ancestrais de um nó, se ele existir na árvore
int ancestrais(noA *pai, int no)
{
    int cont=0;
    if(pai!=NULL)
    {
        if(pai->info==no) return cont;
        if(pai->dir!=NULL) return cont+=1+ancestrais(pai->dir, no);
        if(pai->esq!=NULL) return cont+=1+ancestrais(pai->esq, no);
    }
    return 0;
}

//Quantidade de descendentes de um nó, se ele existir na árvore
int conta(noA* pai) //conta os nós
{
    if (pai!=NULL) return 1+conta(pai->dir)+conta(pai->esq);
}

int descendentes(noA* pai, int no)
{
    if(pai!=NULL)
    {
        if (pai->info==no) return conta(pai);
        if (pai->info>no) return descendentes(pai->esq, no);
        else return descendentes(pai->dir, no);
    }
    return 0;
}

//numero de nós maior que um certo valor
int maiorque(noA* pai, int v)
{
    int cont=0;
    if(pai!=NULL)
    {
        if(pai->info>v)
        {
            cont++;
        }
        if(pai->dir!=NULL)
        {
            cont+=maiorque(pai->dir, v);
        }
        if(pai->esq!=NULL)
        {
            cont+=maiorque(pai->esq, v);
        }
    }
    return cont;
}

//elementos de uma árvore até certo nível
void imp_nivel(noA* pai, int lvl)
{
    if(pai!=NULL && lvl!=0)
    {
        printf("%d ", pai->info);
        imp_nivel(pai->esq, lvl-1);
        imp_nivel(pai->dir, lvl-1);
    }
}

//número de nós após em um certo nível
int aposnivel(noA* pai, int lvl, int atual)
{
    if(pai==NULL) return 0;
    int cont=0;
    if (atual > lvl) cont = 1;
    if(pai->esq!=NULL) cont += aposnivel(pai->esq, lvl, atual + 1);
    if(pai->dir!=NULL)  cont += aposnivel(pai->dir, lvl, atual + 1);
    return cont;
}

//remoção das folhas
noA* remove_folha(noA* pai)
{
    if(pai==NULL) return NULL;
    if(pai->dir==NULL && pai->esq==NULL)
    {
        free(pai);
        return NULL;
    }
    pai->esq=remove_folha(pai->esq);
    pai->dir=remove_folha(pai->dir);
    return pai;
}

//num de nos da subarvore da esquerda de certo nó
int subesq(noA* pai, int no)
{
    if(pai==NULL) return 0;
    if(pai->info==no) return conta(pai->esq);
    return subesq(pai->esq, no);
    return subesq(pai->dir, no);
}

//imprime o pai de uma valor
void imp_pai(noA* pai, int no)
{
    if(pai!=NULL)
    {
        if(pai->esq!=NULL && pai->esq->info==no) printf("%d", pai->info);
        if(pai->dir!=NULL && pai->dir->info==no) printf("%d", pai->info);
        imp_pai(pai->esq, no);
        imp_pai(pai->dir, no);
    }
}

//menor elemento
int menor(noA* pai)
{
    if(pai==NULL) return 999;
    int m=pai->info;
    int E=menor(pai->esq);
    int D=menor(pai->dir);
    if(E<m) m=E;
    if(D<m) m=D;
    return m;
}

//remove o menor elemento
noA* remenor(noA* pai)
{
    if(pai==NULL) return NULL;
    if(pai->esq==NULL)
    {
        noA* aux=pai->dir;
        free(pai);
        return aux;
    }
    pai->esq=remenor(pai->esq);
    return pai;
}

//quantidade de nós com somente um filho
int filho(noA* pai)
{
    int qt=0;
    if(pai==NULL) return 0;
    if((pai->esq==NULL && pai->dir!=NULL) || (pai->esq!=NULL && pai->dir==NULL)) return qt+=1+filho(pai->esq)+filho(pai->dir);
}

//profundidade
int profundidade(noA* pai)
{
    if(pai==NULL) return 0;
    int D=profundidade(pai->dir);
    int E=profundidade(pai->esq);
    if(D>E) return 1+D;
    else return 1+E;
}


int main()
{
    arv *a= cria_arv(), *b=cria_arv();
    int no;

    insere(a, 30);
    insere(a, 23);
    insere(a, 19);
    insere(a, 20);
    insere(a, 18);

    imprimeArv(a);

    int qt=conta(a->raiz);
    printf("\n\nqtidade de nos: %d\n\n", qt);


    /*b->raiz=remove_folha(a->raiz);
    imprimeArv(b);

    int s=somapar(a->raiz);
    printf("\nsoma pares: %d\n", s);

    int q=qt_folhas(a->raiz);
    printf("\nquantidade de folhas: %d\n", q);

    int h=altura(a->raiz);
    printf("\naltura: %d\n", h);

    printf("\n no que deseja ver o nivel: ");
    scanf("%d", &no);
    int lvl=nivel(a->raiz, no);
    printf("\nnivel: %d\n", lvl);

    int mp = maiorpar(a->raiz);
    printf("\nmaior par: %d", mp);

    printf("\n\n no que deseja ver os ancestrais: ");
    scanf("%d", &no);
    int anc = ancestrais(a->raiz, no);
    printf("\nancestrais: %d", anc);

    printf("\n\n no que deseja ver os descendentes: ");
    scanf("%d", &no);
    int desc = descendentes(a->raiz, no);
    printf("\ndescendentes: %d", desc);

    printf("\n\n maior que: ");
    scanf("%d", &no);
    int maior = maiorque(a->raiz, no);
    printf("%d", maior);

    printf("\n\nnivel: ");
    scanf("%d", &no);
    imp_nivel(a->raiz, no);

    printf("\n\napos nivel: ");
    scanf("%d", no);
    int apos=aposnivel(a->raiz, no, 0);
    printf("%d", apos);

    printf("\n\nsubarvore da esquerda de: ");
    scanf("%d", &no);
    int sub=subesq(a->raiz, no);
    printf("%d", sub);

    printf("\n\nimprimir pair de: ");
    scanf("%d", &no);
    imp_pai(a->raiz, no);

    int men = menor(a->raiz);
    printf("\n\nmenor elemento: %d\n\n", men);
    b->raiz=remenor(a->raiz);
    imprimeArv(b);

    int f=filho(a->raiz);
    printf("nos com um filho: %d", f);*/

    int p=profundidade(a->raiz);
    printf("profundidade: %d", p);

}
