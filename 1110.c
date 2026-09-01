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

typedef struct Node {
    int dado;
    struct Node* proximo;
} Node;

typedef struct Fila {
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

Fila* criaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
    return f;
}

int estavazia(Fila* f){
    return f->inicio == NULL;
}

void enfileirar(Fila* f, int valor){
    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->dado = valor;
    novoNode->proximo = NULL;

    if (f->fim == NULL){
        f->inicio = f->fim = novoNode;
    }
    else{
        f->fim->proximo = novoNode;
        f->fim = novoNode;
    }
    f->tamanho++;
}

int desenfileirar(Fila* f){
    if (estavazia(f)){
        return -1;
    }

    Node* temp = f->inicio;
    int valor = temp->dado;
    
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL){
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;
    return valor;
}

void liberarFila(Fila* f){
    while (!estavazia(f)){
        desenfileirar(f);
    }
    free(f);
}

int main(){
    int n;

    while(scanf("%d", &n) == 1 && n!= 0){
        Fila* f = criaFila();

        for (int i=1; i<=n; i++){
            enfileirar(f, i);
        }

        printf("Discarded cards:");
        int primeiroDescarte = 1;

        while(f->tamanho > 1){
            int descartada = desenfileirar(f);
            if (primeiroDescarte == 1){
                printf(" %d", descartada);
                primeiroDescarte = 0;
            }
            else{
                printf(", %d", descartada);
            }

            int movida = desenfileirar(f);
            enfileirar(f, movida);
        }

        printf("\nRemaining card: %d\n", desenfileirar(f));
        liberarFila(f);
    }

    return 0;
}