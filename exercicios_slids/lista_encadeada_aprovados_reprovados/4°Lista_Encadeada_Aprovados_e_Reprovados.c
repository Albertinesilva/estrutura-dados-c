#include <stdio.h>
#include <stdlib.h>

typedef int Tipochave;

typedef struct
{
    Tipochave matricula;
    float nota;
    char curso[20];

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
    int tamanho;

} TipoLista;

void Aprovados_e_Reprovados(TipoLista *Lista, TipoLista *aprovados, TipoLista *reprovados);
void Inicia(TipoLista *Lista);
int Vazia(TipoLista *Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Remove (Apontador p, TipoLista *Lista, TipoItem *Item);
void Imprime (TipoLista Lista);

int main()
{
    TipoLista Lista, aprovados, reprovados;
    TipoItem x;
    int op;

    Inicia(&Lista);
    Inicia(&aprovados);
    Inicia(&reprovados);
    do
    {
        printf("\nDigite a Matricula: ");
        scanf("%d",&x.matricula);
        fflush(stdin);
        printf("\nDigite o curso: ");
        gets(x.curso);
        fflush(stdin);
        printf("\nDigite a Nota: ");
        scanf("%f",&x.nota);
        Insere(x,&Lista);

        printf("\n0 - Sair\n1 - Continuar\n");
        scanf("%d",&op);
        system("cls");
    }
    while(op != 0);
    printf("\n------------Alunos------------\n");
    Imprime (Lista);

    Aprovados_e_Reprovados(&Lista, &aprovados, &reprovados);
    printf("\n----------Aprovados-----------\n");
    Imprime (aprovados);

    printf("\n----------Reprovados----------\n");
    Imprime (reprovados);

    return 0;
}

void Inicia(TipoLista *Lista)
{
    Lista->Primeiro = (Apontador) malloc (sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TipoLista *Lista)
{
    return (Lista->Primeiro == Lista->Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (Apontador) malloc (sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->tamanho = Lista->tamanho + 1;
}

void Remove (Apontador p, TipoLista *Lista, TipoItem *Item)
{
    /*obs: o item a ser retirado e o seguinte ao apontado por p*/
    Apontador pAux;
    if(Vazia(Lista) || p == NULL || p->Prox == NULL)
    {
        printf("\nErro Lista Vazia ou posição não existe\n");
        return;
    }
    pAux = p->Prox;
    *Item = pAux->Item;
    p->Prox = pAux->Prox;
    if(p->Prox == NULL)
    {
        Lista->Ultimo = p;
        free(pAux);
        Lista->tamanho = Lista->tamanho - 1;
    }
}

void Imprime (TipoLista Lista)
{
    Apontador Aux;
    Aux = Lista.Primeiro->Prox;
    while(Aux != NULL)
    {
        printf("Matricula: %d\n",Aux->Item.matricula);
        printf("Curso: %s\n",Aux->Item.curso);
        printf("Nota: %f\n\n",Aux->Item.nota);
        Aux = Aux->Prox;
    }
}

void Aprovados_e_Reprovados(TipoLista *Lista, TipoLista *aprovados, TipoLista *reprovados)
{
    Apontador aux = Lista->Primeiro->Prox;
    while(aux != NULL)
    {
        if(aux->Item.nota >= 7)
        {
            Insere(aux->Item, aprovados);
        }
        else
        {
            Insere(aux->Item, reprovados);
        }
        aux = aux->Prox;
    }
}

