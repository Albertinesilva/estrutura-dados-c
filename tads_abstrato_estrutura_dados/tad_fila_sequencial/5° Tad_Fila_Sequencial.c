#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 1
#define MaxTam 5

typedef int Apontador;
typedef int TipoChave;


typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Frente, Fundo;

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
    Fila->Frente = InicioVetor;
    Fila->Fundo = Fila->Frente;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Enfileirar_Fila(TipoItem x, TipoFila *Fila)
{
    if(Fila->Frente == (Fila->Fundo % MaxTam + 1))
    {
        printf("\n\tErro, Fila esta Cheia!...\n");
    }
    else
    {
        Fila->Item[Fila->Fundo - 1] = x;
        Fila->Fundo = (Fila->Fundo % MaxTam) + 1;
    }
}

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item)
{
    if(Fila_Vazia(Fila))
    {
        printf("\n\tErro, Fila esta Vazia!...\n");
    }
    else
    {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = (Fila->Frente % MaxTam) + 1;
    }
}

void Imprimir_Fila(TipoFila Fila)
{
  int Aux = 0;

  for(Aux = Fila.Frente - 1; Aux < Fila.Fundo - 1; Aux++)
  {
      printf("\n%d",Fila.Item[Aux].chave);
  }
}
