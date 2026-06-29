#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"

static char primeiroJogador;

void configuraJogadores() {
    printf("==== JOGO DA VELHA ====\n");

    do {
        printf("Qual jogador ira comecar (X ou O)? ");
        scanf(" %c", &primeiroJogador);
        if (primeiroJogador != 'X' && primeiroJogador != 'O') {
            printf("\nEscolha invalida. Tente Novamente.\n");
        }
    } while (primeiroJogador != 'X' && primeiroJogador != 'O');
}

void inicia() {
    int jogadorAtual;
    int vencedor;

    if (primeiroJogador == 'X') {
        jogadorAtual = X;
    } else {
        jogadorAtual = O;
    }

    inicializaTabuleiro();

    while (1) {
        desenha();
        joga(jogadorAtual);

        vencedor = temVencedor();
        if (vencedor == X) {
            desenha();
            printf("\nO jogador 'X' venceu!\n");
            break;
        }

        if (vencedor == O) {
            desenha();
            printf("\nO jogador 'O' venceu!\n");
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