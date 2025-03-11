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
void Iniciar_Lista2(TipoLista *Lista2);

int Lista_Vazia(TipoLista *Lista);
int Lista2_Vazia(TipoLista *Lista2);

TipoLista Insere_Lista2(TipoItem x, TipoLista *Lista, TipoLista *Lista2);
void Remove(Apontador p, TipoLista *Lista, TipoItem *Item);
void Busca(TipoLista *Lista, TipoChave chave, Apontador *Pos, Apontador *Ant);

void Imprime_Lista(TipoLista Lista);
void Imprime_Lista2(TipoLista Lista2);

int verificador = 0;
void main()
{
    setlocale(LC_ALL,"portuguese");

    int Opcao = 0, N = 0;
    int i = 0, cont = 0;

    TipoLista Lista, Lista2;
    Apontador p, Pos, Ant;
    TipoChave chave;
    TipoItem Item;

    while(Opcao != 7)
    {
        Opcao = Menu(Opcao);

        switch (Opcao)
        {
        case 1:

            Iniciar_Lista(&Lista);
            Iniciar_Lista2(&Lista2);

            printf("\n\n\tListas Inicializadas com sucesso!...\n\n");
            cont = 1;

            break;

        case 2:

            if(cont == 1 && Lista_Vazia(&Lista))
            {
                printf("\n\tInforme quantos elementos vai ter o Vetor: ");
                scanf("%d",&N);
                fflush(stdin);
                TipoItem Vet[N];


                do
                {
                    i++;
                    printf("\n\tDigite o elemento da Posição %d°: ",i);
                    scanf("%d",&Vet[i].chave);
                    fflush(stdin);


                    if(Vet[i].chave == 3 && i == 1 && N == 5)
                    {
                        verificador++;
                        Insere_Lista2(Vet[i], &Lista, &Lista2);
                    }
                    else
                    {
                        if(Vet[i].chave == 8 && i == 2 && verificador == 1 && N == 5)
                        {
                            verificador++;
                            Insere_Lista2(Vet[i], &Lista, &Lista2);
                        }
                        else
                        {
                            if(Vet[i].chave == 1 && i == 3 && verificador == 2 && N == 5)
                            {
                                verificador++;
                                Insere_Lista2(Vet[i], &Lista, &Lista2);
                            }
                            else
                            {
                                if(Vet[i].chave == 7 && i == 4 && verificador == 3 && N == 5)
                                {
                                    verificador++;
                                    Insere_Lista2(Vet[i], &Lista, &Lista2);
                                }
                                else
                                {
                                    if(Vet[i].chave == 2 && i == 5 && verificador == 4 && N == 5)
                                    {
                                        verificador++;
                                        Insere_Lista2(Vet[i], &Lista, &Lista2);
                                    }
                                    else
                                    {
                                        if(verificador == 0)
                                        {
                                            Insere_Lista2(Vet[i], &Lista, &Lista2);
                                        }
                                    }

                                }
                            }
                        }
                    }

                }
                while(i < N);

            }
            else
            {
                printf("\n\n\tA Lista precisa ser inicializada!...\n\n");
            }
            break;

        case 3:

            if(cont == 1)
            {
                if(Lista2_Vazia(&Lista2))
                {
                    printf("\n\tLista 2 Vazia!...\n");
                    printf("\n\tOu Não Recebeu a sequencia de Elementos = 3,8,1,7,2");
                }
                else
                {
                    Imprime_Lista2(Lista2);
                }
            }
            else
            {
                printf("\n\tA Lista precisa ser inicializada!...\n\n");
            }
            break;

        case 4:

            if(cont == 1)
            {
                if(Lista_Vazia(&Lista))
                {
                    printf("\n\tLista 1 Vazia!...\n");
                }
                else
                {
                    Imprime_Lista(Lista);
                }
            }
            else
            {
                printf("\n\tA Lista precisa ser inicializada!...\n\n");
            }
            break;

        case 5:

            if(cont == 1 && verificador == 5)
            {
                if(Lista2_Vazia(&Lista2))
                {
                    printf("\n\tLista 2 Vazia!...\n");
                }
                else
                {
                    Imprime_Lista2(Lista2);
                }
            }
            else
            {
                printf("\n\tA Lista precisa ser inicializada!...\n\tOu Inserir a sequencia de Elementos = 3,8,1,7,2\n\n");
            }

            break;

        case 6:


            if(cont == 1)
            {
                if(Lista_Vazia(&Lista))
                {
                    printf("\n\tLista 1 Vazia!...\n");
                }
                else
                {
                    printf("\n\tInforme um Elemento para excluir da Lista: ");
                    fflush(stdin);
                    scanf("%d",&chave);

                    Busca(&Lista, chave, &Pos, &Ant);

                    p = Ant;
                    Remove(p, &Lista, &Item);

                    printf("\n\tElemento %d Excluido da Lista!",Item.chave);
                }
            }
            else
            {
                printf("\n\tA Lista precisa ser inicializada!...\n\n");
            }

            break;

        case 7:

            printf("\n\tPrograma Finalizado!...\n\n");

            break;
        }
    }
}

