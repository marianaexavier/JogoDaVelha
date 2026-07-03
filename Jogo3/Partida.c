#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorRemoto.h"

void configuraJogadores() {
    printf("==== JOGO DA VELHA (REMOTO))===\n");

}

void inicia() {
    Tabuleiro tab;
    int jogadorAtual = X, vencedor;

    inicializaTabuleiro(&tab);

    while (1) {
        desenha(&tab);

        if (jogadorAtual == X) {
            
        } else {
            
        }


        vencedor = temVencedor(&tab);
        if (vencedor == X) {
            desenha(&tab);
            printf("\nO jogador 'X' venceu!\n");
            break;
        }

        if (vencedor == O) {
            desenha(&tab);
            printf("\nO jogador 'O' venceu!\n");
            break;
        }

        if (vencedor == EMPATE) {
            desenha(&tab);
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