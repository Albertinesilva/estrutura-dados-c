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

void Empilhar_aPilha(int x, TipoPilha *Pilha);

void Imprime_Pilha(TipoPilha Pilha);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;

    int Num = 0, Aux = 0;
    int Opcao = 0, verificador = 0;

    while(Opcao != 4)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {

        case 1:

            Inicia_Pilha(&Pilha);
            verificador = 1;

            printf("\n\tPilha e Lista Inicializadas!...\n\n");

            break;

        case 2 :

            if(verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {

                    printf("\n\tPilha Vazia, pode inserir elementos!...\n\n");

                    printf("\n\tInforme um número positivo em formato decimal, para transformar em binário:  ");
                    fflush(stdin);
                    scanf("%d",&Num);
                    system("cls");

                    while(Num > 0)
                    {
                        Aux = Num % 2;

                        Empilhar_aPilha(Aux, &Pilha);

                        Num = Num/2;
                    }

                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 3:

            if(verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tPilha Vazia!...\n");
                }
                else
                {
                    Imprime_Pilha(Pilha);
                }

            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;
        }

    }
}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t--------Transferir Elementos para Pilha 2--------\n\n");

    do
    {
        printf("\n\t1 - Iniciar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Imprimir a Pilha em formato Binário");
        printf("\n\t4 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 4 || Opcao < 1);

}

void Inicia_Pilha(TipoPilha *Pilha)
{
    Pilha->Topo = - 1;
}

int Pilha_Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == - 1);
}

void Empilhar_aPilha(int x, TipoPilha *Pilha)
{
    if(Pilha->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo].chave = x;
    }
}

void Imprime_Pilha(TipoPilha Pilha)
{
    printf("\n\t-------------Pilha no Formato Binário----------\n");

    int Aux;

    for(Aux = Pilha.Topo; Aux > -1; Aux--)
    {
        printf("\n\t%d", Pilha.Item[Aux].chave);
    }
    printf("\n\t-----------------------------------------------\n");
}

