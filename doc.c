/* ALGORITMOS DE LISTAS, ÁRVORES, GRAFOS, BUSCAS E ORDENAÇÕES PADRÕES PARA CONSULTA  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//------------------------------------- ~~~ LISTAS ENCADEADAS ~~~ -------------------------------------


// -------------------------- PILHAS --------------------------

typedef struct cel{
    int valor;
    struct cel *seg;
} celula;

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
        printf("Está vazia");
        return -1;
    }
    else{
        int v_topo = P->topo->valor;
        celula *temp = P->topo;
        P->topo = P->topo->seg;
        free(temp);
        return v_topo;
    }
}

void clear(Pilha *P){
    while(!vazia(P)){
        celula *temp = P->topo;
        P->topo = P->topo->seg;
        free(temp);
    }
}

// -------------------------- FILA --------------------------

typedef struct celula{
    int valor;
    struct celula *seg;
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
    return 0;
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
        printf("Está vazia");
        return -1;
    }
    else{
        int v_inicio = F->inicio->valor;
        celula *temp = F->inicio;
        F->inicio = F->inicio->seg;
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
        F->inicio = F->inicio->seg;
        free(temp);
    }
    F->fim = NULL;
}

//-------------------------- LISTA ENCADEADA --------------------------

typedef struct celula{
    int valor;
    celula *seg;
}celula;

typedef struct Lista{
    celula *cabeca;
}Lista;

void inicializar(Lista *L){
    L->cabeca = malloc(sizeof(celula));
    L->cabeca->seg = NULL;
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
    nova->seg = L->cabeca->seg;
    L->cabeca->seg = nova;
}

int remover(Lista *L){
    if (vazia(L)){
        printf("Está vazia");
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
    while(!vazia(L)){
        celula *temp = L->cabeca->seg;
        L->cabeca->seg = temp->seg;
        free(temp);
    }
}


//------------------------------------- ~~~ ORDENAÇÃO ~~~ -------------------------------------


// QUICK SORT
int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++){
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void Quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
    }
}

// MERGE SORT
void Intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r){
        if (v[i] <= v[j]){
            w[k++] = v[i++];
        }
        else{
            w[k++] = v[j++];
        }
    }
    while (i < q){
        w[k++] = v[i++];
    }
    while (j < r){
        w[k++] = v[j++];
    }
    for (i = p; i < r; i++){
        v[i] = w[i-p];
    }
    free (w);
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
    }
}

