#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 1
#define MaxTam 7

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

void Iniciar_Fila(TipoFila *Fila, TipoFila *Fila_Par, TipoFila *Fila_Impar);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Dividir_aFila_EmDuas_Par_e_Impar(TipoFila *Fila, TipoFila *Fila_Par, TipoFila *Fila_Impar);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Imprimir_Fila(TipoFila Fila);

void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila, Fila_Par, Fila_Impar;
    TipoItem Item, x;

    int Opcao = 0, verificador = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Fila(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila, &Fila_Par, &Fila_Impar);
            verificador = 1;
            printf("\n\tFila Inicializada!...\n");

            break;

        case 2:

            if(verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    while(Fila.Fundo != MaxTam)
                    {
                        printf("\n\tInforme o %d Elemento da Fila: ",Fila.Fundo);
                        fflush(stdin);
                        scanf("%d",&x);

                        Enfileirar_Fila(x, &Fila);
                    }
                }
                else
                {
                    printf("\n\tFila Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA Fila não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Matriz Vazia!...\n");
                }
                else
                {
                    Dividir_aFila_EmDuas_Par_e_Impar(&Fila, &Fila_Par, &Fila_Impar);
                }
            }
            else
            {
                printf("\n\tAs Filas não foram Inicializadas!...\n");
            }

            break;

        case 4:

        do
        {

            printf("\n\tQual Fila deseja Desinfileirar:\n\n\t1 - Fila Matriz\n\t2 - Fila Par\n\t3 - Fila Impar\n\t0 - Sair\n\tEntrada: ");
            fflush(stdin);
            scanf("%d",&Opcao);
            system("cls");

            if(verificador == 1)
            {
                if(Opcao == 1)
                {

                    if(Fila_Vazia(&Fila))
                    {
                        printf("\n\tFila Matriz Vazia!...\n");
                    }
                    else
                    {
                        Desinfileirar_Fila(&Fila, &Item);
                        printf("\n\t%d Desinfileirado com Sucesso!...\n",Item.chave);
                    }

                }
                else
                {
                    if(Opcao == 2)
                    {
                        if(Fila_Vazia(&Fila_Par))
                        {
                            printf("\n\tFila Par Vazia!...\n");
                        }
                        else
                        {
                            Desinfileirar_Fila(&Fila_Par, &Item);
                            printf("\n\t%d Desinfileirado com Sucesso!...\n",Item.chave);
                        }
                    }
                    else
                    {
                        if(Opcao == 3)
                        {
                            if(Fila_Vazia(&Fila_Impar))
                            {
                                printf("\n\tFila Impar Vazia!...\n");
                            }
                            else
                            {
                                Desinfileirar_Fila(&Fila_Impar, &Item);
                                printf("\n\t%d Desinfileirado com Sucesso!...\n",Item.chave);
                            }
                        }
                    }
                }
            }
            else
            {
                printf("\n\tAs Filas não foram Inicializada!...\n");
            }

            if(Opcao == 0)
            {
                printf("\n\tMetodo Desinfileiramento Finalizado!...\n");
            }
        }
        while(Opcao != 0);

            break;

        case 5:

            if(verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Matriz Vazia!...\n");
                }
                else
                {
                    Imprimir_Fila(Fila);
                }

                if(Fila_Vazia(&Fila_Par))
                {
                    printf("\n\tFila Par Vazia!...\n");
                }
                else
                {
                    printf("\n\t----------Fila Par----------\n");

                    Imprimir_Fila(Fila_Par);
                }

                if(Fila_Vazia(&Fila_Impar))
                {
                    printf("\n\tFila Impar Vazia!...\n");
                }
                else
                {
                    printf("\n\t----------Fila Impar--------\n");

                    Imprimir_Fila(Fila_Impar);
                }
            }
            else
            {
                printf("\n\tAs Filas não foram Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

        }
    }

}

int Menu_Fila(int Opcao)
{
    printf("\n\n\t----------Dividir uma Fila em duas Par/Impar----------\n\n");

    do
    {
        printf("\n\t1 - Iniciar a Fila");
        printf("\n\t2 - Enfileirar a Fila");
        printf("\n\t3 - Dividir a Fila em duas: Par/Impar");
        printf("\n\t4 - Desinfileirar as Filas");
        printf("\n\t5 - Imprimir Filas");
        printf("\n\t6 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 6 || Opcao < 1 );

    return Opcao;
}

void Iniciar_Fila(TipoFila *Fila, TipoFila *Fila_Par, TipoFila *Fila_Impar)
{
    Fila->Frente = InicioVetor;
    Fila->Fundo = Fila->Frente;

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

void Dividir_aFila_EmDuas_Par_e_Impar(TipoFila *Fila, TipoFila *Fila_Par, TipoFila *Fila_Impar)
{
    TipoItem Item;
    int Aux = Fila->Frente - 1;

    while(Aux < Fila->Fundo - 1)
    {
        Desinfileirar_Fila(Fila, &Item);

        if(Fila->Item[Aux].chave % 2 == 0)
        {
            Enfileirar_Fila(Item, Fila_Par);
        }
        else
        {
            Enfileirar_Fila(Item, Fila_Impar);
        }
        Aux++;
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
