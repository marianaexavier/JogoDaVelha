#ifndef PARTIDA_H
#define PARTIDA_H
#include "JogadorRemoto.h"

void configuraJogadores(JogadorRemoto *jr, int tipo, char *ip);
void inicia(JogadorRemoto *jr, int tipo);

#endif