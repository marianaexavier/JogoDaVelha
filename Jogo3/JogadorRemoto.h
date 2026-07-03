#ifndef JOGADORREMOTO_H
#define JOGADORREMOTO_H
#include "Tabuleiro.h"

typedef struct {
    int socketFd;
} JogadorRemoto;

void aceitaConexao(JogadorRemoto *jr, int porta);
void conectaServidor(JogadorRemoto *jr, char *ip, int porta);
void enviaJogada(JogadorRemoto *jr, int linha, int coluna);
void jogaRemoto(JogadorRemoto *jr, Tabuleiro *tab);

#endif