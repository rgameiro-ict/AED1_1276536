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

// 1. Definição da estrutura da Pilha
typedef struct {
    char itens[1005];
    int topo;
} Pilha;

// 2. Funções de manipulação da Pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, char valor) {
    p->topo++;
    p->itens[p->topo] = valor;
}

// Retorna 1 se deu certo, 0 se a pilha estava vazia (erro)
int pop(Pilha *p) {
    if (p->topo == -1) {
        return 0; 
    }
    p->topo--;
    return 1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    char expressao[1005];
    
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        expressao[strcspn(expressao, "\r\n")] = '\0';
        
        Pilha p;
        inicializar(&p);
        
        int correto = 1;
        
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                push(&p, '(');
            } else if (expressao[i] == ')') {
                // Tenta desempilhar. Se retornar 0, é porque não tinha '(' sobrando
                if (pop(&p) == 0) {
                    correto = 0;
                    break;
                }
            }
        }
        
        // Expressão válida apenas se nenhum erro ocorreu e a pilha terminou vazia
        if (correto && vazia(&p)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
