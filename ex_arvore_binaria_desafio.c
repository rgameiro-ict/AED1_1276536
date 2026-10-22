/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : Exercício: Árvore Binária de Busca
Data        : 22/10/2026
Objetivo    : leia N números inteiros distintos e insira esses números,
na ordem de leitura, em uma árvore binária de busca. Depois, imprima os
valores utilizando o percurso em ordem (in-order traversal).
Dificuldade : Nenhuma
Uso de IA   : Não usei
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No* dir;
}No;

No* criar_no(int val);
void inserir_arvore(No* raiz, int val);
void print_arvore(No* raiz);


int main(){
    int N;
    No *raiz = NULL;
    if (scanf("%d", &N) == 1) {
        raiz = criar_no(N);
        while(scanf("%d", &N) != EOF){
            inserir_arvore(raiz, N);
        }
        
        print_arvore(raiz);
    }

    return 0;
}

No* criar_no(int val){
    No* novo = malloc(sizeof(No));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = val;
    return novo;
}

void inserir_arvore(No* raiz, int val){
    if(val < raiz->valor && raiz->esq == NULL){
        raiz->esq = criar_no(val);
        return;
    }
    if(val > raiz->valor && raiz->dir == NULL){
        raiz->dir = criar_no(val);
        return;
    }
    else {
        if(val < raiz->valor) inserir_arvore(raiz->esq, val);
        else inserir_arvore(raiz->dir, val);
    }
}


void print_arvore(No* raiz){
    if(raiz != NULL){
        print_arvore(raiz->esq);
        printf("Conteudo: %d\n", raiz->valor);
        print_arvore(raiz->dir);
    }
}