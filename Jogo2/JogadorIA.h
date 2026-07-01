#ifndef JOGADORIA_H
#define JOGADORIA_H
#include "Tabuleiro.h"

typedef struct {
    int tipo;
} JogadorIA;

int jogaIA(Tabuleiro *tab, int tipo);

#endif