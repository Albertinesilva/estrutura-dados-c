#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Locale.h>

#define InicioVetor 0
#define TamMax1 5
#define TamMax2 10

typedef int TipoChave;
typedef int Apontador;

typedef struct
{
    TipoChave Matricula;
    char Nome[50];
    int Idade;

} TipoItem;

typedef struct
{
    TipoItem Item1[TamMax1];
    TipoItem Item2[TamMax2];
    Apontador Primeiro, Ultimo;

} TipoLista;

int Menu_TipoLista(int Opcao);
void Inicia_Listas(TipoLista *L1, TipoLista *L2, TipoLista *L3);
int Lista1_Vazia(TipoLista L1);
int Lista2_Vazia(TipoLista L2);
int Insere_Lista1(TipoItem x, TipoLista *L1);
int Insere_Lista2(TipoItem y, TipoLista *L2);
void Ordenar_L1(TipoItem x, TipoLista *L1, TipoLista *L2);
void Imprime_L1_L2(TipoLista L1, TipoLista L2);
void Verifica_se_L1_EstaOrdenada(TipoLista L1);
void Copia_L1_Para_L2(TipoLista *L1, TipoLista *L2);
void Inverte_L1_Colocando_Em_L2(TipoLista L1,TipoLista L2);
void Intercala_L1ComL2_Ordenados_Gerando_L3(TipoLista *L1,TipoLista *L2,TipoLista *L3);
int Elimina_L1(Apontador P, TipoLista *L1, TipoItem *Item);
int Retira_Lista(Apontador P, TipoLista *L1, TipoItem *Item);

int main()
{
    setlocale(LC_ALL,"portuguese");

    Apontador P;
    TipoItem Lista1, Lista2, Item;
    TipoLista L1, L2, L3;
    Inicia_Listas(&L1, &L2, &L3);

    int op = 0;
    while(op != 10)
    {
        op = Menu_TipoLista(op);

        switch(op)
        {
        case 1:

            printf("\n\n\t----------Lista L1----------\n");
            if(Lista1_Vazia(L1))
            {
                printf("\n\tLista Vazia, Pode Inserir!...\n");
                Insere_Lista1(Lista1, &L1);
            }
            else
            {
                if(L1.Ultimo < TamMax1)
                {
                    Insere_Lista1(Lista1, &L1);
                }
                else
                {
                    printf("\n\tA Lista L1 esta cheia!\n");
                }
            }
            break;

        case 2:

            printf("\n\n\t----------Lista L2----------\n");
            if(Lista2_Vazia(L2))
            {
                printf("\n\tLista Vazia, Pode Inserir!...\n");
                Insere_Lista2(Lista2, &L2);
            }
            else
            {
                if(L2.Ultimo < TamMax1)
                {
                    Insere_Lista2(Lista2, &L2);
                }
                else
                {
                    printf("\n\tA Lista L2 esta cheia!\n");
                }
            }

            break;

        case 3:

            Ordenar_L1(Item, &L1, &L2);

            break;

        case 4:

            if(Lista1_Vazia(L1))
            {
                printf("\nLista L1 Vazia!\n");
                fflush(stdin);
            }
            else
            {
                Verifica_se_L1_EstaOrdenada(L1);
            }

            break;

        case 5:

            Copia_L1_Para_L2(&L1, &L2);

            break;

        case 6:

            Inverte_L1_Colocando_Em_L2(L1, L2);

            break;

        case 7:

            Intercala_L1ComL2_Ordenados_Gerando_L3(&L1, &L2, &L3);

            break;

        case 8:
            printf("\n\tInforme o Número da Matricula, que deseja Eliminar da Lista L1: ");
            scanf("%d",&P);
            fflush(stdin);

            Elimina_L1(P, &L1, &Item);
            printf("\n\tMATRICULA %d EXCLUIDA DA LISTA,",Item.Matricula);
            printf(" DO ALUNO %s COM A IDADE DE %d ANOS",Item.Nome, Item.Idade);

            break;

        case 9:

            Imprime_L1_L2(L1, L2);

            break;

        default:

            printf("\n\tPrograma Encerrado!\n");

            break;
        }
    }
    return 0;
}

