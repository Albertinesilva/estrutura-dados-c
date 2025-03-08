#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define inicio 0
#define TamMax 5

typedef int TipoChave;
typedef int Apontador;

typedef struct
{
    TipoChave Num1,Num2,Num22,Num3;;

} TipoItem;

typedef struct
{
    TipoItem itens[TamMax];
    Apontador Primeiro, Ultimo;

} TipoLista;

void Iniciar_Lista(TipoLista *L1);

int Lista_Vazia(TipoLista L1);

int Insere_Lista(TipoItem x1,TipoItem x2, TipoLista *L1, TipoLista *L2);

void ImprimeLista(TipoLista L1, TipoLista L2, TipoLista L3);

void Verifica_se_EstaOrdenado(TipoLista L1);

void Verifica_sea_Lista_L1eL2e_Igual(TipoLista L1, TipoLista L2);

void Inverte_L1_Colocando_Em_L2(TipoLista L1,TipoLista L2);

void Intercala_L1ComL2_Ordenados_Gerando_L3(TipoLista *L1,TipoLista L2,TipoLista *L3);

int Retira_Lista(Apontador p, TipoLista *L1, TipoItem *Item);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    TipoLista L1,L2,L3;
    TipoItem Lista1,Lista2,Lista3,Lista1_Eliminado;

    Iniciar_Lista(&L1);
    Iniciar_Lista(&L2);
    Iniciar_Lista(&L3);
    Lista_Vazia(L1);

    for(int i=0; i < TamMax; i++)
    {
        printf("\n----------%d° Elemento----------\n",i+1);
        printf("\nInforme os Elementos de L1: ");
        fflush(stdin);
        scanf("%d",&Lista1.Num1);
        Lista2.Num22 = Lista1.Num1;

        printf("\nInforme os Elementos de L2: ");
        fflush(stdin);
        scanf("%d",&Lista2.Num2);
        system("cls");

        Insere_Lista(Lista1,Lista2,&L1,&L2);
    }
    ImprimeLista(L1,L2,L3);

    Intercala_L1ComL2_Ordenados_Gerando_L3(&L1,L2,&L3);
    printf("\n-------------------------Lista L1 Excluida-------------------------\n");
    int i=0;
    do
    {
        i++;
        Retira_Lista(i,&L1, &Lista1_Eliminado);
        printf("%d, Foi excluido!\n",Lista1_Eliminado.Num1);
    }
    while(i < TamMax);
    return 0;
}

void Iniciar_Lista(TipoLista *L1)
{
    L1->Primeiro = inicio;
    L1->Ultimo = L1->Primeiro;

    /*L2->Primeiro = inicio;
    L2->Ultimo = L2->Primeiro;

    L3->Primeiro = inicio;
    L3->Ultimo = L3->Primeiro;*/
}

int Lista_Vazia(TipoLista L1)
{
    return L1.Primeiro == L1.Ultimo;
}

int Insere_Lista(TipoItem x1,TipoItem x2, TipoLista *L1, TipoLista *L2)
{
    if(L1->Ultimo > TamMax -1 || L2->Ultimo > TamMax -1)
    {
        return (0);
    }
    else
    {
        L1->itens[L1->Ultimo] = x1;
        L1->Ultimo++;

        L2->itens[L2->Ultimo] = x2;
        L2->Ultimo++;
    }
}

void ImprimeLista(TipoLista L1, TipoLista L2,TipoLista L3)
{
    printf("\n------------------------------Lista L1----------------------------\n\n");
    for(int i = 0; i < L1.Ultimo; i++)
    {
        printf("%d,",L1.itens[i].Num1);
    }
    Verifica_se_EstaOrdenado(L1);

    printf("\n------------------------------Lista L2----------------------------\n\n");
    for(int i = 0; i < L2.Ultimo; i++)
    {
        printf("%d,",L2.itens[i].Num2);
    }
    Verifica_sea_Lista_L1eL2e_Igual(L1,L2);

    printf("\n---------------------Cópia da Lista L1 Para L2--------------------\n\n");
    for(int i = 0; i < L2.Ultimo; i++)
    {
        printf("%d,",L2.itens[i].Num22);
    }
    printf("\n\n----------------L1 Invertido e Colocado em L2---------------------\n\n");
    Inverte_L1_Colocando_Em_L2(L1,L2);

    printf("\n\n------------L1 com L2 Ordenados, Intercalados Gerando L3-----------\n");

    Intercala_L1ComL2_Ordenados_Gerando_L3(&L1,L2,&L3);
    for(int i = 0; i < (L1.Ultimo + L2.Ultimo); i++)
    {
        printf("%d,",L3.itens[i].Num3);
    }
}

