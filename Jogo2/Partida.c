#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorIA.h"

void configuraJogadores(char *primeiroJogador) {
    printf("==== JOGO DA VELHA CONTRA IA====\n");

    do {
        printf("\nQual simbolo voce quer ser (X ou O)? ");
        scanf(" %c", primeiroJogador);

        if (*primeiroJogador != 'X' && *primeiroJogador != 'O') {
            printf("\nEscolha invalida. Tente Novamente.\n");
        }
    } while (*primeiroJogador != 'X' && *primeiroJogador != 'O');
}

void inicia(char primeiroJogador) {
    Tabuleiro tab;
    int jogadorHumano, jogadorIA;
    int jogadorAtual, vencedor;

    if (primeiroJogador == 'X') {
        jogadorHumano = X;
        jogadorIA = O;
        jogadorAtual = X;
    } else {
        jogadorHumano = O;
        jogadorIA = X;
        jogadorAtual = O;
    }

    inicializaTabuleiro(&tab);

    while (1) {
        desenha(&tab);

        if (jogadorAtual == jogadorHumano) {
            joga(&tab, jogadorHumano);
        } else {
            jogaIA(&tab, jogadorIA, jogadorHumano);
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