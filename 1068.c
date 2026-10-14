/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Rafael do Couto Gameiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 31/08/2026
Objetivo    : Verificar se todos parênteses estão fechados
Dificuldade : Compreensão da implementação de Pilhas
Uso de IA   : Estruturação do código e Compreenção de Listas Encadeadas
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definir a Pilha

typedef struct cel{
    char letra;
    struct cel *seg;
}celula;

typedef struct Pilha{
    celula *topo;
}Pilha;

void inicializar(Pilha *P){
        P->topo = NULL;
}

int vazia(Pilha *P){
    if(P->topo == NULL){
        return 1;
    }
    return 0;
}

void push(Pilha *P, char v){
    celula *nova = malloc(sizeof(celula));
    nova->letra = v;
    nova->seg = P->topo;
    P->topo = nova;
}

char pop(Pilha *P){
    if (vazia(P)){
        return;
    }
    else{
        char v_topo=P->topo->letra;
        celula *temp = P->topo;
        P->topo = P->topo->seg;
        free(temp);
        return v_topo;
    }
}

void clear(Pilha *P){
    while (!vazia(P)){
        celula *temp = P->topo;
        P->topo = P->topo->seg;
        free(temp);
    }
}

int main(){
    char str[1002];
    Pilha P;
    while(fgets(str, sizeof(str), stdin) != NULL){
        inicializar(&P);
        int correta=1;
        for(int i=0; str[i]!='\0' && str[i] != '\n'; i++){
            if (str[i]=='('){
                push(&P, '(');
            }
            else{
                if (str[i]==')'){
                    if(vazia(&P)){
                        correta = 0;
                        break;
                    }
                    else{
                        pop(&P);
                    }
                }
            }
        }
        if (!vazia(&P)){
            correta = 0;
        }

        if (correta){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
        clear(&P);
    }




    return 0;
}