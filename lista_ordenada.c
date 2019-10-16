#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50

#define INVALIDO -1

typedef int TIPOCHAVE;

typedef char NOMINAL[40];

typedef struct {
    TIPOCHAVE chave; 
    NOMINAL cor; 
    NOMINAL forma;
} REGISTRO;

typedef struct {//
    REGISTRO reg; 
    int prox;
} ELEMENTO;

typedef struct 
{
    ELEMENTO A[MAX]; 
    int inicio; 
    int dispo;
} LISTA;

void listaStart (LISTA* L)
{
    int i;
    for (i = 0 ; i < MAX - 1 ; i++)
        L->A[MAX-1].prox = INVALIDO;
    L->inicio = INVALIDO;
    L->dispo = 0;
}

int listaTamanho (LISTA* L)
{
    int i = L->inicio;
    int tam = 0;
    while (i =! INVALIDO)
    {
        tam++;
        i = L->A[i].prox;
    }
    return tam;
}

void listaExibir (LISTA* L){
    int i = L->inicio;
    printf ("Lista: \" ");
    while (i != INVALIDO)
    {
        printf ("%d ", L->A[i].reg.chave);
        i = L->A[i].prox;
    }   
    printf ("\"\n");
}

int buscaSequencialOrd (LISTA* L, TIPOCHAVE ch)
{
    int i = L->inicio;
    while (i != INVALIDO && L->A[i].reg.chave < ch)
        i = L->A[i].prox;
    if (i != INVALIDO && L->A[i].reg.chave == ch)
        return i;
    else return INVALIDO;
}

int obterNo (LISTA* L)
{
    int resultado = L->dispo;
    if (L->dispo != INVALIDO)
        L->dispo = L->A[L->dispo].prox;
    return resultado;
}

void devolverNo (LISTA* L, int j)
{
    L->A[j].prox = L->dispo;
    L->dispo = j; 
}
bool inserirElemListaOrd (LISTA* L, REGISTRO reg)
{
    if (L->dispo == INVALIDO)
        return false;
    int i = L->inicio;
    int anterior = INVALIDO;
    TIPOCHAVE ch = reg.chave;
    while ((i != INVALIDO) && (L->A[i].reg.chave < ch))
    {
        anterior = i;
        i = L->A[i].prox;
    }
    if ((i != INVALIDO) && (L->A[i].reg.chave == ch))
        return false;
    i = obterNo(L);
    L->A[i].reg = reg;
    if (anterior == INVALIDO)
    {
        L->A[i].prox = L->inicio;
        L->inicio = i;
    }
    else
    {
        L->A[i].prox = L->A[anterior].prox;
        L->A[anterior].prox = i;
    }
    return true;
    
}

void listaRestart (LISTA* L)
{
    listaStart (L);
}
int main (){
    printf ("Hello Lista Ordenada!\n");
    return 0;

}

//==================================