#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorRemoto.h"

void configuraJogadores(JogadorRemoto *jr, int tipo) {
    if (tipo == X) {
        printf("==== JOGO DA VELHA (SERVIDOR) ====\n");
        printf("Voce eh o Jogador X. Aguardando oponente...\n");
        aceitaConexao(jr, 8080);
    }

    if (tipo == O) {
        printf("==== JOGO DA VELHA (CLIENTE) ====\n");
        printf("Voce eh o Jogador O. Conectando...\n");
        conectaServidor(jr, "127.0.0.1", 8080);
    }
}

void inicia(JogadorRemoto *jr, int tipo) {
    Tabuleiro tab;
    int jogadorAtual = X, vencedor;

    inicializaTabuleiro(&tab);

    while (1) {
        desenha(&tab);

        if (jogadorAtual == tipo) {
            joga(&tab, jogadorAtual);
        } else {
            jogaRemoto(jr, jogadorAtual);
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