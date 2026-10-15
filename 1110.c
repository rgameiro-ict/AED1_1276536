/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 01/09/2026
Objetivo    : Enquanto houver pelo menos 2 cartas, descartar a primeira e colocar a próxima no fundo
Dificuldade : Aprender a sintaxe e implementação de Listas Encadeadas
Uso de IA   : Aprendizado de implementação de Listas Encadeadas: Sintaxe e Estrutura geral
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Definir Lista Encadeada

typedef struct cel{
    int valor;
    struct cel *seg;
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

void enfileirar(Fila *F, int v){
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

int desenfileirar(Fila *F){
    if (vazia(F)){
        printf("Eatá vazia");
        return -1;
    }
    else{
        int v_inicio = F->inicio->valor;
        celula *temp = F->inicio;
        F->inicio = F->inicio->seg;
        if (F->inicio->valor == NULL){
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

// Corpo Principal

int main(){
    int N;
    Fila F;





    return 0;
}