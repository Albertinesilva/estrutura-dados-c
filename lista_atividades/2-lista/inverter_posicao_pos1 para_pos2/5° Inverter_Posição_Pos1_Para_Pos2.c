#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef int TipoChave;

typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;
};

typedef struct
{
    Apontador Primeiro, Ultimo;
    int Tamanho;

} TipoLista;

int Menu(int Opcao);

void Iniciar_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista *Lista);

void Inserir_Lista(TipoItem x, TipoLista *Lista);

void Imprime(TipoLista Lista);

void Trocar_Posicao(TipoLista *Lista, int Pos1, int Pos2);

void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x;

    int Opcao = 0, Verificador = 0;
    int Op = 0, Posicao1 = 0, Posicao2 = 0;

    while(Opcao != 5)
    {
        Opcao = Menu(Opcao);

        switch (Opcao)
        {
        case 1:

            Verificador = 1;
            Iniciar_Lista(&Lista);
            printf("\n\tLista Inicializada com sucesso!\n");

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Lista_Vazia(&Lista))
                {
                    printf("\n\tA Lista está Vazia, pode inserir...\n");

                    do
                    {
                        printf("\n\tDigite um Elemento: ");
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        Inserir_Lista(x, &Lista);

                        printf("\n\n\t1 - Continuar\n\t2 - Sair");
                        printf("\n\tEntrada: ");
                        scanf("%d",&Op);
                        system("cls");

                    }
                    while(Op != 2);

                }
                else
                {
                    printf("\n\tA Lista contem alguns elementos, pode continuar inserindo...\n");

                    do
                    {
                        printf("\n\tDigite um Elemento: ");
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        Inserir_Lista(x, &Lista);

                        printf("\n\t1 - Continuar\n2 - Sair");
                        printf("\n\tEntrada: ");
                        scanf("%d",&Op);
                        system("cls");

                    }
                    while(Op != 2);
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...");
            }
            break;

        case 3:


            if(Verificador == 1)
            {
                printf("\n\n\tInforme a Posição, do elemento da Lista, que deseja trocar:\n\n");

                Imprime(Lista);

                printf("\n\n\tInforme POS1: ");
                fflush(stdin);
                scanf("%d",&Posicao1);

                printf("\n\tInforme POS2: ");
                fflush(stdin);
                scanf("%d",&Posicao2);

                Trocar_Posicao(&Lista, Posicao1, Posicao2);

            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...");
            }

            break;

        case 4:

            if(Verificador == 1)
            {
                Imprime(Lista);
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...");
            }


            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;
        }
    }

}

int Menu(int Opcao)
{
    printf("\n\n\t---------------Inverter Posição Pos---------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar Lista");
        printf("\n\t2 - Inserir Elementos na Lista");
        printf("\n\t3 - Inverter Elementos da Posição");
        printf("\n\t4 - Imprimir Lista");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;
}

int Lista_Vazia(TipoLista *Lista)
{
    return Lista->Primeiro == Lista->Ultimo;
}

void Inserir_Lista(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->Tamanho = Lista->Tamanho + 1;
}

void Trocar_Posicao(TipoLista *Lista, int Pos1, int Pos2)
{
    Apontador P1 = Lista->Primeiro;
    Apontador P2 = Lista->Primeiro;

    int i = 0;
    int y = 0;
    while(i <= Lista->Tamanho)
    {
        i++;
        if(Pos1 == i)
        {
            break;
        }
        P1 = P1->Prox;
    }

    do
    {
        y++;
        if(Pos2 == y)
        {
            break;
        }
        P2 = P2->Prox;

    }
    while(y <= Lista->Tamanho);

    Apontador Aux1 = P1->Prox;
    Apontador Aux2 = P2->Prox;

    P1->Prox = Aux2;
    P2->Prox = Aux1;

    Apontador Aux3 = Aux1->Prox;
    Aux1->Prox = Aux2->Prox;
    Aux2->Prox = Aux3;

    printf("\n\t-----------------Posição Invertida-----------------\n\n\n");

    Imprime(*Lista);

}

void Imprime(TipoLista Lista)
{
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;

    printf("\n");
    while(Aux != NULL)
    {
        printf("\t");
        printf("%d,",Aux->Item.chave);

        Aux = Aux->Prox;
    }
    printf("\n\n");
}
