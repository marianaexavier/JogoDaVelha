#include <stdio.h>
#include "JogadorIA.h"
#include "Tabuleiro.h"

static char distinguirJogador(int tipo) {
    if (tipo == X) return 'X';
    return 'O';
}

int regra1(Tabuleiro *tab, int tipo, int *linha, int *coluna);


void jogaIA(Tabuleiro *tab, int tipo) {
 
}