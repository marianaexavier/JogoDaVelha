#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"

void configuraJogadores(int *escolha, char *primeiroJogador) {
    printf("==== JOGO DA VELHA ====\n");
    printf("(1) JOGAR LOCALMENTE\n");
    printf("(2) JOGAR CONTRA UMA IA\n");

    do {
        printf("\nDigite sua escolha: ");
        scanf("%d", escolha);

        if (*escolha != 1 && *escolha != 2) {
            printf("\nEscolha invalida. Tente Novamente.\n");
        }
    } while (*escolha != 1 && *escolha != 2);

    switch(*escolha) {
        case 1:
        do {
            printf("\nQual jogador ira comecar (X ou O)? ");
            scanf(" %c", primeiroJogador);

            if (*primeiroJogador != 'X' && *primeiroJogador != 'O') {
                printf("\nEscolha invalida. Tente Novamente.\n");
            }
        } while (*primeiroJogador != 'X' && *primeiroJogador != 'O');
        break;
    }    
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

        switch(escolha) {
            case 1:
            joga(&tab, jogadorAtual.tipo);
            break;
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

        if (jogadorAtual.tipo == X) {
            jogadorAtual.tipo = O;
        } else {
            jogadorAtual.tipo = X;
        }
    }
}