int Menu_TipoLista(int Opcao)
{
    do
    {
        printf("\n\n\t----------MENU TIPO LISTA-----------\n");

        printf("\n\t1 - Preencher L1\n");
        printf("\t2 - Preencher L2\n");
        printf("\t3 - Preencher L1 e L2 Ordenadas\n");
        printf("\t4 - Verifique se L1 está ordenada\n");
        printf("\t5 - Faça Copia de L1 Para L2\n");
        printf("\t6 - Inverta L1 Colocando em L2\n");
        printf("\t7 - Intercale L1 Com L2, Gerando L3\n");
        printf("\t8 - Elimine de L1 Todas as Ocorrências\n");
        printf("\t9 - Imprime L1 e L2\n");
        printf("\t10 - Sair\n");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        fflush(stdin);
        system("cls");
    }
    while(Opcao > 10|| Opcao < 1);
    return Opcao;
}
void Inicia_Listas(TipoLista *L1, TipoLista *L2, TipoLista *L3)
{
    L1->Primeiro = InicioVetor;
    L1->Ultimo = L1->Primeiro;

    L2->Primeiro = InicioVetor;
    L2->Ultimo = L2->Primeiro;

    L3->Primeiro = InicioVetor;
    L3->Ultimo = L3->Primeiro;
}

int Lista1_Vazia(TipoLista L1)
{
    return L1.Primeiro == L1.Ultimo;
}

int Lista2_Vazia(TipoLista L2)
{
    return L2.Primeiro == L2.Ultimo;
}

int Insere_Lista1(TipoItem x, TipoLista *L1)
{
    int Pos=0;
    if(L1->Ultimo > TamMax1 - 1)
    {
        return (0);
    }
    else
    {
        printf("\n\tDigite o Nome: ");
        fflush(stdin);
        gets(x.Nome);
        printf("\tDigite a Idade: ");
        fflush(stdin);
        scanf("%d",&x.Idade);
        printf("\tDigite a Matricula: ");
        fflush(stdin);
        scanf("%d",&x.Matricula);


        do
        {
            printf("\n\tInforme a posição que deseja inserir %d° Aluno: ",L1->Ultimo+1);
            scanf("%d",&Pos);
            fflush(stdin);

            if(Pos > TamMax1 || Pos <= 0)
            {
                printf("\n\tPosição Invalida!\n");
            }
            else
            {
                L1->Item1[Pos - 1] = x;
                L1->Ultimo++;
            }
        }
        while(Pos > TamMax1);
        printf("\n\tAlunos Cadastrados: %d",L1->Ultimo);
    }
}

int Insere_Lista2(TipoItem y, TipoLista *L2)
{
    int Pos = 0;

    if(L2->Ultimo > TamMax1 -1)
    {
        return (0);
    }
    else
    {
        printf("\n\tDigite o Nome: ");
        fflush(stdin);
        gets(y.Nome);
        printf("\tDigite a Idade: ");
        fflush(stdin);
        scanf("%d",&y.Idade);
        printf("\tDigite a Matricula: ");
        fflush(stdin);
        scanf("%d",&y.Matricula);

        do
        {
            printf("\n\tInforme a posição que deseja inserir %d° Aluno: ",L2->Ultimo + 1);
            scanf("%d",&Pos);
            fflush(stdin);

            if(Pos > TamMax1 || Pos <= 0)
            {
                printf("\n\tPosição Invalida!\n");
            }
            else
            {
                L2->Item1[Pos - 1] = y;
                L2->Ultimo++;
            }
        }
        while(Pos > TamMax1);
        printf("\n\tAlunos Cadastrados: %d\n",L2->Ultimo);
    }
}

