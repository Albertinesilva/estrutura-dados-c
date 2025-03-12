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

void Pares_Base_Impares_Topo(TipoPilha *Pilha);

void Imprimir_Pilha(TipoPilha Pilha);



void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;
    TipoItem x, Item;
    TipoChave chave;

    int Opcao = 0, Verificador = 0, i = 0;
    int Quant_Elementos = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Pilha(Opcao);

        switch (Opcao)
        {

        case 1:

            Inicia_Pilha(&Pilha);
            printf("\n\tPilha Inicializada!...\n\n");
            Verificador = 1;

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, pode Empilhar!...\n\n");

                    while(i != 5)
                    {
                        printf("\n\tInforme o %d° Elemento da Pilha: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x);

                        Empilhar_aPilha(x, &Pilha);
                        i++;
                    }

                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, não tem Elementos para Desempilhar!...\n\n");
                }
                else
                {
                    printf("\n\tDeseja Desempilhar Quantos Elementos: ");
                    fflush(stdin);
                    scanf("%d",Quant_Elementos);

                    for(int y = 0; y < Quant_Elementos; y++)
                    {
                        Desempilhar_aPilha(&Pilha, &Item);
                    }
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n");
            }

            break;

        case 4:

            Pares_Base_Impares_Topo(&Pilha);

            break;

        case 5:

            Imprimir_Pilha(Pilha);

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;
        }
    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\n\t-------------Pilha com Pares e Impares-------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Desempilhar a Pilha");
        printf("\n\t4 - Números Pares na Base e Impares no Topo");
        printf("\n\t5 - Imprimir Pilha");
        printf("\n\t6 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 6 || Opcao < 1);

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

void Pares_Base_Impares_Topo(TipoPilha *Pilha)
{
    TipoPilha Pares, Impares;
    TipoItem Item;

    Inicia_Pilha(&Pares);
    Inicia_Pilha(&Impares);

    while(!Pilha_Vazia(*Pilha) || Pilha->Topo != -1)
    {
        if(Pilha->Item[Pilha->Topo].chave % 2 == 0)
        {
            Desempilhar_aPilha(Pilha, &Item);
            Empilhar_aPilha(Item, &Pares);
        }
        else
        {
            Desempilhar_aPilha(Pilha, &Item);
            Empilhar_aPilha(Item, &Impares);
        }

    }

    printf("\n\n\t----------Pilha Par----------\n\n");

    Imprimir_Pilha(Pares);

    printf("\n\n\t---------Pilha Impar---------\n\n");

    Imprimir_Pilha(Impares);


    while(!Pilha_Vazia(Pares) || Pares.Topo != -1)
    {
        Desempilhar_aPilha(&Pares, &Item);
        Empilhar_aPilha(Item, Pilha);
    }

    while(!Pilha_Vazia(Impares) || Impares.Topo != -1)
    {
        Desempilhar_aPilha(&Impares, &Item);
        Empilhar_aPilha(Item, Pilha);
    }

    printf("\n\n\t-----------Pares na Base, Impares no Topo-----------\n\n");

    Imprimir_Pilha(*Pilha);

}

void Imprimir_Pilha(TipoPilha Pilha)
{
    int i = 0;

    for(i = 0; i <= Pilha.Topo; i++)
    {
        printf("\t");
        printf("%d,",Pilha.Item[i].chave);
    }
}
