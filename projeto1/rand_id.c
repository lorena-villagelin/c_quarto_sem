#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min 100
#define max 999
#define total (max - min + 1)

//gerenciador ids
typedef struct {
    int numeros[total];
    int livres[total];
    int topo_livres;
    int indice;
} GerenciadorIDs;

//inicializa o gerenciador
void init_gerenciador(GerenciadorIDs *g)
{
    g->topo_livres = -1; //ainda nao ha ids deletados
    g->indice = 0;

    //preenche com todos os numeros possíveis dentro do intervalo
    for (int i = 0; i < total; i++)
    {
        g->numeros[i] = min + i;
    }

    //embaralha os números, gerando aleatorios
    for (int i = total - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); //escolhe um aleatorio entre 0 e i
        int tmp = g->numeros[i]; //troca [i] com [j]
        g->numeros[i] = g->numeros[j];
        g->numeros[j] = tmp;
    }
}

//gera um ID
int gerar_id(GerenciadorIDs *g)
{
    if (g->topo_livres >= 0)
    {
        //reutiliza ID deletado
        return g->livres[g->topo_livres--];
    }
    if (g->indice < total)
    {
        return g->numeros[g->indice++]; //se tiver ids nao usados, retorna o prox array
    }
    else
    {
        printf("Todos os IDs foram usados!\n"); //se todos os ids estão em uso
        exit(1);
    }
}

//deleta um ID (para reutilização futura)
void deletar_id(GerenciadorIDs *g, int id)
{
    if (g->topo_livres < total - 1)
    {
        g->livres[++g->topo_livres] = id; //coloca id no topo da lista de ids livres
    }
}

int main()
{
    srand(time(NULL)); //inicializa o gerador de numeros com o tempo

    GerenciadorIDs gerenciador;
    init_gerenciador(&gerenciador);
    return 0;
}
