#include <stdio.h>
#include "Tabuleiro.h"

int regra1(Tabuleiro *tab, int tipo, int tipoHumano){

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
    if ((*tab).M[0][0] == tipoHumano) {
        marcaJogada(tab, 2, 2, tipo);
        return 1;
    }

    if ((*tab).M[0][2] == tipoHumano) {
        marcaJogada(tab, 2, 0, tipo);
        return 1;
    }

    if ((*tab).M[2][0] == tipoHumano) {
        marcaJogada(tab, 0, 2, tipo);
        return 1;
    }

    if ((*tab).M[2][2] == tipoHumano) {
        marcaJogada(tab, 0, 0, tipo);
        return 1;
    }

    return 0;
}

int regra5(Tabuleiro *tab, int tipo) {
    int i, j;
    for (i = 0; i < 3; i + 2) {
        for (j = 0; j < 3; j + 2) {
            if (posicaoDisponivel(tab, i, j)) {
                marcaJogada(tab, i, j, tipo);
            }
        }
    }
}

void regra6(Tabuleiro *tab, int tipo) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (posicaoDisponivel(tab, i, j)) {
                marcaJogada(tab, i, j, tipo);
            }
        }
    }
}