#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorRemoto.h"

int main() {
    int tipo = X;
    JogadorRemoto jr;

    configuraJogadores(&jr, tipo);
    inicia(&jr, tipo);
}