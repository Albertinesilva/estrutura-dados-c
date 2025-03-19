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

void Retirar_Maior_Elemento_e_Inverter_aPilha(TipoPilha *Pilha);

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
                    Retirar_Maior_Elemento_e_Inverter_aPilha(&Pilha);
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
    printf("\n\n\t----------Pilha: Retirar Maior Elemento e Inverter----------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Pilha");
        printf("\n\t[2] - Empilhar a Pilha");
        printf("\n\t[3] - Retirar Maior Elemento e Inverter a Pilha");
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

void Retirar_Maior_Elemento_e_Inverter_aPilha(TipoPilha *Pilha)
{
    TipoPilha Aux, Aux2;
    TipoItem Item;
    int Maior = 0, Menor = 0;
    float Soma = 0, Media = 0;

    Menor = Pilha->Item[Pilha->Topo].chave;

    Inicia_Pilha(&Aux);
    Inicia_Pilha(&Aux2);

    while(!Pilha_Vazia(*Pilha))
    {
        Desempilhar_aPilha(Pilha, &Item);

        Empilhar_aPilha(Item, &Aux);

        if(Item.chave > Maior)
        {
            Maior = Item.chave;
        }

        if(Item.chave < Menor)
        {
            Menor = Item.chave;
        }

        Soma += Pilha->Item[Pilha->Topo].chave;

    }

    Media = Soma / (Aux.Topo + 1);

    while(!Pilha_Vazia(Aux))
    {
        Desempilhar_aPilha(&Aux, &Item);

        if(Item.chave != Maior)
        {
            Empilhar_aPilha(Item, &Aux2);
        }

    }

    while(!Pilha_Vazia(Aux2))
    {
        Desempilhar_aPilha(&Aux2, &Item);

        Empilhar_aPilha(Item, Pilha);
    }

    Imprime_Pilha(*Pilha);

    printf("\n\tMaior Elemento da Pilha: %d\n\tMenor Elemento da Pilha: %d\n\tSoma dos Elementos %.2f\n\tMédia dos Elementos: %.2f\n\n",Maior,Menor,Soma,Media);

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
