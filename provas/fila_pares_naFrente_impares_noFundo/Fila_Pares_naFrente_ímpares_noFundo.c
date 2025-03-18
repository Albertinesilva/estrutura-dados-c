#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioFila 1
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

} TipoFila, TipoLista;


int Menu_Fila(int Opcao);

void Iniciar_Fila(TipoFila *Fila);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Pares_naFrente_Impares_noFundo(TipoFila *Fila);

void Imprimir_Fila(TipoFila Fila);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila;
    TipoItem x;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Fila(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila);
            Verificador = 1;

            printf("\n\tFila Inicializada com sucesso!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    do
                    {
                        printf("\n\tInforme um elemento para a Fila:  ");
                        fflush(stdin);
                        scanf("%d",&x);
                        system("cls");

                        Enfileirar_Fila(x, &Fila);

                    }
                    while(Fila.Fundo != MaxTam);
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

            Pares_naFrente_Impares_noFundo(&Fila);

            break;

        case 4:

            Imprimir_Fila(Fila);

            break;

        default:

            printf("\n\tPrograma Finalizado com sucesso!...\n");

        }
    }

}

int Menu_Fila(int Opcao)
{
    printf("\n\n\t---------Lista: Pares na Frente, Ímpares no Fundo---------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Fila");
        printf("\n\t[2] - Enfileirar  a Fila");
        printf("\n\t[3] - Colocar Pares na Frente, Ímpares no Fundo");
        printf("\n\t[4] - Imprimir Fila");
        printf("\n\t[5] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;
}

void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = InicioFila;
    Fila->Fundo = Fila->Frente;
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

void Pares_naFrente_Impares_noFundo(TipoFila *Fila)
{
    TipoFila Aux_Par;
    TipoFila Aux_Impar;
    TipoItem Item;

    Iniciar_Fila(&Aux_Par);
    Iniciar_Fila(&Aux_Impar);

    while(!Fila_Vazia(Fila))
    {
        if(Fila->Item[Fila->Fundo].chave % 2 == 0)
        {
            Desinfileirar_Fila(Fila, &Item);

            Enfileirar_Fila(Item, &Aux_Par);
        }
        else
        {
            Desinfileirar_Fila(Fila, &Item);

            Enfileirar_Fila(Item, &Aux_Impar);
        }
    }

    Iniciar_Fila(Fila);

    while(!Fila_Vazia(&Aux_Par))
    {
        Desinfileirar_Fila(&Aux_Par, &Item);

        Enfileirar_Fila(Item, Fila);

    }

    while(!Fila_Vazia(&Aux_Impar))
    {
        Desinfileirar_Fila(&Aux_Impar, &Item);

        Enfileirar_Fila(Item, Fila);
    }

    Imprimir_Fila(*Fila);

}

void Imprimir_Fila(TipoFila Fila)
{
    printf("\n\t--------------Pares na Frente Ímpares no Fundo------------\n\n");

    int Aux = 0;

    for(Aux = Fila.Frente - 1; Aux < Fila.Fundo - 1; Aux++)
    {
        printf("\t%d,",Fila.Item[Aux].chave);
    }
    printf("\n\n\t----------------------------------------------------------\n");
}


