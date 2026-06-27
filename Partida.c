#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"

void configuraJogadores() {
    printf("==== JOGO DA VELHA ====\n");
    printf("Jogador 1 = X | Jogador 2 = O\n\n");
}

void inicia() {
    int jogadorAtual = X;
    int vencedor;

    inicializaTabuleiro();

    while (1) {
        desenha();
        joga(jogadorAtual);

        vencedor = temVencedor();
        if (vencedor == X) {
            desenha();
            printf("\nO jogador 1 (X) venceu!\n");
            break;
        }

        if (vencedor == O) {
            desenha();
            printf("\nO jogador 2 (O) venceu!\n");
            break;
        }

        if (vencedor == EMPATE) {
            desenha();
            printf("\nEMPATE!\n");
            break;
        }

        if (jogadorAtual == X) {
            jogadorAtual = O;
        } else {
            jogadorAtual = X;
        }
    }
}