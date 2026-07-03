#ifndef JOGADOR_IA
#define JOGADOR_IA
#include "Tabuleiro.h"

typedef struct {
    int tipo;
} JogadorIA;

typedef struct {
    int linha;
    int coluna;
} Posicao;

int regra1(Tabuleiro *tab, int tipo, int *linha, int *coluna);

void jogaIA(Tabuleiro *tab, int tipo);

#endif