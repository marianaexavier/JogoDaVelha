#include <stdio.h>
#include "Tabuleiro.h"

int regra1(Tabuleiro *tab, int tipo, int tipoHumano) {
    int i, j, k, soma;
    int objetivos[2] = {2 * tipo, 2 * tipoHumano};

    for (k = 0; k < 2; k++) {
        int objetivo = objetivos[k];

        for (i = 0; i < 3; i++) {
            soma = (*tab).M[i][0] + (*tab).M[i][1] + (*tab).M[i][2];
            if (soma == objetivo) {
                for (j = 0; j < 3; j++) {
                    if (posicaoDisponivel(tab, i, j)) {
                        marcaJogada(tab, i, j, tipo);
                        return 1;
                    }
                }
            }
        }

        for (j = 0; j < 3; j++) {
            soma = (*tab).M[0][j] + (*tab).M[1][j] + (*tab).M[2][j];
            if (soma == objetivo) {
                for (i = 0; i < 3; i++) {
                    if (posicaoDisponivel(tab, i, j)) {
                        marcaJogada(tab, i, j, tipo);
                        return 1;
                    }
                }
            }
        }

        soma = (*tab).M[0][0] + (*tab).M[1][1] + (*tab).M[2][2];
        if (soma == objetivo) {
            for (i = 0; i < 3; i++) {
                if (posicaoDisponivel(tab, i, i)) {
                    marcaJogada(tab, i, i, tipo);
                    return 1;
                }
            }
        }

        soma = (*tab).M[0][2] + (*tab).M[1][1] + (*tab).M[2][0];
        if (soma == objetivo) {
            for (i = 0; i < 3; i++) {
                if (posicaoDisponivel(tab, i, 2 - i)) {
                    marcaJogada(tab, i, 2 - i, tipo);
                    return 1;
                }
            }
        }
    }
    return 0; 
}

int regra2(Tabuleiro *tab, int tipo, int tipoHumano) {

}

int regra3(Tabuleiro *tab, int tipo) {
    if (posicaoDisponivel(tab, 1, 1)) {
        marcaJogada(tab, 1, 1, tipo);
        return 1;
    }
    return 0;
}

int regra4(Tabuleiro *tab, int tipo, int tipoHumano) {
    if ((*tab).M[0][0] == tipoHumano && posicaoDisponivel(tab, 2, 2)) {
        marcaJogada(tab, 2, 2, tipo);
        return 1;
    }
    if ((*tab).M[0][2] == tipoHumano && posicaoDisponivel(tab, 2, 0)) {
        marcaJogada(tab, 2, 0, tipo);
        return 1;
    }
    if ((*tab).M[2][0] == tipoHumano && posicaoDisponivel(tab, 0, 2)) {
        marcaJogada(tab, 0, 2, tipo);
        return 1;
    }
    if ((*tab).M[2][2] == tipoHumano && posicaoDisponivel(tab, 0, 0)) {
        marcaJogada(tab, 0, 0, tipo);
        return 1;
    }
    return 0;
}

int regra5(Tabuleiro *tab, int tipo) {
    int i, j;

    for (i = 0; i < 3; i += 2) {
        for (j = 0; j < 3; j += 2) {
            if (posicaoDisponivel(tab, i, j)) {
                marcaJogada(tab, i, j, tipo);
            }
        }
    }
    return 0;
}

int regra6(Tabuleiro *tab, int tipo) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (posicaoDisponivel(tab, i, j)) {
                marcaJogada(tab, i, j, tipo);
                return 1;
            }
        }
    }
    return 0;
}