void Ordenar_L1(TipoItem x, TipoLista *L1, TipoLista *L2)
{
    int op = 0;

    printf("\n\tDeseja Preencher qual das Listas Ordenada?\n\n");
    printf("\tL1 Digite - 1\n\tL2 Digite - 2\n");
    printf("\n\tEntrada: ");
    scanf("%d",&op);

    if(op == 1)
    {
        if(Lista1_Vazia(*L1))
        {
            printf("\n\tLista L1 Vazia, Pode Inserir!...\n");
            for(int j = L1->Primeiro; j < TamMax1; j++)
            {
                printf("\n\tDigite o Nome: ");
                fflush(stdin);
                gets(x.Nome);
                printf("\tDigite a Idade: ");
                fflush(stdin);
                scanf("%d",&x.Idade);
                printf("\tDigite a Matricula: ");
                fflush(stdin);
                scanf("%d",&x.Matricula);

                int i = L1->Ultimo;
                while(i > 0 && x.Matricula < L1->Item1[i - 1].Matricula)
                {
                    L1->Item1[i] = L1->Item1[i - 1];
                    i--;
                }
                L1->Item1[i] = x;
                L1->Ultimo++;
            }
        }
        else
        {
            printf("\nA Lista L1 esta Cheia!\n");
        }
    }
    if(op == 2)
    {
        if(Lista1_Vazia(*L2))
        {
            printf("\n\tLista L2 Vazia, Pode Inserir!...\n");
            for(int j = L2->Primeiro; j < TamMax1; j++)
            {
                printf("\n\tDigite o Nome: ");
                fflush(stdin);
                gets(x.Nome);
                printf("\tDigite a Idade: ");
                fflush(stdin);
                scanf("%d",&x.Idade);
                printf("\tDigite a Matricula: ");
                fflush(stdin);
                scanf("%d",&x.Matricula);

                int i = L2->Ultimo;
                while(i > 0 && x.Matricula < L2->Item1[i - 1].Matricula)
                {
                    L2->Item1[i] = L2->Item1[i - 1];
                    i--;
                }
                L2->Item1[i] = x;
                L2->Ultimo++;
            }
        }
        else
        {
            printf("\nA Lista L2 esta Cheia!\n");
        }
    }
}

void Imprime_L1_L2(TipoLista L1, TipoLista L2)
{
    printf("\n\n\t---------------Lista L1---------------\n");
    for(int i = L1.Primeiro; i < L1.Ultimo; i++)
    {
        printf("\n\tNome: %s\n",L1.Item1[i].Nome);
        printf("\tMatricula: %d\n",L1.Item1[i].Matricula);
        printf("\tIdade: %d\n",L1.Item1[i].Idade);
    }

    printf("\n\n\t---------------Lista L2---------------\n");
    for(int i = L2.Primeiro; i < L2.Ultimo; i++)
    {
        printf("\n\tNome: %s\n",L2.Item1[i].Nome);
        printf("\tMatricula: %d\n",L2.Item1[i].Matricula);
        printf("\tIdade: %d\n",L2.Item1[i].Idade);
    }
}
void Verifica_se_L1_EstaOrdenada(TipoLista L1)
{
    int x=0,y=1;
    int crescente=0,decrescente=0;

    for(int i = 0; i < L1.Ultimo; i++)
    {
        if(L1.Item1[i].Idade <= L1.Item1[x].Idade)
        {
            crescente++;
            x++;
        }
        else
        {
            if(L1.Item1[i].Idade >= L1.Item1[y].Idade)
            {
                decrescente++;
                y++;
            }
            x++;
            y++;
        }
    }
    if(crescente == L1.Ultimo )
    {
        printf("\n\n\tEsta ordenado de forma crescente!\n");
    }
    else
    {
        if(decrescente == L1.Ultimo - 1)
        {
            printf("\n\n\tEsta ordenado de forma decrescente!\n");
        }
        else
        {
            printf("\n\n\tNão está nem crescente e nem decrescente!\n");
            printf("\n\tcrescente %d",crescente);
        }
    }
}

