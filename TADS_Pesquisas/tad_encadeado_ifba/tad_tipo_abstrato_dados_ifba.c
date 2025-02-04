#include <stdio.h>
#include <stdlib.h>
#define InicioVetor 0
#define Maxtam 100

typedef int Tipochave;
typedef int Apontador;

typedef struct
{
    Tipochave chave;
} TipoItem;

typedef struct
{
    TipoItem itens[Maxtam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void Iniciar_Lista(TipoLista *Lista);
int Insere_Lista(TipoItem x,TipoLista *Lista);
int Lista_Vazia(TipoLista Lista);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);
void ImprimeLista(TipoLista Lista);

int main()
{
    TipoLista ListaTeste;
    Iniciar_Lista(&ListaTeste);

    TipoItem a,b,c,d,r;
    a.chave = 10;
    b.chave = 11;
    c.chave = 50;
    d.chave = 45;

    Insere_Lista(a, &ListaTeste);
    Insere_Lista(b, &ListaTeste);
    Insere_Lista(c, &ListaTeste);
    Insere_Lista(d, &ListaTeste);

    d.chave = 5;
    Insere_Lista(d, &ListaTeste);
    ImprimeLista(ListaTeste);
    Insere_Lista(a, &ListaTeste);
    ImprimeLista(ListaTeste);

    Retira_Lista(0,&ListaTeste, &r);
    ImprimeLista(ListaTeste);

    printf("\n%d Foi excluido!\n",r.chave);


    system("pause");
    return 0;
}
void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista)
{
    return   Lista.Primeiro == Lista.Ultimo;
}

int Insere_Lista(TipoItem x, TipoLista *Lista)
{
    if(Lista->Ultimo > Maxtam -1)
    {
        return (0);
    }
    else
    {
        Lista->itens[Lista->Ultimo] = x;
        Lista->Ultimo++;

        return(1);
    }
}


void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return;
    }
    *Item = Lista->itens[p-1];
    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->itens[Aux -1] = Lista->itens[Aux];
        Lista->Ultimo--;
    }
}


void ImprimeLista(TipoLista Lista)
{
    int Aux;
    printf("//****Lista****//\n");
    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("%d\n", Lista.itens[Aux].chave);
    }
}
