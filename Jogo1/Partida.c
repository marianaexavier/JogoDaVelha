#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"

void configuraJogadores(int *escolha, char *primeiroJogador) {
    printf("==== JOGO DA VELHA ====\n");

    do {
        printf("Qual jogador ira comecar (X ou O)? ");
        scanf(" %c", primeiroJogador);

        if (*primeiroJogador != 'X' && *primeiroJogador != 'O') {
            printf("\nEscolha invalida. Tente Novamente.\n");
        }
    } while (*primeiroJogador != 'X' && *primeiroJogador != 'O');
}

void inicia(int escolha, char primeiroJogador) {
    Jogador jogadorAtual;
    Tabuleiro tab;
    int vencedor;

    if (primeiroJogador == 'X') {
    jogadorAtual.tipo = X;
    } else {
    jogadorAtual.tipo = O;
    }

    inicializaTabuleiro(&tab);

    while (1) {
        desenha(&tab);
        joga(&tab, jogadorAtual.tipo);

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

        if (jogadorAtual.tipo == X) {
            jogadorAtual.tipo = O;
        } else {
            jogadorAtual.tipo = X;
        }
    }
}