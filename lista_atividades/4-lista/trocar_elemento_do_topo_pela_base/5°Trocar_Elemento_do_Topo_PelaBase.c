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

void Troca_Base_Pelo_Topo(TipoPilha *Pilha, TipoItem Item);

void Imprime_Pilha(TipoPilha Pilha);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;
    TipoItem x, Item;

    int Opcao = 0, Iniciou = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {

        case 1:

            Inicia_Pilha(&Pilha);
            Iniciou = Opcao;

            printf("\n\tPilha Inicializada com Sucesso!...\n\n");

            break;

        case 2:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    while(Pilha.Topo != MaxTam - 1)
                    {
                        printf("\n\tDigite o %d° Elemento da Pilha: ",Pilha.Topo + 2);
                        fflush(stdin);
                        scanf("%d",&x);

                        Empilhar_aPilha(x, &Pilha);
                    }
                }
                else
                {
                    printf("\n\tPilha Cheia!...\n\n");
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 3:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tPilha Vazia!...\n\n");
                }
                else
                {
                    Troca_Base_Pelo_Topo(&Pilha, Item);
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 4:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tPilha Vazia!...\n\n");
                }
                else
                {
                    printf("\n\t----------Pilha, Antes de Trocar Base pelo Topo----------\n\n");

                    Imprime_Pilha(Pilha);
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\n");
        }
    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t----------Pilha/Trocar Base Pelo Topo----------\n\n");

    do
    {
        printf("\n\t1 - Inicializar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Trocar a Base pelo Topo");
        printf("\n\t4 - Imprimir Pilha");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
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

void Troca_Base_Pelo_Topo(TipoPilha *Pilha, TipoItem Item)
{
    TipoPilha Aux;
    Inicia_Pilha(&Aux);


    printf("\n\t************************Pilha Matriz*************************\n\n");

    Imprime_Pilha(*Pilha);


    int i = Pilha->Topo;
    i--;
    while (Pilha->Topo > i)
    {
        Desempilhar_aPilha(Pilha, &Item);
        i++;
        Aux.Item[i] = Item;

        while (!Pilha_Vazia(*Pilha))
        {
            Desempilhar_aPilha(Pilha, &Item);
            Empilhar_aPilha(Item, &Aux);

            if(Pilha_Vazia(*Pilha))
            {
                Empilhar_aPilha(Aux.Item[i], Pilha);

                break;
            }
        }
    }

    i = Aux.Topo;
    i--;
    while (Aux.Topo > i)
    {
        Desempilhar_aPilha(&Aux, &Item);
        i++;

        while (!Pilha_Vazia(Aux))
        {
            Desempilhar_aPilha(&Aux, &Item);
            Empilhar_aPilha(Item, Pilha);

            if(Pilha_Vazia(Aux))
            {
                Empilhar_aPilha(Aux.Item[i], Pilha);

                break;
            }
        }

    }

    printf("\n\t**********Pilha, Troca de Elementos: Base pelo Topo**********\n\n");

    Imprime_Pilha(*Pilha);

}

void Imprime_Pilha(TipoPilha Pilha)
{

    int Aux;

    for(Aux = Pilha.Topo; Aux > -1; Aux--)
    {
        printf("\n\t%d", Pilha.Item[Aux].chave);
    }
    printf("\n\n");
}