void Verifica_se_EstaOrdenado(TipoLista L1)
{
    int x = 0,y = 1;
    int crescente = 0,decrescente = 0;

    for(int i = 0; i < L1.Ultimo; i++, x++, y++)
    {
        if(L1.itens[i].Num1 <= L1.itens[x+1].Num1)
        {
            crescente++;
        }
        else
        {
            if(L1.itens[i].Num1 >= L1.itens[y].Num1)
            {
                decrescente++;
            }
        }
    }
    if(crescente == 4)
    {
        printf("\n\nEsta ordenado de forma crescente!\n");
    }
    else
    {
        if(decrescente == 5)
        {
            printf("\n\nEsta ordenado de forma decrescente!\n");
        }
        else
        {
            printf("\n\nNão está nem crescente e nem decrescente!\n");
        }
    }
}

void Verifica_sea_Lista_L1eL2e_Igual(TipoLista L1, TipoLista L2)
{
    int Igual=0;
    for(int i = 0; i < TamMax; i++)
    {
        if(L1.itens[i].Num1 == L2.itens[i].Num2)
        {
            Igual++;
        }
    }
    if(Igual == 5)
    {
        printf("\n\nA lista L1 é igual a Lista L2!\n");
    }
    else
    {
        printf("\n\nA Lista L1 não é igual a Lista L2!\n");
    }
}
void Inverte_L1_Colocando_Em_L2(TipoLista L1,TipoLista L2)
{
    int x = L1.Ultimo;
    for(int i = 0; i < TamMax; i++)
    {
        L2.itens[i].Num2 = L1.itens[x-1].Num1;
        x--;
    }
    for(int i = 0; i < TamMax; i++)
    {
        printf("%d,",L2.itens[i].Num2);

    }

}

void Intercala_L1ComL2_Ordenados_Gerando_L3(TipoLista *L1,TipoLista L2, TipoLista *L3)
{
    int i,j,aux;
    for(i = L1->Primeiro; i < L1->Ultimo; i++)
    {
        for(j = i + 1; j < L1->Ultimo; j++)
        {
            if(L1->itens[i].Num1 > L1->itens[j].Num1)
            {
                aux = L1->itens[i].Num1;
                L1->itens[i].Num1 = L1->itens[j].Num1;
                L1->itens[j].Num1 = aux;
            }
        }
    }
    for(i = L2.Primeiro; i < L2.Ultimo; i++)
    {
        for(j = i + 1; j < L2.Ultimo; j++)
        {
            if(L2.itens[i].Num2 > L2.itens[j].Num2)
            {
                aux = L2.itens[i].Num2;
                L2.itens[i].Num2 = L2.itens[j].Num2;
                L2.itens[j].Num2 = aux;
            }
        }
    }
    int x=0,y=0;
    for(i = 0; i < (L1->Ultimo + L2.Ultimo); i++)
    {
        if(i%2==0)
        {
            L3->itens[i].Num3 = L1->itens[y].Num1;
            y++;
        }
        else
        {
            L3->itens[i].Num3 = L2.itens[x].Num2;
            x++;
        }
    }
    printf("\n");
}
int Retira_Lista(Apontador p, TipoLista *L1, TipoItem *Item)
{
    int Aux=0;
    if(Lista_Vazia(*L1) && p - 1  <= L1->Ultimo)
    {
        return (0);
    }
    *Item = L1->itens[p - 1];
    for(Aux = p; Aux < L1->Ultimo; Aux++)
    {
        L1->itens[Aux = -1] = L1->itens[Aux];
        L1->Ultimo--;
    }
}
