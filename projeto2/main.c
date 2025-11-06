#include <stdlib.h>  // rand, srand
#include <time.h>    // time

#include <stdio.h>
#include <time.h>

typedef struct {
    int chave;
    double valor;
}item;


void geraVetorAleatorio(item vetor[], int tamanho, int sem)
{
    srand(sem);

    // Gera a primeira chave aleatória entre 100000 e 300000
    vetor[0].chave = 100000 + rand() % 200001;

    // Gera o valor correspondente (aleatório entre 100000 e 300000)
    vetor[0].valor = 100000.0f + ((float)rand() / RAND_MAX) * 200000.0f;

    // A partir do segundo elemento, incrementa 100 na chave
    for (int i = 1; i < tamanho; i++) {
        vetor[i].chave = vetor[i - 1].chave + 100;

        // Valor continua aleatório (se quiser, pode seguir outro padrão)
        vetor[i].valor = 100000.0f + ((float)rand() / RAND_MAX) * 200000.0f;
    }
}


void troca(item *a, item *b)
{
    item temp = *a;
    *a = *b;
    *b = temp;

}


int particaoLS(item *v, int LI, int LS)
{
    int aux, pivo, e = LI, d = LS;
    pivo = v[d].chave;  // pivô é o último elemento

    while (e < d)
    {
        while ((v[e].chave > pivo) && (e < LS))
        {
                e++;
        }
        while ((v[d].chave <= pivo) && (d > LI))
        {
            d--;
        }

        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave= aux;
        }
    }

    aux = v[LS].chave;
    v[LS].chave = v[e].chave;
    v[e].chave = aux;

    return e;  // retorna a posição do pivô
}

int particaoM(item *v, int LI, int LS)
{
    int aux, pivo, e = LI, d = LS;
    pivo = v[(LS + LI) / 2].chave;  // pivô central

    while (e < d)
    {
        while ((v[e].chave > pivo) && (e < LS))
        {
            e++;
        }
        while ((v[d].chave < pivo) && (d > LI))
        {
                d--;
        }

        if (e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
            e++;
            d--;
        }
    }

    return e;
}


void quicksortLS(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particaoLS(v,LI,LS);
        quicksortLS(v,LI,p-1);
        quicksortLS(v,p+1,LS);
    }
}


void quicksortM(item *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p,i;
        p = particaoM(v,LI,LS);
        quicksortM(v,LI,p-1);
        quicksortM(v,p+1,LS);
    }
}

int main()
{
    int i;
    int TAM=32000;
    item *vetor = malloc(TAM * sizeof (item));

    clock_t inicio, fim;
    float tempo_insercao, tempo_quick;

    geraVetorAleatorio(vetor, TAM, 1260);

   /* inicio = clock();
    quicksortLS(vetor,0,TAM-1);
    fim = clock();*/
    inicio=clock();
    quicksortM(vetor,0,TAM-1);
    fim=clock();
     for (i = 0; i < TAM; i++) {
        printf("Chave %d: %d\n",i, vetor[i].chave);
    }
    tempo_quick = (float)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo_quick);
    free(vetor);
    vetor = NULL;
    return 0;
}
