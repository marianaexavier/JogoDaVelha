#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H
#include "Tabuleiro.h"

typedef struct {
    int tipo;
} Jogador;

void joga(Tabuleiro *tab, int tipo);

#endif