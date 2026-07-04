#ifndef JOGADORREMOTO_H
#define JOGADORREMOTO_H
#include "Tabuleiro.h"

#define porta 8080

typedef struct {
    int socketFd;
} JogadorRemoto;

void aceitaConexao(JogadorRemoto *jr);
void conectaServidor(JogadorRemoto *jr, char *ip);
void enviaJogada(JogadorRemoto *jr, int linha, int coluna);
void jogaRemoto(JogadorRemoto *jr, Tabuleiro *tab, int tipo);

#endif