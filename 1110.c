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

typedef struct celula{
    int valor;
    struct celula *seg;
}celula;

typedef struct Lista{
    celula *cabeca;
}Lista;

void inicializar(Lista *L, int N){
    L->cabeca = malloc(sizeof(celula));
    L->cabeca->seg = NULL;
    for(int i=1; i<=N; i++){
        inserir(L, i);
    }
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

// Corpo Principal

int main(){
    int N;
    Lista L;
    while(scanf("%d", &N) == 1 && N != 0){
        inicializar(&L, N);
        printf("Discarded cards: ");
        int primeiro = 1;
        for(int i=1; i<=N-1; i++){
            int carta_descartada = remover(&L);
            if (primeiro){
                printf("%d", carta_descartada);
                primeiro = 0;
            }
            else {
                printf(", %d", carta_descartada);
            }
            inserir(&L, remover(&L));
        }
        printf("\nRemaining card: %d\n", remover(&L));
        clear(&L);
    }

    return 0;
}