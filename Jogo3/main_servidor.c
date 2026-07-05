#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorRemoto.h"

int main() {
    int tipo = X;
    JogadorRemoto jr;

    // Passamos NULL no final porque o servidor não precisa de IP
    configuraJogadores(&jr, tipo, NULL); 
    inicia(&jr, tipo);

    return 0;
}