/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 24/09/2026
Objetivo    : Carteiro
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int busca_bin(int v[], int x, int n);

int main(){
    int N, M, *R, d_total=0, pos_i=0;
    scanf("%d", &N);
    scanf("%d", &M);

    R = (int *) malloc(N*sizeof(int));
    for (int i=0; i<N; i++){
        scanf("%d", &R[i]);
    }

    for(int i=0; i<M; i++){
        int pos_f, distancia, encomenda;
        scanf("%d", &encomenda);
        pos_f = busca_bin(R, encomenda, N);
        distancia = pos_f - pos_i;
        if (distancia<0){
        distancia = -1*distancia;
        }
        d_total += distancia;
        pos_i = pos_f;

        distancia = 0;
    }

    printf("%d\n", d_total);

    free(R);
    return 0;
}

int busca_bin (int v[], int x, int n) {
    int e, m, d;
    e = -1; d = n;
    while (/*X*/ e < d - 1) {
        m = (e + d)/2;
        if (v[m] < x) e = m;
        else d = m;
    }
return d;
}