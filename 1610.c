/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 21/08/2026
Objetivo    : Contabilizar total de cada cobaia animal e porcentagem
Dificuldade : Nenhum
Uso de IA   : Auxílio na explicação de erros
-------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>

int** init_matriz(int tam){
    int ** M = malloc(tam * sizeof(int *));
    for (int i=0; i<tam; i++){
        M[i] = (int*) malloc(tam * sizeof(int));
    }
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            M[i][j] = 0;
        }
    }
    return M;
}



void del_matriz(int** M, int tam){
    for (int i=0; i<tam; i++){
        free(M[i]);
    }
    free(M);
}


int DFS(int** M, int tam, int v, int* estado){
    estado[v] = 1;
    for (int i = 0; i < tam; i++){
        if (M[v][i] == 1){
            if (estado[i] == 1){
                return 1;
            }
            if (estado[i] == 0 && DFS(M, tam, i, estado)){
                return 1;
            }
        }
    }
    estado[v] = 2;
    return 0;
}


void verifica_caso(int** M, int tam, int dep){
    for (int i=1; i<=dep; i++){
        int x,y;
        scanf("%d", &x);
        scanf("%d", &y);
        x -= 1;
        y -= 1;
        M[x][y] = 1;
    }

    int estado[tam];
    for (int i = 0; i < tam; i++){
        estado[i] = 0;
    }

    int ciclo = 0;
    for (int i = 0; i < tam && !ciclo; i++){
        if (estado[i] == 0 && DFS(M, tam, i, estado)){
            ciclo = 1;
        }
    }

    if (ciclo){
        printf("SIM\n");
    }
    else{
        printf("NAO\n");
    }
}


int main(){
    int T;
    scanf("%d", &T);
    for (int i=1; i<=T; i++){
        int tam, dep;
        scanf(" %d", &tam);
        scanf("%d", &dep);
        int** M = init_matriz(tam);
        verifica_caso(M, tam, dep);
        del_matriz(M, tam);
    }

    return 0;
}