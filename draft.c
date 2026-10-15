//TREINO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PILHA

typedef struct celula{
    int valor;
    struct celula *seg;
}celula;

typedef struct Pilha{
    celula *topo;
}Pilha;

void inicializar(Pilha *P){
    P->topo = NULL;
}

int vazia(Pilha *P){
    if (P->topo == NULL){
        return 1;
    }
    return 0;
}

void push(Pilha *P, int v){
    celula *nova = malloc(sizeof(celula));
    nova->valor = v;
    nova->seg = P->topo;
    P->topo = nova;
}

int pop(Pilha *P){
    if (vazia(P)){
        return -1;
    }
    else{
        int v_topo = P->topo->valor;
        celula *temp = P->topo;
        P->topo = temp->seg;
        free(temp);
        return v_topo;
    }
}

void clear(Pilha *P){
    while (!vazia(P)){
        celula *temp = P->topo;
        P->topo = temp->seg;
        free(temp);
    }
}

//FILA

typedef struct celula{
    int valor;
    celula *seg;
}celula;

typedef struct Fila{
    celula *inicio;
    celula *fim;
}Fila;

void inicializar(Fila *F){
    F->inicio = NULL;
    F->fim = NULL;
}

int vazia(Fila *F){
    if (F->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void inserir(Fila *F, int v){
    celula *nova = malloc(sizeof(celula));
    nova->valor = v;
    nova->seg = NULL;
    if (vazia(F)){
        F->inicio = nova;
        F->fim = nova;
    }
    else{
        F->fim->seg = nova;
        F->fim = nova;
    }
}

int remover(Fila *F){
    if (vazia(F)){
        return -1;
    }
    else{
        int v_inicio = F->inicio->valor;
        celula *temp = F->inicio;
        F->inicio = temp->seg;
        if (F->inicio == NULL){
            F->fim = NULL;
        }
        free(temp);
        return v_inicio;
    }
}

void clear(Fila *F){
    while(!vazia(F)){
        celula *temp = F->inicio;
        F->inicio = temp->seg;
        free(temp);
    }
    F->fim = NULL;
}

// LISTA ENCADEADA

typedef struct celula{
    int valor;
    celula *seg;
}celula;

typedef struct Lista{
    celula *cabeca;
}Lista;

void inicializar(Lista *L){
    celula *cabeca = malloc(sizeof(celula));
}

int vazia(Lista *L){
    if (L->cabeca->seg == NULL){
        return 1;
    }
    return 0;
}

void inserir(Lista *L, int v){
    celula *nova = malloc(sizeof(celula));
    nova->valor = v;
    nova->seg = NULL;
    celula *temp = L->cabeca;
    while(temp->seg != NULL){
        temp = temp->seg;
    }
    temp->seg = nova;
}

int remover(Lista *L){
    if (vazia(L)){
        return -1;
    }
    else{
        int v_inicio = L->cabeca->seg->valor;
        celula *temp = L->cabeca->seg;
        L->cabeca->seg = temp->seg;
        free(temp);
        return v_inicio;
    }
}

void clear(Lista *L){
    while (!vazia(L)){
        celula *temp = L->cabeca->seg;
        L->cabeca->seg = temp->seg;
        free(temp);
    }
}

//BUSCA BINÁRIA

int busca_binaria(int v[], int t, int x){
    int inicio = 0;
    int fim = t-1;
    int meio;

    while(inicio <= fim){
        meio = (inicio + (fim - inicio)) / 2;
        if (v[meio] == x){
            return meio;
        }
        if (x < meio){
            fim = meio-1;
        } 
        if (x > meio){
            inicio = meio + 1;
        }
    }
}
