#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef float TipoChave;

typedef struct
{
    TipoChave Chave;

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
    int Tamanho1, Tamanho2;

} TipoLista;

int Menu(int Opcao);
void Iniciar_Lista(TipoLista *L1, TipoLista *L2);

int Lista_L1_Vazia(TipoLista *L1);
int Lista_L2_Vazia(TipoLista *L2);

void Inserir_L1(TipoItem x, TipoLista *L1);
void Inserir_L2(TipoItem x, TipoLista *L2);

void Concatenar_Listas_L2_e_L1(TipoLista L1, TipoLista L2);

void Busca(TipoLista *L1, TipoChave Chave, Apontador *Pos, Apontador *Ant);
void Remove(Apontador p, TipoLista *L1, TipoItem *Item);

void Imprime_L1(TipoLista L1);
void Imprime_L2(TipoLista L2);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista L1, L2;
    TipoItem x, Item;
    Apontador p, Pos, Ant;
    TipoChave Chave;

    int Opcao = 0, cont = 0;
    while(Opcao != 8)
    {
        Opcao = Menu(Opcao);

        switch (Opcao)
        {
        case 1:

            Iniciar_Lista(&L1, &L2);
            printf("\n\tLista L1 e L2 Inicializadas!...\n");
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
                        scanf("%f",&x);

                        Inserir_L1(x,&L1);
                    }

                    printf("\n\tDeseja Continuar?\n\n\t1 - Continuar\n\t0 - Sair\n");
                    printf("\n\tEntrada: ");
                    fflush(stdin);
                    scanf("%d",&cont);
                    system("cls");

                }
                while(cont > 2 || cont > 0);
                cont = 1;
            }
            else
            {
                printf("\n\tPrimeiro Inicialize a Lista!\n");
            }

            break;

        case 3:

            if(cont == 1)
            {
                do
                {
                    if(Opcao == 3 && cont == 1)
                    {
                        printf("\n\tInforme um Número Inteiro: ");
                        fflush(stdin);
                        scanf("%f",&x);

                        Inserir_L2(x,&L2);
                    }

                    printf("\n\tDeseja Continuar?\n\n\t1 - Continuar\n\t0 - Sair\n");
                    printf("\n\tEntrada: ");
                    fflush(stdin);
                    scanf("%d",&cont);
                    system("cls");

                }
                while(cont > 2 || cont > 0);
                cont = 1;
            }
            else
            {
                printf("\n\tPrimeiro Inicialize a Lista!\n");
            }

            break;

        case 4:

            if(cont == 1)
            {
                if(Lista_L1_Vazia(&L1) || Lista_L2_Vazia(&L2))
                {
                    printf("\n\tAlguma Lista esta Vazia!\n");
                }
                else
                {
                    printf("\n\tLista L2 concatenada em L1!\n");
                    Concatenar_Listas_L2_e_L1(L1, L2);
                }
            }
            else
            {
                printf("\n\tAs Listas não foram inicializadas!\n");
            }

            break;

        case 5:

            Imprime_L1(L1);

            break;

        case 6:

            Imprime_L2(L2);

            break;

        case 7:

         if(cont == 1)
            {
                if(Lista_L1_Vazia(&L1) || Lista_L2_Vazia(&L2))
                {
                    printf("\n\tAlguma Lista esta Vazia!\n");
                }
                else
                {
                    printf("\n\tInforme o Elemento da Lista para remover: ");
                    fflush(stdin);
                    scanf("%f",&Chave);

                    Busca(&L1, Chave, &Pos, &Ant);

                    p = Ant;
                    Remove(p, &L1, &Item);

                    printf("\n\tElemento %2.f Removido da Lista com Sucesso!\n\n",Item.Chave);
                }
            }
            else
            {
                printf("\n\tAs Listas não foram inicializadas!\n");
            }

            break;

        default:

            printf("\n\tPrograma Encerrado!\n");

            break;

        }
    }
}

