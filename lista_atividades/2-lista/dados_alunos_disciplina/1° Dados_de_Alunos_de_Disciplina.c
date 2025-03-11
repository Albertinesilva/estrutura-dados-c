#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef int TipoChave;

typedef struct
{
    TipoChave Matricula;
    char Nome[80];
    float Media;

} TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula
{
    TipoItem Item;
    Apontador Prox;

} TipoCelula;

typedef struct
{
    Apontador Primeiro, Ultimo;
    int Tamanho;

} TipoLista;

int Menu(int Opcao);

void Inicia_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista *Lista);

void Preencher_Lista(TipoItem Aluno, TipoLista *Lista);

void Insere_na_Lista(TipoItem x, TipoLista *Lista);

void Insere_Lista_Ordenada(TipoItem Aluno, TipoLista *Lista);

void Busca(TipoLista *Lista, TipoChave chave, Apontador *Pos, Apontador *Ant);

void Remove_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

void Imprime_Lista(TipoLista Lista);


int main()
{
    setlocale(LC_ALL,"Portuguese");

    TipoItem Aluno, Item;
    TipoLista Lista;
    Apontador p, Pos, Ant;
    TipoChave chave;
    Lista.Tamanho = 0;

    int Opcao = 0, Iniciou_Lista = 0;
    while(Opcao != 5)
    {
        Opcao= Menu(Opcao);

        switch (Opcao)
        {

        case 1:

            Inicia_Lista(&Lista);
            printf("\n\tLista Inicializada!...\n\tEscolha a Opção Inserir Aluno.\n");
            Iniciou_Lista = Opcao;

            break;

        case 2:

            if(Iniciou_Lista != 1)
            {
                printf("\n\tA Lista Não Foi Inicializada!\n");
            }
            else
            {
                Preencher_Lista(Aluno, &Lista);
            }
            break;

        case 3:

            Imprime_Lista(Lista);

            break;

        case 4:

          if(Lista.Tamanho >= 1)
          {

            printf("\n\tInforme o número da matricula para remover da LISTA: ");
            fflush(stdin);
            scanf("%d",&chave);

            Busca(&Lista, chave, &Pos, &Ant);

            p = Ant;
            Remove_Lista(p, &Lista, &Item);

            printf("\n\n\t%s Removido do curso com a matricula %i e com a média %.1f\n\n",Item.Nome,Item.Matricula,Item.Media);
          }
          else
          {
              printf("\n\tA Lista esta Vazia!...\n\n");
          }
            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\tObrigado, Volte sempre!\n");

            break;
        }
    }
    return 0;
}

int Menu(int Opcao)
{
    printf("\n\t----------Inserir dados Ordenados----------\n");

    do
    {
        printf("\n\t1 - Iniciar Lista\n");
        printf("\t2 - Inserir Alunos Ordenados\n");
        printf("\t3 - Imprime Lista\n");
        printf("\t4 - Remover Aluno\n");
        printf("\t5 - Sair\n");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        system("cls");
    }
    while(Opcao > 5 || Opcao <= 0);

    return Opcao;
}

int Lista_Vazia(TipoLista *Lista)
{
    return (Lista->Primeiro == Lista->Ultimo);
}

void Inicia_Lista(TipoLista *Lista)
{
    Lista->Primeiro = (Apontador) malloc (sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;
}

void Preencher_Lista(TipoItem Aluno, TipoLista *Lista)
{
    int Quant_Alunos = 0;

    printf("\n\tQuantos Alunos, deve ser Armazenados: ");
    fflush(stdin);
    scanf("%d",&Quant_Alunos);
    system("cls");

    if(Quant_Alunos > 0)
    {

        while(Quant_Alunos != 0)
        {
            printf("\n\tQual o seu Nome? ");
            fflush(stdin);
            gets(Aluno.Nome);

            printf("\n\t%s Informe seu Número de Matricula: ",Aluno.Nome);
            fflush(stdin);
            scanf("%d",&Aluno.Matricula);

            printf("\n\t%s, Digite sua Média: ",Aluno.Nome,Aluno.Media);
            fflush(stdin);
            scanf("%f",&Aluno.Media);

            Insere_Lista_Ordenada(Aluno, Lista);

            Quant_Alunos--;

        }

    }
    else
    {
        printf("\n\tQuantidade de Alunos, não é valido!...\n\n");
    }

}

/*Função insere_Ordenado: Insere elemento em ordem*/
void Insere_Lista_Ordenada(TipoItem Aluno, TipoLista *Lista)
{
    Apontador Novo;
    Apontador Ant = NULL; /*Ponteiro para elemento anterior*/
    Apontador Aux = Lista->Primeiro->Prox;


    //Procura posição de inserção
    while(Aux != NULL && Aux->Item.Matricula < Aluno.Matricula)
    {
        Ant = Aux;
        Aux = Aux->Prox;
    }

    //Cria Novo elemento
    Novo = (Apontador) malloc (sizeof(TipoCelula));
    Novo->Item = Aluno;

    //Encadeia elemento
    if(Ant == NULL)
    {
        /*Insere elemento no Ínicio*/
        Novo->Prox = Lista->Ultimo->Prox;
        Lista->Ultimo->Prox = Novo;
    }
    else
    {
        /*Insere elemento no meio da lista*/
        Novo->Prox = Ant->Prox;
        Ant->Prox = Novo;
    }
    Lista->Tamanho = Lista->Tamanho + 1;

    printf("\n\t%d° Aluno Inserido com Sucesso!\n\n",Lista->Tamanho);
    getchar();


}

void Busca(TipoLista *Lista, TipoChave chave, Apontador *Pos, Apontador *Ant)
{
    Apontador Aux;
    Aux = Lista->Primeiro;

    while(Aux != NULL)
    {
        if(Aux->Item.Matricula == chave)
        {
            *Pos = Aux;

            break;
        }

        *Ant = Aux;
        Aux = Aux->Prox;
    }

}

void Remove_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    Apontador pAux;

    if(Lista->Tamanho == 0 || p == NULL || p->Prox == NULL)
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
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;

    while(Aux != NULL)
    {
        printf("\n\tNome %s\n\tMatricula %d\n\tNota %2.f\n",Aux->Item.Nome,Aux->Item.Matricula,Aux->Item.Media);
        Aux = Aux->Prox;
    }
}


