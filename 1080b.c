/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Ler 100 valores inteiros e retornar o maior valor lido e a posição com alocação dinâmica
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor, maior=-1, posicao;
    vetor = (int *) malloc(100*sizeof(int));
    for(int i=0; i<100; i++){
        scanf("%d", &vetor[i]);
        if (vetor[i]>maior){
            maior = vetor[i];
            posicao = i + 1;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicao);
    free(vetor);
    return 0;
}