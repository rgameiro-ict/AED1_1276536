/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 07/10/2026
Objetivo    : Organizar os vagões
Dificuldade : 
Uso de IA   : Estruturação do código e Compreenção de Listas Encadeadas
-------------------------------------------------------------------------- */

#include <stdio.h>

// 1. Definição da Pilha usando struct
typedef struct {
    int itens[1005];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int valor) {
    p->topo++;
    p->itens[p->topo] = valor;
}

void pop(Pilha *p) {
    if (p->topo != -1) {
        p->topo--;
    }
}

// Retorna o valor do topo sem desempilhar
int top(Pilha *p) {
    if (p->topo != -1) {
        return p->itens[p->topo];
    }
    return -1; 
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

// 2. Lógica principal
int main() {
    int n;
    
    // Lê a quantidade de vagões, para quando n for 0
    while (scanf("%d", &n) == 1 && n != 0) {
        int primeiro;
        
        // Lê o primeiro vagão da formação desejada. Se for 0, acaba o bloco
        while (scanf("%d", &primeiro) == 1 && primeiro != 0) {
            int saida_esperada[1005];
            saida_esperada[0] = primeiro;
            
            // Lê o restante da sequência de vagões desejada
            for (int i = 1; i < n; i++) {
                scanf("%d", &saida_esperada[i]);
            }
            
            Pilha estacao;
            inicializar(&estacao);
            
            int trem_chegando = 1;
            int possivel = 1;
            
            // Verifica cada vagão da saída desejada
            for (int i = 0; i < n; i++) {
                // Enquanto o trem desejado não estiver no topo da estação,
                // vamos colocando os trens que estão chegando
                while (vazia(&estacao) || top(&estacao) != saida_esperada[i]) {
                    if (trem_chegando > n) {
                        break; // Não há mais trens para chegar
                    }
                    push(&estacao, trem_chegando);
                    trem_chegando++;
                }
                
                // Se o trem no topo é o que queremos, ele sai da estação
                if (top(&estacao) == saida_esperada[i]) {
                    pop(&estacao);
                } else {
                    // Se não for, é impossível gerar a sequência
                    possivel = 0;
                    break;
                }
            }
            
            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        // O beecrowd pede uma linha em branco após cada bloco de testes (após o 0)
        printf("\n"); 
    }
    
    return 0;
}