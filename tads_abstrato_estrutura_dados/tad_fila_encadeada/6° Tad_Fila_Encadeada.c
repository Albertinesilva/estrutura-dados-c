#include <stdio.h>
#include <stdlib.h>


typedef int TipoChave;


typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;

} Celula;

typedef struct
{
    Apontador Frente, Fundo;
    int Tamanho;

} TipoFila;


void Iniciar_Fila(TipoFila *Fila);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Imprimir_Fila(TipoFila Fila);

void main()
{

}

void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = (Apontador)malloc(sizeof(Celula));
    Fila->Fundo = Fila->Frente;
    Fila->Frente->Prox = NULL;
    Fila->Tamanho = 0;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Enfileirar_Fila(TipoItem x, TipoFila *Fila)
{
    Fila->Fundo->Prox = (Apontador)malloc(sizeof(Celula));
    Fila->Fundo = Fila->Fundo->Prox;
    Fila->Fundo->Item = x;
    Fila->Fundo->Prox = NULL;
    Fila->Tamanho = Fila->Tamanho + 1;
}

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item)
{
    Apontador Aux;

    if(Fila_Vazia(Fila))
    {
        printf("\n\tErro Fila Vazia!...\n");
        return;
    }
    else
    {
        Aux = Fila->Frente;
        Fila->Frente = Fila->Frente->Prox;
        *Item = Fila->Frente->Item;
        free(Aux);
        Fila->Tamanho = Fila->Tamanho - 1;
    }
}

void Imprimir_Fila(TipoFila Fila)
{
    Apontador Aux;
    Aux= Fila.Fundo->Prox;

    while(Aux != NULL)
    {
        printf("\n%d",Aux->Item.chave);

        Aux = Aux->Prox;
    }
}
