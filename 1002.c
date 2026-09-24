/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1002
Data        : 21/08/2026
Objetivo    : Calcular a área da circunferência com base no raio
Dificuldade : Nenhum
Uso de IA   : Não usei
-------------------------------------------------------------------------- */

#include <stdio.h>


int main(){
    double pi=3.14159, R;
    scanf("%lf", &R);
    printf("A=%.4lf\n", pi*R*R);
    
    return 0;
}