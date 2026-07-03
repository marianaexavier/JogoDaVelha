#include <stdio.h>
#include "Tabuleiro.h"

void inicializaTabuleiro(Tabuleiro *tab) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            (*tab).M[i][j] = VAZIO;
        }
    }
}

static char simbolo(int valor) {
    if (valor == O) return 'O';
    if (valor == X) return 'X';
    return ' ';
}

void desenha(Tabuleiro *tab) {
    int i, j;
    printf("\033[2J\033[H");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", simbolo((*tab).M[i][j]));
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
}

int posicaoDisponivel(Tabuleiro *tab, int linha, int coluna) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2)
        return 0;
        
    return (*tab).M[linha][coluna] == VAZIO;
}

void marcaJogada(Tabuleiro *tab, int linha, int coluna, int tipo) {
    (*tab).M[linha][coluna] = tipo;
}

int temVencedor(Tabuleiro *tab) {
    int i, j, soma;
 
    for (i = 0; i < 3; i++) {
        soma = (*tab).M[i][0] + (*tab).M[i][1] + (*tab).M[i][2];
        if (soma == 3) return O;
        if (soma == 12) return X;
    }

    for (i = 0; i < 3; i++) {
        soma = (*tab).M[0][i] + (*tab).M[1][i] + (*tab).M[2][i];
        if (soma == 3) return O;
        if (soma == 12) return X;
    }

    soma = (*tab).M[0][0] + (*tab).M[1][1] + (*tab).M[2][2];
    if (soma == 3) return O;
    if (soma == 12) return X;

    soma = (*tab).M[0][2] + (*tab).M[1][1] + (*tab).M[2][0];
    if (soma == 3) return O;
    if (soma == 12) return X;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++){
            if ((*tab).M[i][j] == VAZIO) {
                return 0;
            }
        }
    }
    
    return EMPATE;
}