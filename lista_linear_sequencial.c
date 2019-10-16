#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#define MAX 10
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
}REGISTRO;


typedef struct
{
    REGISTRO A[MAX+1];
    int nroElem;
}LISTA;


void listaStart(LISTA L)
{
    L.nroElem = 0;
}


void listaStartREG(LISTA* L)
{
    L->nroElem = 0;
}


int tamanho(LISTA* L)
{
    return L->nroElem;
}


void listaPrint(LISTA* L)
{
    int i;
    printf("Lista: \" ");
    for (i=0 ; i<L->nroElem ; i++)
        printf("%d ", L->A[i].chave);
    printf("\"\n");
}



int buscaSequencial(LISTA* L, TIPOCHAVE CH)
{
    int i = 0;
    while (i < L->nroElem)
    {
        if (CH == L->A[i].chave) return i;
        else i++;
    }
    return -1;
}


int buscaSentinela(LISTA* L, TIPOCHAVE ch)
{
    int i = 0;
    L->A[L->nroElem].chave = ch;
    while (L->A[i].chave != ch) i++;
    if (i == L->nroElem) return -1;
    else return i;
}


int buscaBinaria(LISTA* L, TIPOCHAVE ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = L->nroElem-1;
    while (esq <= dir)
        {
        meio = ((esq + dir) / 2);
        if (L->A[meio].chave == ch)return meio;
        else{
            if (L->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
    }
    return -1;
}


bool listaInsElem(LISTA* L, REGISTRO REG, int I)
{
    int j;
    if ((L->nroElem == MAX) || (I < 0) || (I > L->nroElem))
        return false;
    for (j = L->nroElem; j > I; j--)
        L->A[j] = L->A[j-1];
    L->A[I] = REG;
    L->nroElem++;
    return true;
}


bool listaDelElem(TIPOCHAVE CH, LISTA* L)
{
    int pos, j;
    pos = buscaSequencial(L, CH);
    if (pos == -1) return false;
    for (j=pos ; j<L->nroElem-1 ; j++)
        L->A[j] = L->A[j+1];
    L->nroElem--;
    return true;
}


bool listaInsElemOrdem(LISTA* L, REGISTRO reg)
{
    if  (L->nroElem >= MAX) return false;
    int pos = L->nroElem;
    while (pos > 0 && L->A[pos-1].chave > reg.chave)
    {
        L->A[pos] = L->A[pos-1];
        pos--;
    }
    L->A[pos] = reg;
    L->nroElem++;
}



void listaRestart(LISTA* L)
{
    L->nroElem = 0;
}

int main (){
    printf("Hello Lista Sequencial!\n");
    return 0;
}

