/*criando uma lista*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no //cria lista
{
    int info;
    struct no *prox;
} no;

typedef no lista; //inicializa
lista* inicializa()
{
    return NULL;
}

lista* insereinicio(lista* recebida, int valor) //inserindo no inicio
{
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    if (novo != NULL)
    {
        novo -> info = valor;
        novo -> prox = recebida;
        return novo;
    }
}

lista* removeinicio(lista *aux, int *removido) //remover do inicio
{
    if (aux == NULL)
    {
        *removido = -1;
        return NULL;
    }
    if (aux -> prox == NULL)
    {
        *removido = aux -> info;
        free(aux);
        return NULL;
    }
    lista *aux2;
    aux2 = aux;
    aux = aux -> prox;
    *removido = aux2 -> info;
    free(aux2);
    return aux;
}

lista* inserefinal(lista* recebida, int valor) //inserindo no final
{
    lista *novo, *aux;
    aux = recebida;
    novo = (lista*)malloc(sizeof(lista));
    novo -> info = valor;
    novo -> prox = NULL;
    if(recebida==NULL)
    {
        return novo;
    }
    else
    {
        while(aux -> prox != NULL)
        {
            aux = aux -> prox;
        }
        aux -> prox = novo;
        return recebida;
    }
}

lista* removefinal(lista *aux, int *removido) //remover do inicio
{
    lista *atual = aux;
    lista *anterior = NULL;
    if (aux == NULL)
    {
        return NULL;
        *removido = -1;
    }
    if(aux->prox == NULL)
    {
        free(aux);
        return NULL;
        *removido = aux -> info;
    }
    while(atual -> prox != NULL) //percorrendo até o ultimo
    {
        anterior = atual;
        atual = atual -> prox;
    }
    *removido = atual -> info;
    anterior -> prox = NULL; //desconecta o ultimo
    free(atual);
    return aux; //retorna o inicio da lista
}

lista* buscar(lista *inicio, int busca) //buscando elemento
{
    lista *atual = inicio;
    while (atual != NULL)
    {
        if (atual -> info == busca)
        {
            return atual;
        }
        atual = atual -> prox;
    }
    return NULL;
}


void imprime(lista *aux) //imprime a lista
{
    if (aux == NULL)
    {
        printf("\nlista vazia!!\n");
    }
    else
    {
        printf("\nlista: ");
        while (aux != NULL)
        {
            printf("| %d |", aux -> info);
            aux = aux -> prox;
        }
    }
}

lista* apaga (lista *aux) //apaga lista inteira
{
    lista *aux2;
    while(aux != NULL)
    {
        aux2 = aux;
        aux = aux -> prox;
        free(aux2);
    }
    return aux;
}

int main()
{
    int op, num, removido, qt=0, qt_pares=0, qt_impares=0, soma=0;
    char in;
        lista *inicio;
        inicio = inicializa();
    do
    {
        system("cls");
        printf("\n\n------------ MENU -------------\n");
        printf("| 1. inserir valor no inicio  |\n"); //ok
        printf("| 2. remover valor do inicio  |\n"); //ok
        printf("| 3. inserir valor no final   |\n"); //ok
        printf("| 4. remover valor do final   |\n"); //ok
        printf("| 5. buscar valor             |\n"); //ok
        printf("| 6. imprimir                 |\n"); //ok
        printf("| 7. quantidade de elementos  |\n"); //ok
        printf("| 8. soma de elementos        |\n"); //ok
        printf("| 9. numero impares           |\n"); //ok
        printf("| 10. numeros pares           |\n"); //ok
        printf("| 11. sair                    |\n"); //ok
        printf("-------------------------------\n");
        printf("Escolha uma acao do menu: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: //inserir valor no inicio
            do
            {
                printf("Digite o valor para inserir: ");
                scanf("%d", &num);
                inicio = insereinicio(inicio, num);
                qt++;
                soma+=num;
                if(num%2==0)
                {
                    qt_pares++;
                }
                else
                {
                    qt_impares++;
                }
                printf("Inserir outro valor? [S/N]: ");
                scanf(" %c", &in);
            } while (in == 's' || in == 'S');
        break;
        case 2: //remover valor no inicio
            inicio = removeinicio(inicio, &removido);
            if (removido != -1)
            {
                soma -= removido;
            }
            if(removido%2==0)
                {
                    qt_pares--;
                }
                else
                {
                    qt_impares--;
                }
            qt--;
        break;
        case 3: //inserir valor no final
            do
            {
                printf("Digite o valor para inserir: ");
                scanf("%d", &num);
                inicio = inserefinal(inicio, num);
                qt++;
                soma+=num;
                if(num%2==0)
                {
                    qt_pares++;
                }
                else
                {
                    qt_impares++;
                }
                printf("Inserir outro valor? [S/N]: ");
                scanf(" %c", &in);
            } while (in == 's' || in == 'S');

        break;
        case 4: //remover valor no final
            inicio = removefinal(inicio, &removido);
            if (removido != -1)
            {
                soma -= removido;
            }
            if(removido%2==0)
                {
                    qt_pares--;
                }
            else
            {
                qt_impares--;
            }
            qt--;

        break;
        case 5: //buscar valor
            printf("Qual valor deseja buscar? ");
            scanf("%d", &num);
            lista *encontrado = buscar(inicio, num);
            if (encontrado != NULL)
            {
                printf("\nElemento encontrado  :)\n");
            }
            else
            {
                printf("\nElemento nao encontrado  :(\n");
            }
        break;
        case 6: //imprimir
            imprime(inicio);
        break;
        case 7: //quantidade de elementos
            printf("Quantidade de elementos: %d", qt);
        break;
        case 8: //somar elementos
            printf("Soma dos elementos: %d", soma);
        break;
        case 9: //numeros impares
            printf("Quantidade de números impares: %d", qt_impares);
        break;
        case 10: //numeros pares
            printf("Quantidade de números pares: %d", qt_pares);
        break;
        case 11: //sair
            inicio=apaga(inicio);
        break;
        }
    }while(op!=11);

    return 0;
}
