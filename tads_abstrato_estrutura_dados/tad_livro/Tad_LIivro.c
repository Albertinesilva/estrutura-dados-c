#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista
{
    int info;
    struct lista* Prox;
};

typedef struct lista Lista;

/*Fun��o de cria��o: Retorna uma lista vazia*/
Lista* lst_Cria(void)
{
    return NULL;
}

/*inser��o no inicio: retorna a lista atualizada*/
Lista* lst_Insere (Lista* l, int i)
{
    Lista* Novo = (Lista*)malloc(sizeof(Lista));
    Novo->info = i;
    Novo->Prox = l;
    return Novo;
}

/*Inser��o no in�cio: atualiza valor da lista*/
void lst_insere (Lista** l, int i)
{
    Lista* Novo = (Lista*)malloc(sizeof(Lista));
    Novo->info = i;
    Novo->Prox = *l;
    *l = Novo;
}

/*Fun��o imprime: Imprime valores dos elementos*/
void lst_Imprime(Lista* l)
{
    Lista* p; /*Variavel auxiliar para percorrer a lista*/

    for(p = l; p != NULL; p = p->Prox)
    {
        printf("\ninfo = %d,",p->info);
    }
}

/*Fun��o vazia:retorna 1 se vazia ou 0 se n�o vazia*/
int lst_Vazia(Lista* l)
{
    return (l == NULL);
}

/*Fun��o busca: busca um elemento na lista*/
Lista* lst_Busca(Lista* l, int v)
{
    Lista* p;
    for(p = l; p != NULL; p = p->Prox)
    {
        if(p->info == v)
        {
            return p;
        }
    }
    return NULL; /*N�o achou o elemento.*/
}

/*Fun��o retira: retira elemento da lista*/
Lista* lst_Retira (Lista* l, int v)
{
    Lista* ant = NULL; /*Ponteiro para elemento anterior*/
    Lista* p = l;     /*Ponteiro para percorrer a lista*/

    /*Procurar elemento na lista, guardando anterior*/
    while(p != NULL && p->info != v)
    {
        ant = p;
        p = p->Prox;
    }

    /*verifica se achou elemento*/
    if(p == NULL)
    {
        return l; /*N�o achou retorna lista horiginal*/
    }

    /*Retira elemento*/
    if(ant == NULL)
    {
        /*Retira elemento no inicio*/
        l = p->Prox;
    }
    else
    {
        /*retira elemento no meio da lista*/
        ant->Prox = p->Prox;
    }
    free(p);
    return l;
}

void lst_Libera(Lista* l)
{
    Lista* p = l;
    while(p != NULL)
    {
        Lista* t = p->Prox;   /*Guarda refer�ncia p / Prox. Elemento*/
        free(p);              /*Libera a mem�ria apontada por p*/
        p = t;                /*Faz p apontar para o proximo*/
    }
}

/*Fun��o Insere_Ordenado: Insere elemento em ordem*/
Lista* lst_Insere_ordenado(Lista* l, int v)
{
    Lista* Novo;
    Lista* Ant = NULL; /*Ponteiro para elemento anterior*/
    Lista* p = l;

    /*Procura posi��o de inser��o*/
    while(p != NULL && p->info < v)
    {
        Ant = p;
        p = p->Prox;
    }

    /*cria novo elemento*/
    Novo = (Lista*)malloc(sizeof(Lista));
    Novo->info = v;

    /*Encadeia elemento*/
    if(Ant == NULL)
    {
        /*Insere elemento no in�cio*/
        Novo->Prox = l;
        l = Novo;
    }
    else
    {
        /*Insere elemento no meio da lista*/
        Novo->Prox = Ant->Prox;
        Ant->Prox = Novo;
    }
    return l;
}

void main()
{
    Lista* l; //Declara uma lista N�o inicializada.

    l = lst_Cria(); //Inicia a lista vazia.

    l = lst_Insere(l, 23);
    l = lst_Insere(l, 45);
    l = lst_Insere(l, 56);
    l = lst_Insere(l, 78);
    lst_Imprime(l);
    printf("\n");
    l = lst_Retira(l, 78);
    lst_Imprime(l);
    printf("\n");
    l = lst_Retira(l, 45);
    printf("\n");
    lst_Imprime(l);
    lst_Libera(l);

}
