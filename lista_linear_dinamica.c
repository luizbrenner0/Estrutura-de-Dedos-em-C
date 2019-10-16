#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TIPOCHAVE;
typedef struct {TIPOCHAVE chave;} REGISTRO;
typedef struct aux {REGISTRO reg; struct aux* prox;} ELEMENTO;
typedef ELEMENTO* PONT;
typedef struct {PONT inicio;} LISTA;

void listaStart (LISTA* L)
{
    L->inicio = NULL;
}

int listaTamanho (LISTA* L)
{
    PONT end = L->inicio;
    int tam = 0;
    while (end != NULL)
    {
        tam ++;
        end = end->prox;
    }
    return tam;
}

PONT buscaSequencial (LISTA* L, TIPOCHAVE ch)
{
    PONT pos = L->inicio;
    while (pos != NULL)
    {
        if (pos->reg.chave == ch) 
            return pos;
        pos = pos->prox;
    }
    return NULL;
}

PONT buscaSeqOrd (LISTA* L, TIPOCHAVE ch)
{
    PONT pos = L->inicio;
    while (pos != NULL && pos->reg.chave < ch) 
        pos = pos->prox;
    if (pos != NULL && pos->reg.chave == ch) 
        return pos;
    return NULL;
}

int main ()
{
    printf("Ola mundo\n");
    return 0;
}