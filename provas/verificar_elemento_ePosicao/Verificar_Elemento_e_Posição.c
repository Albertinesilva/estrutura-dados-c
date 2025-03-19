#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    Apontador Topo;

} TipoPilha;


int Menu_Pilha(int Opcao);

void Inicia_Pilha(TipoPilha *Pilha);

int Pilha_Vazia(TipoPilha Pilha);

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha);

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item);

void Verificar_Elemento_e_Posicao(TipoPilha *Pilha);

void Imprime_Pilha(TipoPilha Pilha);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;
    TipoItem x;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {
        case 1:

            Inicia_Pilha(&Pilha);
            Verificador = 1;
            printf("\n\tPilha Inicializada com Sucesso!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {

                if(Pilha_Vazia(Pilha))
                {

                    do
                    {
                        printf("\n\tInforme os elementos para a Pilha:  ");
                        fflush(stdin);
                        scanf("%d",&x);
                        system("cls");

                        Empilhar_aPilha(x, &Pilha);

                    }
                    while(Pilha.Topo != MaxTam - 1);

                }
                else
                {
                    printf("\n\tA Pilha esta Cheia!...\n");
                }

            }
            else
            {
                printf("\n\tA pilha não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {

                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha esta Vazia!...\n");
                }
                else
                {
                    Verificar_Elemento_e_Posicao(&Pilha);
                }

            }
            else
            {
                printf("\n\tA pilha não foi Inicializada!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {

                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha esta Vazia!...\n");
                }
                else
                {
                    Imprime_Pilha(Pilha);
                }

            }
            else
            {
                printf("\n\tA pilha não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");
        }
    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t----------Pilha: Verificar Elemento e Posição----------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Pilha");
        printf("\n\t[2] - Empilhar a Pilha");
        printf("\n\t[3] - Verificar Elemento e Posição");
        printf("\n\t[4] - Imprimir a Pilha");
        printf("\n\t[5] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");
    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;
}

void Inicia_Pilha(TipoPilha *Pilha)
{
    Pilha->Topo = - 1;
}

int Pilha_Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == - 1);
}

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha)
{
    if(Pilha->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo] = x;
    }
}

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item)
{
    if(Pilha_Vazia(*Pilha))
    {
        printf("\n\tErro pilha esta vazia\n");
    }
    else
    {
        *Item = Pilha->Item[Pilha->Topo];
        Pilha->Topo--;
    }
}

void Verificar_Elemento_e_Posicao(TipoPilha *Pilha)
{
    TipoPilha Aux;
    TipoItem Item;
    int Elemento = 0, Quant_Elementos = 0, i = 0;
    int Posicao[5];

    Inicia_Pilha(&Aux);

     Imprime_Pilha(*Pilha);

    printf("\n\n\tInforme o elemento que deseja verificar na Pilha:  ");
    fflush(stdin);
    scanf("%d",&Elemento);
    system("cls");

    while(!Pilha_Vazia(*Pilha))
    {
        Desempilhar_aPilha(Pilha, &Item);

        Empilhar_aPilha(Item, &Aux);

        i++;

        if(Item.chave == Elemento)
        {
            Posicao[Quant_Elementos] = i;
            Quant_Elementos++;
        }

    }

     if(Quant_Elementos >= 1)
     {
        printf("\n\tElemento %d Localizado na Posição",Elemento);

        for(i = 0; i < Quant_Elementos; i++)
        {
            printf(", %d ",Posicao[i]);
        }

     }
      printf("\n\tQuantidade de evidencias do elemento: %d\n",Quant_Elementos);

    while(!Pilha_Vazia(Aux))
    {
        Desempilhar_aPilha(&Aux, &Item);

        Empilhar_aPilha(Item, Pilha);
    }

}

void Imprime_Pilha(TipoPilha Pilha)
{
    printf("\n\t----------Pilha sem o Maior Elemento e Invertida----------\n");

    int Aux;

    for(Aux = Pilha.Topo; Aux > -1; Aux--)
    {
        printf("\n\t%d", Pilha.Item[Aux].chave);
    }
    printf("\n\t----------------------------------------------------------\n");
}
