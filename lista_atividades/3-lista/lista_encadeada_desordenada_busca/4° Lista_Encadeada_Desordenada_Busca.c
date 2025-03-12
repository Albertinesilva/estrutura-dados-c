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


int Menu_Lista(int Opcao);

void Inicia_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista *Lista);

void Insere_Lista(TipoItem x, TipoLista *Lista);

void Busca(TipoLista *Lista, TipoChave chave, Apontador *P, Apontador *Ant);

void Remove(Apontador p, TipoLista *Lista, TipoItem *Item);

void Imprime (TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x,Item;
    TipoChave chave;
    Apontador P, p, Ant;

    int Opcao = 0, verificador = 0, N = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Lista(Opcao);

        switch (Opcao)
        {

        case 1:

            Inicia_Lista(&Lista);
            verificador = 1;
            printf("\n\tLista Inicializada com Sucesso!...\n");

            break;

        case 2:

            if(verificador == 1)
            {
                if(Lista_Vazia(&Lista))
                {
                    printf("\n\tLista Vazia, pode inserir Elementos!...\n");

                    printf("\n\tDeseja inserir quantos Elementos: ");
                    fflush(stdin);
                    scanf("%d",&N);
                    system("cls");

                    for(int i = 0; i < N; i++)
                    {
                        printf("\n\tInsira o %d° Elemento: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x);

                        Insere_Lista(x, &Lista);
                    }
                    system("cls");
                }
                else
                {
                    printf("\n\tA lista contem elementos, pode continuar inserindo!...\n");

                    printf("\n\tLista Vazia, pode inserir Elementos!...\n");

                    printf("\n\tDeseja inserir quantos Elementos: ");
                    fflush(stdin);
                    scanf("%d",&N);

                    for(int i = 0; i < N; i++)
                    {
                        printf("\n\tInsira o %d° Elemento: ");
                        fflush(stdin);
                        scanf("%d",&x);

                        Insere_Lista(x, &Lista);
                    }
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        case 3:

            Imprime(Lista);

            printf("\n\tInforme um elemento para Busca: ");
            fflush(stdin);
            scanf("%d",&chave);

            Busca(&Lista, chave, &P, &Ant);

            printf("\n\tElemento Anterior %d,",*Ant);
            printf(" Elemento Posterior %d",*P);

            break;

        case 4:

            Imprime(Lista);

            break;

        default:

            printf("\n\tProgama Finalizado!...\n");

            break;

        }
    }
}

int Menu_Lista(int Opcao)
{
    printf("\n\n\t---------------Busca Lista Encadeada---------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar Lista");
        printf("\n\t2 - Inserir Elementos na Lista");
        printf("\n\t3 - Busca");
        printf("\n\t4 - Imprimir Lista");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;
}

void Inicia_Lista(TipoLista *Lista)
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

void Insere_Lista(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Tamanho = Lista->Tamanho + 1;
}

void Busca(TipoLista *Lista, TipoChave chave, Apontador *P, Apontador *Ant)
{
    Apontador Aux;
    Aux = Lista->Primeiro;

    while(Aux != NULL)
    {
        if(Aux->Item.chave == chave)
        {
            *P = Aux;

            break;
        }
        *Ant = Aux;
        Aux = Aux->Prox;
    }

}

void Remove(Apontador p, TipoLista *Lista, TipoItem *Item)
{

}

void Imprime(TipoLista Lista)
{
    printf("\n\n\t-----------------Elementos da Lista-----------------\n\n");

    Apontador Aux;
    Aux = Lista.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\t%d,",Aux->Item.chave);

        Aux = Aux->Prox;
    }
    printf("\n\n\t----------------------------------------------------\n\n");

}

