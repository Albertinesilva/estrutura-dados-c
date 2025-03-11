#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef int TipoChave;

typedef struct
{
    TipoChave chave;
    TipoChave n;

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

} Lista;


int Menu(int op);
void Inicia_Lista_L(Lista *L);

int Lista_Vazia(Lista *L2);
int Lista_Vazia_L(Lista *L);

void Insere_Lista(TipoItem x, Lista *L);
Lista* Separa_Lista(Lista* L, int n);

void Imprime_Lista_Separada(Lista L);
void Imprime_Lista_Nova(Lista L2);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoItem Item, x;
    Lista Lista_Separada, Lista_Nova;

    int Opcao=0, n=0, cont=0;
    while(Opcao != 6)
    {
        Opcao = Menu(Opcao);

        switch (Opcao)
        {
        case 1:

            Inicia_Lista_L(&Lista_Separada);
            printf("\n\tLista Inicializada!...\n");
            cont = 1;

            break;

        case 2:

            if(cont == 1)
            {
                do
                {
                    if(Opcao == 2 && cont == 1)
                    {
                        printf("\n\tInforme um Número Inteiro: ");
                        fflush(stdin);
                        scanf("%d",&x);

                        Insere_Lista(x,&Lista_Separada);
                    }

                    printf("\n\tDeseja Continuar?\n\n\t1 - Continuar\n\t0 - Sair\n");
                    printf("\n\tEntrada: ");
                    fflush(stdin);
                    scanf("%d",&cont);
                    system("cls");

                }
                while(cont > 2 || cont > 0);

            }
            else
            {
                printf("\n\tPrimeiro Inicialize a Lista!\n");
            }

            break;

        case 3:

            printf("\n\tInforme a ocorrencia de N: ");
            fflush(stdin);
            scanf("%d",&n);

            Separa_Lista(&Lista_Separada, n);

            break;

        case 4:

            Imprime_Lista_Separada(Lista_Separada);

            break;

        case 5:

            Imprime_Lista_Nova(Lista_Nova);

            break;

        default:

            printf("\n\tPesquisa finalizada!\n");

            break;
        }
    }
}

int Menu(int op)
{
    do
    {
        printf("\n\n\t------------SEPARAR LISTAS------------\n\n");
        printf("\n\t1 - Iniciar Lista");
        printf("\n\t2 - Preencher Lista");
        printf("\n\t3 - Separar Lista");
        printf("\n\t4 - Imprimir Lista separada");
        printf("\n\t5 - Imprimir Lista nova");
        printf("\n\t6 - Sair\n");
        printf("\n\tEntrada: ");
        scanf("%d",&op);
        system("cls");
    }
    while(op > 6 || op < 1);
    return op;
}

void Inicia_Lista_L(Lista *L)
{
    L->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    L->Ultimo = L->Primeiro;
    L->Primeiro->Prox = NULL;
    L->Tamanho = 0;
}

int Lista_Vazia(Lista *L2)
{
    return (L2->Primeiro == L2->Ultimo);
}

int Lista_Vazia_L(Lista *L)
{
    return (L->Primeiro == L->Ultimo);
}

void Insere_Lista(TipoItem x, Lista *L)
{
    L->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    L->Ultimo = L->Ultimo->Prox;
    L->Ultimo->Item = x;
    L->Ultimo->Prox = NULL;
    L->Tamanho = L->Tamanho + 1;
}

Lista* Separa_Lista(Lista* L, int n)
{
    Apontador Aux;
    Aux = L->Primeiro->Prox;
    Lista L2;

    L2.Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    L2.Ultimo = L2.Primeiro;
    L2.Primeiro->Prox = NULL;

    while(Aux != NULL)
    {
        if(Aux->Item.chave == n)
        {
            L2.Primeiro->Prox = Aux->Prox;
            L->Ultimo->Prox = NULL;
        }
        L->Ultimo = Aux->Prox;
        Aux = Aux->Prox;
    }

    Imprime_Lista_Separada(*L);

    Imprime_Lista_Nova(L2);

}

void Imprime_Lista_Separada(Lista L)
{
    Apontador Aux;
    Aux = L.Primeiro->Prox;

    printf("\n\n\t-------------Lista Separada------------\n\n");
    while(Aux != NULL)
    {
        printf("\t%d,",Aux->Item.chave);
        Aux = Aux->Prox;
    }
     printf("\n\n");
}

void Imprime_Lista_Nova(Lista L2)
{
    Apontador Aux;
    Aux = L2.Primeiro->Prox;

    printf("\n\n\t---------------Nova Lista--------------\n\n");
    while(Aux != NULL)
    {
        printf("\t%d,",Aux->Item.chave);
        Aux = Aux->Prox;
    }
    printf("\n\n");
}



