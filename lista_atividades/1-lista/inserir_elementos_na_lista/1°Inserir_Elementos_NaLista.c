#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define Inicio 0
#define TamMax 5

typedef int Tipochave;
typedef int Apontador;

typedef struct
{
    Tipochave Num;

} Tipoitem;

typedef struct
{
    Tipoitem itens[TamMax];
    Apontador Primeiro, Ultimo, Pos;

} TipoLista;

void Inicia_Lista(TipoLista *Lista);
int Lista_Vazia(TipoLista Lista);
int Insere_Lista(Tipoitem Elemento,TipoLista *Lista);
int Insere_Elemento_na_Posicao_Pos(Tipoitem Elemento,TipoLista *Lista);
void Imprime_Lista(TipoLista Lista);

int main()
{
    setlocale(LC_ALL,"portuguese");

    Tipoitem Elemento;
    TipoLista Lista;
    Inicia_Lista(&Lista);
    Lista_Vazia(Lista);


    Insere_Elemento_na_Posicao_Pos(Elemento,&Lista);
    Imprime_Lista(Lista);

    return 0;
}
void Inicia_Lista(TipoLista *Lista)
{
    Lista->Primeiro = Inicio;
    Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista)
{
    if(Lista.Primeiro == Lista.Ultimo)
    {
        printf("\nLista vazia!\n");
    }
}

int Insere_Elemento_na_Posicao_Pos(Tipoitem Elemento,TipoLista *Lista)
{
    int i=0;
    do
    {
        printf("\n\t%d° Elemento",i+1);
        printf("\n    Digite um Elemento: ");
        fflush(stdin);
        scanf("%d",&Elemento.Num);

        printf("    Digite a Posição POS: ");
        fflush(stdin);
        scanf("%d",&Lista->Pos);
        printf("\n");

        Insere_Lista(Elemento, Lista);
        i++;
    }
    while(i != TamMax);
}

int Insere_Lista(Tipoitem Elemento,TipoLista *Lista)
{
    TipoLista Lista1;
    if(Lista->Ultimo > TamMax -1)
    {
        printf("\nLista esta cheia!\n");
        return (0);
    }
    else
    {
        int x=0;
        for(int i = Lista->Ultimo; i > Lista->Pos - 1; i--,x++)
        {
            Lista->itens[Lista->Ultimo] = Lista->itens[Lista->Pos];
            Lista1.itens[x] = Lista->itens[Lista->Pos-1];
            Lista->itens[i] = Lista1.itens[x];
        }
    }
    Lista->itens[Lista->Pos - 1] = Elemento;
    Lista->Ultimo++;
}

void Imprime_Lista(TipoLista Lista)
{
    int i;
    for(i=Lista.Primeiro; i < Lista.Ultimo; i++)
    {
        printf("\n%d° Elemento = %d",i+1,Lista.itens[i].Num);
    }
    printf("\n");
}

