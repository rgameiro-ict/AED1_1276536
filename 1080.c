/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 21/08/2026
Objetivo    : Ler 100 valores inteiros e retornar o maior valor lido e a posição
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(){
    int valor, maior=-1, posicao;
    for(int i=1; i<=100; i++){
        scanf("%d", &valor);
        if (valor>maior){
            maior = valor;
            posicao = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicao);
    return 0;
}

