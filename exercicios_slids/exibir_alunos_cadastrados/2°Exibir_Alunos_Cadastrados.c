#include <stdio.h>
#include <stdlib.h>
#define InicioVetor 0
#define Maxtam 100

typedef int Tipochave;

typedef int Apontador;

typedef struct
{
    Tipochave chave;
    char nome[50],curso[50];
    int idade;
} TipoItem;

typedef struct
{
    TipoItem itens[Maxtam];
    Apontador Primeiro, Ultimo;
} TipoLista;

void Iniciar_Lista(TipoLista *Lista);
int Insere_Lista(TipoItem x,TipoLista *Lista);
int Lista_Vazia(TipoLista Lista);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);
void ImprimeLista(TipoLista Lista);

int main()
{
    TipoItem aluno;
    TipoLista Lista;
    Iniciar_Lista(&Lista);
    int op,cont = 1;

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
        printf("Digite a idade: ");
        scanf("%d",&aluno.idade);

        Insere_Lista(aluno,&Lista);
        printf("\n0 - Sair \n1 - Continuar\nEntrada: ");
        scanf("%d",&op);
        cont++;
    }
    while(op != 0);

    ImprimeLista(Lista);

    system("pause");
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

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return;
    }
    *Item = Lista->itens[p-1];
    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->itens[Aux -1] = Lista->itens[Aux];
        Lista->Ultimo--;
    }
}

void ImprimeLista(TipoLista Lista)
{
    int Aux;
    printf("\n//****Lista****//\n\n");
    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\nNome: %s\nCurso: %s\nIdade: %d\n",Lista.itens[Aux].nome,Lista.itens[Aux].curso,Lista.itens[Aux].idade);
    }
}
