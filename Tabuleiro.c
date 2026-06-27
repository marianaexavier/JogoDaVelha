#include <stdio.h>
#include "Tabuleiro.h"

static int M[3][3];
static int totalJogadas = 0;

void inicializaTabuleiro() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            M[i][j] = VAZIO;
        }
    }
}

static char simbolo(int valor) {
    if (valor == O) {
        return 'O';
    } else if (valor == X) {
        return 'X';
    } else {
        return ' ';
    }
}

void desenha() {
    int i, j;
    printf("\033[2J\033[H");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", simbolo(M[i][j]));
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
}

int posicaoDisponivel(int linha, int coluna) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2)
        return 0;
        
    return M[linha][coluna] == VAZIO;
}

void marcaJogada(int linha, int coluna, int tipo) {
    M[linha][coluna] = tipo;
    totalJogadas++;
}

int temVencedor() {
    int i, soma;
 
    for (i = 0; i < 3; i++) {
        soma = M[i][0] + M[i][1] + M[i][2];
        if (soma == 3) return O;
        if (soma == 12) return X;
    }

    for (i = 0; i < 3; i++) {
        soma = M[0][i] + M[1][i] + M[2][i];
        if (soma == 3) return O;
        if (soma == 12) return X;
    }

    soma = M[0][0] + M[1][1] + M[2][2];
    if (soma == 3) return O;
    if (soma == 12) return X;

    soma = M[0][2] + M[1][1] + M[2][0];
    if (soma == 3) return O;
    if (soma == 12) return X;

    if (totalJogadas == 9) return EMPATE;
    
    return VAZIO;
}
