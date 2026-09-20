/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 31/08/2026
Objetivo    : Verificar se todos parênteses estão fechados
Dificuldade : 
Uso de IA   : Estruturação do código e Compreenção de Listas Encadeadas
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1005];
    
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        expressao[strcspn(expressao, "\r\n")] = '\0';
        
        int aberto = 0;
        int correto = 1;
        
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                aberto++;
            } else if (expressao[i] == ')') {
                aberto--;
                if (aberto < 0) {
                    correto = 0;
                    break;
                }
            }
        }
        
        if (correto && aberto == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