int Menu(int Opcao)
{
    do
    {
        printf("\n\n\t---------------Concatenar Listas L1 e L2-------------------\n\n");
        printf("\n\t1 - Inicia Lista L1 e L2");
        printf("\n\t2 - Preencher Lista L1");
        printf("\n\t3 - Preencher Lista L2");
        printf("\n\t4 - Concatenar L2 no Final de L1");
        printf("\n\t5 - Imprime L1");
        printf("\n\t6 - Imprime L2");
        printf("\n\t7 - Remove");
        printf("\n\t8 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 8 || Opcao < 1);

    return Opcao;
}

void Iniciar_Lista(TipoLista *L1, TipoLista *L2)
{
    L1->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    L1->Ultimo = L1->Primeiro;
    L1->Primeiro->Prox = NULL;
    L1->Tamanho1 = 0;

    L2->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    L2->Ultimo = L2->Primeiro;
    L2->Primeiro->Prox = NULL;
    L2->Tamanho2 = 0;
}

int Lista_L1_Vazia(TipoLista *L1)
{
    return (L1->Primeiro == L1->Ultimo);
}

int Lista_L2_Vazia(TipoLista *L2)
{
    return (L2->Primeiro == L2->Ultimo);
}

void Inserir_L1(TipoItem x, TipoLista *L1)
{
    L1->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    L1->Ultimo = L1->Ultimo->Prox;
    L1->Ultimo->Item = x;
    L1->Ultimo->Prox = NULL;
    L1->Tamanho1 = L1->Tamanho1 + 1;
}

void Inserir_L2(TipoItem x, TipoLista *L2)
{
    L2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
    L2->Ultimo = L2->Ultimo->Prox;
    L2->Ultimo->Item =  x;
    L2->Tamanho2 = L2->Tamanho2 + 1;
}

void Concatenar_Listas_L2_e_L1(TipoLista L1, TipoLista L2)
{
    Apontador Aux;

    if(Lista_L1_Vazia(&L1) && Lista_L2_Vazia(&L2))
    {
        printf("\n\tExiste Alguma Lista Vazia!\n");
    }
    else
    {
        //Tipo Primitivo Ponteiro: Aux pega o Ultimo elemento de L1.
        Aux =  L1.Ultimo;

        //Tipo Primitivo Ponteiro: Aux pega o Primeiro elemento de L2.
        Aux->Prox = L2.Primeiro->Prox;
    }

    printf("\n\tVariavel Auxiliar, pega o Ultimo elemento de L1!\n\n");
    while(Aux != NULL)
    {
        printf("\t%.1f, ",Aux->Item.Chave);
        Aux = Aux->Prox;
    }

    printf("\n\t------------------------------------------------");

    printf("\n\n\n\tLista L1 Concatenada");
    Imprime_L1(L1);

    printf("\n\t-----------------------------------------------------------\n");
}

void Imprime_L1(TipoLista L1)
{
    printf("\n\t--------------------------Lista L1-------------------------\n\n");
    Apontador Aux;
    Aux = L1.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\t%.1f, ",Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void Imprime_L2(TipoLista L2)
{
    printf("\n\t--------------------------Lista L2-------------------------\n\n");
    Apontador Aux;
    Aux = L2.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\t%.1f, ",Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void Busca(TipoLista *L1, TipoChave Chave, Apontador *Pos, Apontador *Ant)
{
    Apontador Aux;
    Aux = L1->Primeiro;


    while(Aux != NULL)
    {
        if(Aux->Item.Chave == Chave)
        {
            *Pos = Aux;

            break;
        }
        *Ant = Aux;
        Aux = Aux->Prox;

    }
}

void Remove(Apontador p, TipoLista *L1, TipoItem *Item)
{
    Apontador pAux;

    if(Lista_L1_Vazia(L1) || p == NULL || p->Prox == NULL)
    {
        printf("\n\tErro Lista vazia ou posição não existe!\n");
        return;
    }

    pAux = p->Prox;
    *Item = pAux->Item;
    p->Prox = pAux->Prox;

    if(p->Prox == NULL)
    {
        L1->Ultimo = p;
        free(pAux);
        L1->Tamanho1 = L1->Tamanho1 - 1;
    }
}
