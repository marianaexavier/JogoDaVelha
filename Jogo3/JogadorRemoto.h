#ifndef JOGADORREMOTO_H
#define JOGADORREMOTO_H
#include "Tabuleiro.h"

#define PORTA 8080

typedef struct {
    int socketFd;
} JogadorRemoto;

void aceitaConexao(JogadorRemoto *jr);
void conectaServidor(JogadorRemoto *jr, char *ip);
void enviaJogada(JogadorRemoto *jr, int linha, int coluna);
void jogaRemoto(JogadorRemoto *jr, Tabuleiro *tab, int tipo);
void fechaConexao(JogadorRemoto *jr);

#endif