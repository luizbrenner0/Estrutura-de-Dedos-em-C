#include <stdio.h>
#define MAX 10
#define true 1
#define false 0

//tipo abstrato de dado:

typedef int bool;

typedef char TIPONOME [64];

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    TIPONOME nome;
} REGISTRO;

typedef struct {
    REGISTRO A [MAX];
    int topo;
} PILHA;

//inicializar pilha:

void pilhaStart (PILHA* P){
    P->topo = -1;
}

//exibe tamanho da pilha:

int pilhaTamanho (PILHA* P){
    return P->topo + 1;
}

//exibir elementos da pilha:

void pilhaExibir (PILHA* P){
    printf ("Pilha: \" ");
    int i;
    for (i = P->topo ; i >= 0 ; i--)
        printf ("%d ", P->A[i].chave);
    printf ("\"\n");
}

//inserção de elemento na pilha (push):

bool pilhaPush (PILHA* P, REGISTRO reg){
    if (P->topo >= MAX-1) return false;
    P->topo = P->topo + 1;
    P->A[P->topo] = reg;
    return true;
}

//exclusão de elemento na pilha (pop):

bool pilhaPop (PILHA* P, REGISTRO* reg){
    if (P->topo == -1) return false;
    *reg = P->A[P->topo];
    P->topo = P->topo - 1;
    return true;
}

//reiniciar pilha:

void pilhaRestart (PILHA* P){
    P->topo = -1;
}

//-----------------------------------

int main (){
    printf ("Hello World!\n");
    return 0;
}