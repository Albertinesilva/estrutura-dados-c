#include <stdio.h>
#include <stdlib.h>

typedef    int   Tipochave;

typedef struct
{
    Tipochave chave;
} TipoItem;

Typedef    struct   TipoCelula   *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;
};

typedef struct
{
    Apontador Primeiro, Ultimo;
    int tamanho;
} TipoLista;

void Inicia(TipoLista *Lista);
int Vazia(TipoLista *Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Remove(Apontador p, TipoLista *Lista, TipoItem *Item);
void Imprime(TipoLista Lista);

int main()
{
  

  return 0;
}

int Vazia(TipoLista *Lista)
{
    return (Lista->Primeiro == Lista->Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
/*A inserção e feita a direita do ponteiro Ultimo*/
{
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->tamanho = Lista->tamanho + 1;
}

void Remove(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    /*obs: o item a ser retirado e o seguinte ao apontado por p*/
    Apontador pAux;
    if(Vazia(Lista) || p == NULL || p->Prox == NULL)
    {
        printf("Erro Lista vazia ou posição não existe!\n");
        return;
    }
    pAux = p->Prox;
    *Item = pAux->Item;
    p->Prox = pAux->Prox;

    if(p->Prox == NULL)
    {
        Lista->Ultimo = p;
        free(pAux);
        Lista->tamanho = Lista->tamanho - 1;
    }
}

void Imprime(TipoLista Lista)
{
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;
    while(Aux != NULL)
    {
        printf("%d\n",Aux->Item.chave);
        Aux = Aux->Prox;
    }
}
