#include "Partida.h"

int main() {
    int escolha;
    char primeiroJogador;

    configuraJogadores(&escolha, &primeiroJogador);
    inicia(escolha, primeiroJogador);

    return 0;
}