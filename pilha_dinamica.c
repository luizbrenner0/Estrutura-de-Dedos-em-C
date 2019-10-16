#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef int bool;

#define true 0;
#define false -1;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox; 
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
} PILHA;



void pilhaStart (PILHA* P){
    P->topo = NULL;
}

int pilhaTamanho (PILHA* P){
    PONT end = P->topo;
    int tam = 0;
    while (end != NULL){
        tam++;
        end = end->prox;
    }
    return tam;
}

bool estaVazia (PILHA* P){
    if (P->topo == NULL)
        return true;
    return false;
}

void pilhaExibir (PILHA* P){
    PONT end  = P->topo;
    printf ("Pilha: \" ");
    while (end != NULL){
        printf ("%i ", end->reg.chave);
        end = end->prox;
    }
    printf ("\"\n");
}

bool pilhaPush (PILHA* P, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = P->topo;
    P->topo = novo;
    return true;
}

bool pilhaPop(PILHA* P, REGISTRO* reg){
    if (P->topo == NULL) return false;
    *reg = P->topo->reg;
    PONT apagar = P-> topo;
    P->topo = P->topo->prox;
    free (apagar);
    return true;
}

void pilhaRestart(PILHA* P){
    PONT apagar;
    PONT posicao = P->topo;
    while (posicao != NULL){
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    P->topo = NULL;
}

int main (){
    printf ("Hello World!\n");
    return 0;
}