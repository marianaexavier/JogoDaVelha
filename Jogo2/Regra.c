#include <stdio.h>
#include "Tabuleiro.h"

int regra1(Tabuleiro *tab, int tipo){

}

int regra2(Tabuleiro *tab, int tipo) {

}

int regra3(Tabuleiro *tab, int tipo) {
    if ((*tab).M[1][1] == VAZIO) {
        marcaJogada(tab, 1, 1, tipo);
        return 1;
    }
    return 0;
}

int regra4(Tabuleiro *tab, int tipo) {

}

int regra5(Tabuleiro *tab, int tipo) {

}

int regra6(Tabuleiro *tab, int tipo) {

}