#include <stdio.h>
#include <stdlib.h>


typedef int TipoChave;

typedef struct
{
    TipoChave chave;


}TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;

}Celula;

typedef struct
{
    Apontador Fundo, Topo;
    int Tamanho;

}TipoPilha;


void Inicia_Pilha(TipoPilha *Pilha);

int Pilha_Vazia(TipoPilha Pilha);

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha);

void Desempilha_Pilha(TipoPilha *Pilha, TipoItem *Item);


void main()
{

}

void Inicia_Pilha(TipoPilha *Pilha)
{
    Pilha->Topo = (Apontador)malloc(sizeof(Celula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Pilha_Vazia(TipoPilha Pilha)
{
    return(Pilha.Topo == Pilha.Fundo);
}

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha)
{
    Apontador Aux;
    Aux = (Apontador)malloc(sizeof(Celula));
    Pilha->Topo->Item = x;
    Aux->Prox = Pilha->Topo;
    Pilha->Topo = Aux;
    Pilha->Tamanho++;
}

void Desempilha_Pilha(TipoPilha *Pilha, TipoItem *Item)
{
    Apontador Aux;

    if(Pilha_Vazia(*Pilha))
    {
        printf("\n\tErro: Lista Vazia!...\n");
        return;
    }
    Aux = Pilha->Topo;
    Pilha->Topo = Aux->Prox;
    *Item = Aux->Prox->Item;
    free(Aux);
    Pilha->Tamanho--;
}

