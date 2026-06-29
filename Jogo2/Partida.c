#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorTeclado.h"
#include "JogadorIA.h"

static char primeiroJogador;
static int escolha;

void configuraJogadores() {
    printf("==== JOGO DA VELHA ====\n");
    printf("(1) JOGAR LOCALMENTE\n");
    printf("(2) JOGAR CONTRA UMA IA\n");

    do {
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha != 1 && escolha != 2) {
            printf("\nEscolha invalida. Tente Novamente.\n");
        }
    } while (escolha != 1 && escolha != 2);

    switch(escolha) {
        case 1:
        do {
            printf("\nQual jogador ira comecar (X ou O)? ");
            scanf(" %c", &primeiroJogador);

            if (primeiroJogador != 'X' && primeiroJogador != 'O') {
                printf("\nEscolha invalida. Tente Novamente.\n");
            }
        } while (primeiroJogador != 'X' && primeiroJogador != 'O');
        break;

        case 2:
        primeiroJogador = 'X';
        break;
    }    
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

        switch(escolha) {
            case 1:
            joga(jogadorAtual);
            break;

            case 2:
            if (jogadorAtual == X) {
                joga(jogadorAtual);
            } else {
                jogaIA(jogadorAtual);
            }
            break;
        }
        

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