void Copia_L1_Para_L2(TipoLista *L1, TipoLista *L2)
{
    int i;

    if(Lista1_Vazia(*L1))
    {
        printf("\n\tLista L1 Vazia!\n");
        fflush(stdin);
        return;
    }
    for(i = L1->Primeiro; i < L1->Ultimo; i++)
    {
        L2->Item1[i] = L1->Item1[i];
    }
    L2->Primeiro = L2->Primeiro;
    L2->Ultimo = L1->Ultimo;

    printf("\n\t---------------------Cópia da Lista L1 Para L2--------------------\n\n");
    for(int i = L2->Primeiro; i < L2->Ultimo; i++)
    {
        printf("\n\tNome: %s\n",L2->Item1[i].Nome);
        printf("\tMatricula: %d\n",L2->Item1[i].Matricula);
        printf("\tIdade: %d\n",L2->Item1[i].Idade);
    }
}

void Inverte_L1_Colocando_Em_L2(TipoLista L1,TipoLista L2)
{
    int x = L1.Ultimo;
    for(int i = 0; i < L1.Ultimo; i++)
    {
        L2.Item1[i] = L1.Item1[x-1];
        x--;
    }
    L2.Primeiro = L2.Primeiro;
    L2.Ultimo = L1.Ultimo;

    printf("\n\n\t----------------L1 Invertido e Colocado em L2---------------------\n\n");
    for(int i = L2.Primeiro; i < L2.Ultimo; i++)
    {
        printf("\n\tNome: %s\n",L2.Item1[i].Nome);
        printf("\tMatricula: %d\n",L2.Item1[i].Matricula);
        printf("\tIdade: %d\n",L2.Item1[i].Idade);
    }
}
void Intercala_L1ComL2_Ordenados_Gerando_L3(TipoLista *L1,TipoLista *L2,TipoLista *L3)
{
    int x=0,y=0,i=0;
    for(i = 0; i < (L1->Ultimo + L2->Ultimo); i++)
    {
        if(i%2==0)
        {
            L3->Item2[i] = L1->Item1[y];
            y++;
        }
        else
        {
            L3->Item2[i] = L2->Item1[x];
            x++;
        }
    }

    printf("\n\n\t------------L1 com L2 Ordenados, Intercalados Gerando L3-----------\n");
    for(i = L2->Primeiro; i < (L1->Ultimo + L2->Ultimo); i++)
    {
        printf("\nNome: %s\n",L3->Item2[i].Nome);
        printf("Matricula: %d\n",L3->Item2[i].Matricula);
        printf("Idade: %d\n",L3->Item2[i].Idade);
    }
    printf("\n");
}

int Elimina_L1(Apontador P, TipoLista *L1,TipoItem *Item)
{
    if(Lista1_Vazia(*L1))
    {
        printf("\n\tLista L1 está Vazia!\n");
        return (0);
    }

    int i;
    for(i = L1->Primeiro; i < L1->Ultimo; i++)
    {
        if(L1->Item1[i].Matricula == P)
        {
            Retira_Lista(i + 1, L1, Item);
        }
    }
}

int Retira_Lista(Apontador P, TipoLista *L1, TipoItem *Item)
{
    int Aux=0;
    if(Lista1_Vazia(*L1) || P - 1   >= L1->Ultimo)
    {
        return (0);
    }

    *Item = L1->Item1[P - 1];
    L1->Ultimo--;
    for(Aux = P; Aux < L1->Ultimo; Aux++)
    {
        L1->Item1[Aux - 1] = L1->Item1[Aux];
    }

    printf("\nUltimo = %d",L1->Ultimo);
}
