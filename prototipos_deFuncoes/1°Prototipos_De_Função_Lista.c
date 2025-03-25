#include <stdio.h>
#include <Stdlib.h>
#include <locale.h>


//Função para localizar elemento de uma lista
int Localizar_Elemento(TipoLista *L1, int Elemento)
{
    int Localizado = -1;

    if(Lista_Vazia(*L1))
    {
        Printf("\nLista Vazia!\n");
        fflush(stdin);
        return;
    }

    for(int i = 0; i < L1->Ultimo; i++)
    {
        if(L1->Ultimo[i].Chave == Elemento)
        {
            Localizado = i;
        }
    }

    if(Localizado == - 1)
    {
        Printf("\nElemento não Localizado!\n");
        fflush(stdin);
        return - 1;
    }
    else
    {
        return Localizado;
    }

}

//Função para Ordenar Lista Estatica
int Ordenar_Lista(TipoLista *L1)
{
    int i, j;
    TipoItem Temp;

    if(Lista_Vazia(*L1))
    {
        printf("\nLista Vazia!\n");
        fflush(stdin);
        return;
    }

    for(i = 0; i < L1->Ultimo; i++)
    {
        for(j = 0; j < L1->Ultimo - 1; j++)
        {
            if(L1->Item[j].chave < L1->Item[j + 1].chave)
            {
                Temp = L1->Item[j];
                L1->Item[j] = L1->Item[j + 1];
                L1->Item[j + 1] = Temp;
            }
        }
    }

}

int Busca_Lista(TipoLista *Lista, TipoChave chave)
{
    int Inicio, Meio, Final, i;
    Inicio = Lista->Primeiro;
    Final = Lista->Ultimo;
    i = Lista->Primeiro;

    while(Inicio <= Final)
    {
        Meio = (Inicio + Final)/2;

        //if(chave == Lista->Itens[Meio].chave)
        //{
        //return i = Meio + 1;
        //}
        if(chave < Lista->Itens[Meio].chave)
        {
            Final = Meio - 1; //Busca na metade da esquerda
        }
        else
        {
            if(chave > Lista->Itens[Meio].chave)
            {
                Inicio = Meio + 1; //Busca na metade da direita
            }
            else
            {
                return Meio + 1;
            }
        }

    }

    return - 1; // Elemento não encontrado

}

//Função para Remover elementos de lista estatica
int Retira_Lista(Apontador P, TipoLista *L1, TipoItem *Item)
{
    int Aux=0;
    if(Lista1_Vazia(*L1) || P   >= L1->Ultimo)
    {
        return (0);
    }
    *Item = L1->Item1[P - 1];
    printf("\nRetira %s",&Item->Nome);
    for(Aux = P; Aux < L1->Ultimo; Aux++)
    {
        L1->Item1[Aux -1] = L1->Item1[Aux];
        L1->Ultimo--;
    }
}

//Função para eliminar um elemento da Lista atraves de um número de Matricula, Nota, Nome, etc...
int Elimina_L1(Apontador P, TipoLista *L1,TipoItem *Item)
{
    if(Lista1_Vazia(*L1))
    {
        printf("\n\tLista L1 está Vazia!\n");
        return (0);
    }

    int i = L1->Primeiro;
    while((i < L1->Ultimo) || (P >= L1->Item1[i].Matricula))
    {
        if(L1->Item1[i].Matricula == P)
        {
            printf("i = %d",i);
            Retira_Lista(i + 1, L1, Item);
            i--;
        }
        i++;
    }
}

//Função que intercala duas Listas, para formar outra
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

//Função que inverte uma lista para colocar em outra
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


//Função que faz uma copia da Lista 1 para Lista 2
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

//Função que ordena um Lista a moda antiga
void Ordenar_L1(TipoLista *L1, TipoLista *L2)
{
    int i,j;
    int aux_idade, aux_matricula;
    char aux_nome[50];

    for(i = L1->Primeiro; i < L1->Ultimo; i++)
    {
        for(j = i + 1; j < L1->Ultimo; j++)
        {
            if(L1->Item1[i].Idade > L1->Item1[j].Idade)
            {
                aux_idade = L1->Item1[i].Idade;
                L1->Item1[i].Idade = L1->Item1[j].Idade;
                L1->Item1[j].Idade = aux_idade;

                aux_matricula = L1->Item1[i].Matricula;
                L1->Item1[i].Matricula = L1->Item1[j].Matricula;
                L1->Item1[j].Matricula = aux_matricula;

                strcpy(aux_nome, L1->Item1[i].Nome);
                strcpy(L1->Item1[i].Nome, L1->Item1[j].Nome);
                strcpy(L1->Item1[j].Nome, aux_nome);
            }
        }
    }
    fflush(stdin);
    for(i = L2->Primeiro; i <= TamMax1; i++)
    {
        for(j = i + 1; j <= TamMax1; j++)
        {
            if(L2->Item1[i].Idade > L2->Item1[j].Idade)
            {
                aux_idade = L2->Item1[i].Idade;
                L2->Item1[i].Idade = L2->Item1[j].Idade;
                L2->Item1[j].Idade = aux_idade;

                aux_matricula = L2->Item1[i].Matricula;
                L2->Item1[i].Matricula = L2->Item1[j].Matricula;
                L2->Item1[j].Matricula = aux_matricula;

                strcpy(aux_nome, L2->Item1[i].Nome);
                strcpy(L2->Item1[i].Nome, L2->Item1[j].Nome);
                strcpy(L2->Item1[j].Nome, aux_nome);
            }
        }
    }
}

//Busca estatica
int Busca(TipoLista *Lista, TipoChave chave)
{
    int P = 0, i = Lista->Ultimo;

    while(i != Lista->Ultimo)
    {
        if(Lista->Item[i].chave == chave)
        {
            P = i + 1;
            return P;
        }
        i++;
    }
    return P; //se não entrar no (if) P retorna (0)
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

    printf("\n\t%d Aluno Inserido com Sucesso!",Lista->Tamanho);
    getchar();

}


//Concatena uma Lista encadeada com outra lista encadeada
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

//Busca Dinamica
void Busca(TipoLista *Lista, TipoChave chave, Apontador *P, Apontador *Ant)
{
    *Ant = Lista->Primeiro;
    Apontador Aux = Lista->Primeiro->Prox;

    while(Aux != NULL)
    {
        if(Aux->Item.chave == chave)
        {
            *P = Aux;
            break;
        }
        Aux = Aux->Prox;
        *Ant = *Ant->Prox;
    }
}

//zerar Lista
void Zera_Lista(TipoLista *Lista)
{
    Apontador Aux, Pos;
    Aux = Lista->Primeiro->prox;

    while(Aux != NULL)
    {
        Pos = Aux->Prox;
        free(Aux);
        Aux = Pos;
    }

    Lista->Primeiro =  (Apontador)malloc(sizeof(struct TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->Tamanho = 0;

    printf("\n\tLista Zerada!...\n");
}

int main()
{
    setLocale(LC_ALL,"portuguese");

    return 0;
}
