#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define InicioVetor 0
#define Maxtam 6

typedef int Tipochave;

typedef int Apontador;

typedef struct
{
    Tipochave chave;
    char nome[50],curso[50];
    float nota;
} TipoItem;

typedef struct
{
    TipoItem itens[Maxtam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void Iniciar_Lista(TipoLista *Lista);
int Insere_Lista(TipoItem x,TipoLista *Lista);
int Lista_Vazia(TipoLista Lista);
int Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);
void Retira_Valor(TipoLista *Lista, float z);
void ImprimeLista(TipoLista Lista);

int main()
{
    setlocale(LC_ALL,"portuguese");
    TipoItem aluno;
    TipoLista Lista;
    Iniciar_Lista(&Lista);
    int op,cont = 1;
    float x = 5;
    do
    {
        system("cls");
        aluno.chave = cont;
        fflush(stdin);
        printf("Digite o nome do aluno: ");
        gets(aluno.nome);
        fflush(stdin);
        printf("Digite o nome do curso: ");
        gets(aluno.curso);
        fflush(stdin);
        printf("Digite a Nota: ");
        scanf("%f",&aluno.nota);

        Insere_Lista(aluno,&Lista);
        printf("\n0 - Sair \n1 - Continuar\nEntrada: ");
        scanf("%d",&op);
        cont++;
    }
    while(op != 0);

    ImprimeLista(Lista);
    Retira_Valor(&Lista,x);
    printf("\n-----Apos Remoção-----\n");
    ImprimeLista(Lista);

    return 0;
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
    if(Lista->Ultimo > Maxtam -1)
    {
        return (0);
    }
    else
    {
        Lista->itens[Lista->Ultimo] = x;
        Lista->Ultimo++;

        return(1);
    }
}

int Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return (0);
    }
    *Item = Lista->itens[p-1];
    for(Aux = p; Aux <= Lista->Ultimo; Aux++)
    {
        Lista->itens[Aux -1] = Lista->itens[Aux];
        Lista->Ultimo--;
    }
}

void Retira_Valor(TipoLista *Lista,float z)
{
    int i;
    TipoItem Item;
    for(i = Lista->Primeiro; i < Lista->Ultimo; i++)
    {
        if(Lista->itens[i].nota > z)
        {
            Retira_Lista(i+1,Lista,&Item);
            i--;
        }
    }
}
void ImprimeLista(TipoLista Lista)
{
    int Aux;
    for(Aux = Lista.Primeiro; Aux <= Lista.Ultimo-1; Aux++)
    {
        printf("\nNome: %s\nCurso: %s\nNota: %f\n",Lista.itens[Aux].nome,Lista.itens[Aux].curso,Lista.itens[Aux].nota);
    }
}

