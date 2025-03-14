#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef char TipoChave;


typedef struct
{
    TipoChave chave[20];

} TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;

} Celula;

typedef struct
{
    Apontador Frente, Fundo;
    int Tamanho;

} TipoFila;

int Menu_Fila(int Opcao);

void Iniciar_Fila(TipoFila *Fila);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Imprimir_Fila(TipoFila Fila);

void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila;
    TipoItem x, Item;

    int Opcao = 0, verificador = 0, Quant_Avioes = 0;
    while(Opcao != 7)
    {
        Opcao = Menu_Fila(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila);
            verificador = 1;

            printf("\n\tA Fila dos Aviões foi Iniciada!...\n");

            break;

        case 2:

            /*Boeing 747-8.
            Airbus A380. ...
            Boeing 777. ...
            Airbus A350. ...
            Airbus A340. ...
            Airbus A330. ...
            Embraer E-195. ...
            Bombardier CRJ900*/

            if(verificador == 1)
            {
                printf("\n\tInforme quantos Aviões vai decolar: ");
                fflush(stdin);
                scanf("%d",&Quant_Avioes);

                while(Quant_Avioes != 0)
                {
                    printf("\n\tInforme a caracteristica do Avião que vai aguardar a decolagem: ");
                    fflush(stdin);
                    gets(x.chave);

                    Enfileirar_Fila(x, &Fila);
                    Quant_Avioes--;
                }
            }

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

             Imprimir_Fila(Fila);

            break;

        case 6:

            break;

        default:

            printf("\n\tDecolagem Finalizada!...\n");
        }
    }

}

int Menu_Fila(int Opcao)
{
    printf("\n\t---------------Pista para Decolagem de Aviões---------------\n");

    do
    {
        printf("\n\t1 - Iniciar a Fila de Avião");
        printf("\n\t2 - Número de Aviões à Espera da Decolagem");
        printf("\n\t3 - Decolagem de um Avião");
        printf("\n\t4 - Entrada de um Novo Avião para Decolar");
        printf("\n\t5 - Listar os Aviões à Espera de Decolar");
        printf("\n\t6 - Listar as Caracteristicas do Próximo Avião a Decolar");
        printf("\n\t7 - Sair do Aeroporto");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 7 || Opcao < 1);

    return Opcao;
}


void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = (Apontador)malloc(sizeof(Celula));
    Fila->Fundo = Fila->Frente;
    Fila->Frente->Prox = NULL;
    Fila->Tamanho = 0;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Enfileirar_Fila(TipoItem x, TipoFila *Fila)
{
    Fila->Fundo->Prox = (Apontador)malloc(sizeof(Celula));
    Fila->Fundo = Fila->Fundo->Prox;
    Fila->Fundo->Item = x;
    Fila->Fundo->Prox = NULL;
    Fila->Tamanho = Fila->Tamanho + 1;

}

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item)
{
    Apontador Aux;

    if(Fila_Vazia(Fila))
    {
        printf("\n\tErro Fila Vazia!...\n");
        return;
    }
    else
    {
        Aux = Fila->Frente;
        Fila->Frente = Fila->Frente->Prox;
        *Item = Fila->Frente->Item;
        free(Aux);
        Fila->Tamanho = Fila->Tamanho - 1;
    }
}

void Imprimir_Fila(TipoFila Fila)
{
    printf("\n\t---------------Aviões que aguardam decolar---------------\n\n");

    Apontador Aux;
    Aux = Fila.Frente->Prox;

    while(Aux != NULL)
    {
        printf("\n\t%s",Aux->Item.chave);

        Aux = Aux->Prox;
    }
}
