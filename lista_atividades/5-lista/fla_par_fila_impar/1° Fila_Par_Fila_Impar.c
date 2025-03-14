#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define InicioVetor 1
#define MaxTam 6

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

int Menu_Fila(int Opcao);

void Iniciar_Fila(TipoFila *Fila_Par, TipoFila *Fila_Impar);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Imprimir_Fila(TipoFila Fila);

void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila_Par, Fila_Impar;
    TipoItem Item, x;

    int Opcao = 0, verificador = 0;
    bool verdadeiro = true;

    while(Opcao != 5)
    {
        Opcao = Menu_Fila(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila_Par, &Fila_Impar);

            printf("\n\tFila Par e Fila Ímpar Inicializadas!...\n");
            verificador = 1;

            break;

        case 2:

            if(verificador == 1)
            {

                if(Fila_Vazia(&Fila_Par) && Fila_Vazia(&Fila_Impar))
                {

                    do
                    {
                        printf("\n\tInforme um Elemento para a Fila: ");
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        if(x.chave % 2 == 0)
                        {
                            Enfileirar_Fila(x, &Fila_Par);
                        }
                        else
                        {
                            Enfileirar_Fila(x, &Fila_Impar);
                        }

                        if(Fila_Par.Fundo == MaxTam && Fila_Impar.Fundo == MaxTam)
                        {
                            verdadeiro = false;
                        }

                    }
                    while(verdadeiro);

                }
                else
                {
                    printf("\n\tExiste alguma fila Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tAs Filas não foram Inicializadas!...\n");
            }

            break;

        case 3:

            printf("\n\tDeseja Desinfileirar qual das Filas:\n\t1 - Fila Par\n\t2 - Fila Ímpar\n\tEntrada: ");
            fflush(stdin);
            scanf("%d",&Opcao);

            if(verificador == 1)
            {

                if(Opcao == 1)
                {
                    if(Fila_Vazia(&Fila_Par))
                    {
                        printf("\n\tA Fila Par esta Vazia!\n\n");
                    }
                    else
                    {
                        Desinfileirar_Fila(&Fila_Par, &Item);
                    }
                }
                if(Opcao == 2)
                {
                    if(Fila_Vazia(&Fila_Impar))
                    {
                        printf("\n\tA Fila Par esta Vazia!\n\n");
                    }
                    else
                    {
                        Desinfileirar_Fila(&Fila_Impar, &Item);
                    }
                }

            }
            else
            {
                printf("\n\tAs Filas não foram Inicializadas!...\n");
            }


            break;

        case 4:

            if(verificador == 1)
            {
                printf("\n\t----------Fila Par----------\n");
                Imprimir_Fila(Fila_Par);

                printf("\n\t----------Fila Impar----------\n");
                Imprimir_Fila(Fila_Impar);
            }
            else
            {
                printf("\n\tAs Filas não foram Inicializadas!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

        }
    }

}

int Menu_Fila(int Opcao)
{
    printf("\n\n\t------------Fila Par e Fila Impar------------\n");

    do
    {
        printf("\n\t1 - Iniciar a Fila");
        printf("\n\t2 - Fila Par e Fila Ímpar");
        printf("\n\t3 - Desinfileirar a Fila");
        printf("\n\t4 - Imprimir a Fila");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;

}

void Iniciar_Fila(TipoFila *Fila_Par, TipoFila *Fila_Impar)
{
    Fila_Par->Frente = InicioVetor;
    Fila_Par->Fundo = Fila_Par->Frente;

    Fila_Impar->Frente = InicioVetor;
    Fila_Impar->Fundo = Fila_Impar->Frente;
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
        printf("\n\t%d",Fila.Item[Aux].chave);
    }
}
