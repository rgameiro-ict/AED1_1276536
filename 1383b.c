/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Verificar um Sudoku com alocação dinâmica
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void le_matriz(int **matriz);
void verifica_matriz(int **matriz, int cont);
int verifica_linha(int *linha);
int verifica_coluna(int **matriz, int col);
int verifica_setor(int **matriz, int setor);


int main(){
    int **matriz, n, cont=1;
    matriz = (int **) malloc(9 * sizeof(int *));
    for (int i=0; i<9; i++){
        matriz[i] = (int*) malloc(9 * sizeof(int));
    }
    scanf("%d", &n);
    for (int a=0; a<n; a++){
        le_matriz(matriz);
        verifica_matriz(matriz, cont);
        cont++;
    }

    for (int i=0; i<9; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

void le_matriz(int **matriz){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

}

void verifica_matriz(int **matriz, int cont){
    int ver_lin, ver_col, ver_set=0;
    printf("Instancia %d\n", cont);
    for (int i=0; i<9; i++){
        ver_lin = verifica_linha(matriz[i]);
        ver_col = verifica_coluna(matriz, i);
        ver_set = verifica_setor(matriz, i);
        if ((ver_lin==1)||(ver_col==1)||(ver_set==1)){
            printf("NAO\n\n");
            return;
        }
    }
    printf("SIM\n\n");
    return;
}

int verifica_linha(int *linha){
    int gab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, cont=0;
    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if (linha[j]==gab[i]){
                cont++;
            }
            if (cont>1){
                return 1;
            }
        }
        cont = 0;
    }
    return 0;
}

int verifica_coluna(int **matriz, int col){
    int gab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, cont=0;
    for (int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if (matriz[j][col]==gab[i]){
                cont++;
            }
            if (cont>1){
                return 1;
            }
        }
        cont = 0;
    }
    return 0;
}

int verifica_setor(int **matriz, int setor){
    int gab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, cont=0;
    int linha_inicio = (setor / 3) * 3;
    int col_inicio = (setor % 3) * 3;
    for (int a=0; a<9; a++){
        for (int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if (matriz[linha_inicio + i][col_inicio + j]==gab[a]){
                    cont++;
                }
                if (cont>1){
                return 1;
                }
            }
        }
        cont = 0;
    }
    return 0;
}