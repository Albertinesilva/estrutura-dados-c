#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define InicioVetor 0
#define TamMax 5


typedef int TipoChave;

typedef int Apontador;


typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Itens[TamMax];
    Apontador Primeiro, Ultimo;

} TipoLista;


int Menu_Lista(int Opcao);

void Iniciar_Lista(TipoLista *Lista);

int Insere_Lista(TipoItem x, TipoLista *Lista);

int Lista_Vazia(TipoLista Lista);

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

int Busca_Lista(TipoLista *Lista, TipoChave chave);

void Imprime_Lista(TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x, Item;
    TipoChave chave;

    int Opcao = 0, Verificador = 0;
    int i = 0, Busca_Result = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Lista(Opcao);

        switch (Opcao)
        {
        case 1:

            if(Verificador == 1)
            {
                printf("\n\tA Lista já foi Inicializada!...\n\n");
            }
            else
            {
                Iniciar_Lista(&Lista);
                Verificador = 1;
                printf("\n\tLista Inicializada com sucesso!...\n");
            }

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia, pode inserir Elementos!...\n\n");

                    do
                    {

                        printf("\n\tInforme o %d° Elemento para a Lista: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        Insere_Lista(x, &Lista);
                        i++;

                    }
                    while(i < TamMax);

                }
                else
                {
                    if(Lista.Ultimo < TamMax)
                    {
                        printf("\n\tA Lista está com %d elementos, já está Cheia!...",Lista.Ultimo);
                    }

                }
            }
            else
            {
                printf("\n\tFavor Inicializar a Lista!\n");
            }
            break;

        case 3:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia!...\n");
                }
                else
                {
                    printf("\n\tInforme um Elemento para a Busca: ");
                    fflush(stdin);
                    scanf("%d",&chave);

                    Busca_Result =  Busca_Lista(&Lista, chave);

                    if(Busca_Result == 0)
                    {
                        printf("\n\tElemento %d não existe!\n",chave);
                    }
                    else
                    {
                        printf("\n\tResultado da Busca = %d",Lista.Itens[Busca_Result - 1].chave);
                    }
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {

                if(Lista_Vazia(Lista))
                {
                    printf("\n\tLista Vazia!...\n");
                }
                else
                {
                    printf("\n\tGostaria de Remover Algum Elemento?\n\t1 - sim\n\t2 - Não\n\t6 - Sair do Programa\n\tEntrada: ");
                    fflush(stdin);
                    scanf("%d",&Opcao);
                    system("cls");

                    if(Opcao == 1)
                    {
                        printf("\n\tInforme o Elemento para fazer a Busca: ");
                        fflush(stdin);
                        scanf("%d",&chave);
                        system("cls");

                        Busca_Result =  Busca_Lista(&Lista, chave);

                        if(Busca_Result == 0)
                        {
                            printf("\n\tElemento %d não existe!\n",chave);
                        }
                        else
                        {
                            printf("\n\tResultado da Busca = %d",Lista.Itens[Busca_Result - 1].chave);

                            Retira_Lista(Busca_Result, &Lista, &Item);
                            printf("\n\tElemento %d Removido com sucesso!\n",Item);
                        }
                    }
                    else
                    {
                        if(Opcao == 2)
                        {
                           printf("\n\tVocê saiu da Opção de Remoção...\n");
                        }
                        else
                        {
                            if(Opcao == 6)
                            {
                               printf("\n\tPrograma Finalizado!...\n");
                            }
                        }
                    }

                }

            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }
            break;

        case 5:

            Imprime_Lista(Lista);

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\n");

            break;
        }
    }

}

int Menu_Lista(int Opcao)
{
    printf("\n\n\t-------------Busca na Lista------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar Lista");
        printf("\n\t2 - Inserir Elementos na Lista");
        printf("\n\t3 - Realizar Buca na Lista");
        printf("\n\t4 - Remover itens da Lista");
        printf("\n\t5 - Imprimir Lista");
        printf("\n\t6 - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 6  || Opcao < 1);

    return Opcao;
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}

int Insere_Lista(TipoItem x, TipoLista *Lista)
{
    if(Lista->Ultimo > TamMax - 1)
    {
        printf("\n\tLista Cheia!...\n\n");

        return 0;
    }
    else
    {
        Lista->Itens[Lista->Ultimo] = x;
        Lista->Ultimo++;
    }
}

int Busca_Lista(TipoLista *Lista, TipoChave chave)
{
    int p = 0, i = Lista->Primeiro;

    while(i != Lista->Ultimo)
    {
        if(Lista->Itens[i].chave == chave)
        {
            p = i + 1;
            return p;
        }
        i++;
    }
    return p;
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;

    if(Lista_Vazia(*Lista) || p - 1 >= Lista->Ultimo)
    {
        printf("\n\tLista Vazia!...\n");

        return;
    }

    *Item = Lista->Itens[p - 1];

    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Itens[Aux - 1] = Lista->Itens[Aux];
    }
    Lista->Ultimo--;
}

void Imprime_Lista(TipoLista Lista)
{
    int Aux;

    printf("\n\t---------------Lista---------------\n\n");

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\t%d,",Lista.Itens[Aux].chave);
    }
    printf("\n\n");
}
