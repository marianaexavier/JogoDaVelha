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
    Jogador jogadorHumano;
    JogadorIA jogadorIA;
    Tabuleiro tab;
    int jogadorAtual, vencedor;

    if (primeiroJogador == 'X') {
        jogadorHumano.tipo = X;
        jogadorIA.tipo = O;
        jogadorAtual = X;
    } else {
        jogadorHumano.tipo = O;
        jogadorIA.tipo = X;
        jogadorAtual = O;
    }

    inicializaTabuleiro(&tab);

    while (1) {
        desenha(&tab);

        if (jogadorAtual == jogadorHumano.tipo) {
            joga(&tab, jogadorHumano.tipo);
        } else {
            jogaIA(&tab, jogadorIA.tipo, jogadorHumano.tipo);
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