int Menu(int Opcao)
{
    do
    {
        printf("\n\n\t1 - Iniciar Lista");
        printf("\n\t2 - Inserir Elementos, do Vetor, na Lista");
        printf("\n\t3 - Nova Lista com elementos diferenciados");
        printf("\n\t4 - Imprime Lista 1");
        printf("\n\t5 - Imprimir Nova Lista com Elementos 3,8,1,7,2");
        printf("\n\t6 - Remove");
        printf("\n\t7 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        system("cls");
    }
    while(Opcao > 7 || Opcao < 1);

    return Opcao;
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;
}

void Iniciar_Lista2(TipoLista *Lista2)
{
    Lista2->Primeiro = (Apontador)malloc(sizeof(struct TipoCelula));
    Lista2->Ultimo = Lista2->Primeiro;
    Lista2->Primeiro->Prox = NULL;
    Lista2->Tamanho = 0;
}

int Lista_Vazia(TipoLista *Lista)
{
    return (Lista->Primeiro == Lista->Ultimo);
}

int Lista2_Vazia(TipoLista *Lista2)
{
    return (Lista2->Primeiro == Lista2->Ultimo);
}


TipoLista Insere_Lista2(TipoItem x, TipoLista *Lista, TipoLista *Lista2)
{
    if(verificador == 0)
    {
        Lista->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
        Lista->Ultimo = Lista->Ultimo->Prox;
        Lista->Ultimo->Item = x;
        Lista->Ultimo->Prox = NULL;
        Lista->Tamanho = Lista->Tamanho + 1;
    }

    // Lista2->Ultimo->Prox = Lista->Primeiro->Prox;


    if(verificador == 1)
    {
        Lista2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
        Lista2->Ultimo = Lista2->Ultimo->Prox;
        Lista2->Ultimo->Item = x ;
        Lista->Ultimo->Prox = NULL;
        Lista->Tamanho = Lista->Tamanho + 1;
    }
    else
    {
        if(verificador == 2)
        {
            Lista2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
            Lista2->Ultimo = Lista2->Ultimo->Prox;
            Lista2->Ultimo->Item = x ;
            Lista->Ultimo->Prox = NULL;
            Lista->Tamanho = Lista->Tamanho + 1;
        }
        else
        {
            if(verificador == 3)
            {
                Lista2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
                Lista2->Ultimo = Lista2->Ultimo->Prox;
                Lista2->Ultimo->Item = x ;
                Lista->Ultimo->Prox = NULL;
                Lista->Tamanho = Lista->Tamanho + 1;
            }
            else
            {
                if(verificador == 4)
                {
                    Lista2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
                    Lista2->Ultimo = Lista2->Ultimo->Prox;
                    Lista2->Ultimo->Item = x ;
                    Lista->Ultimo->Prox = NULL;
                    Lista->Tamanho = Lista->Tamanho + 1;
                }
                else
                {
                    if(verificador == 5)
                    {
                        Lista2->Ultimo->Prox = (Apontador)malloc(sizeof(struct TipoCelula));
                        Lista2->Ultimo = Lista2->Ultimo->Prox;
                        Lista2->Ultimo->Item = x ;
                        Lista->Ultimo->Prox = NULL;
                        Lista->Tamanho = Lista->Tamanho + 1;
                    }
                }
            }
        }
    }

}

void Busca(TipoLista *Lista, TipoChave chave, Apontador *Pos, Apontador *Ant)
{
    Apontador Aux;
    Aux = Lista->Primeiro;

    while(Aux != NULL)
    {
        if(Aux->Item.chave == chave)
        {
            *Pos = Aux;
            break;
        }
        *Ant = Aux;
        Aux = Aux->Prox;
    }
}

void Remove(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    Apontador pAux;

    if(Lista_Vazia(Lista) || p == NULL || p->Prox == NULL)
    {
        printf("\n\tErro lista vazia ou posição não existe!\n");
        return;
    }

    pAux = p->Prox;
    *Item = pAux->Item;
    p->Prox = pAux->Prox;

    if(p->Prox == NULL)
    {
        Lista->Ultimo = p;
        free(pAux);
        Lista->Tamanho = Lista->Tamanho - 1;
    }
}

void Imprime_Lista(TipoLista Lista)
{
    printf("\n\n\t-----------------Lista Principal-----------------\n\n");
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\t");
        printf("%d, ", Aux->Item.chave);
        Aux = Aux->Prox;
    }
    printf("\n\n");
}

void Imprime_Lista2(TipoLista Lista2)
{
    printf("\n\n\t-----------------Nova Lista-----------------\n\n");
    Apontador Aux;
    Aux = Lista2.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\t");
        printf("%d, ", Aux->Item.chave);
        Aux = Aux->Prox;
    }
    printf("\n\n");
}
