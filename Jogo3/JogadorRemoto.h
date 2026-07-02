#ifndef JOGADORREMOTO_H
#define JOGADORREMOTO_H

#include "Tabuleiro.h"

typedef struct {
    
} JogadorRemoto;

void jogaRemoto(Tabuleiro *tab);
void conectaServidor();
void aceitaConexao();
void enviaJogada();

#endif