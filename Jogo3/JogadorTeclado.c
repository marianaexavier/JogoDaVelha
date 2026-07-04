#include <stdio.h>
#include "JogadorTeclado.h"
#include "Tabuleiro.h"
#include "JogadorRemoto.h"

static char distinguirJogador(int tipo) {
    if (tipo == X) return 'X';
    return 'O';
}

void joga(Tabuleiro *tab, int tipo, JogadorRemoto *jr) {
    int linha, coluna;

    do {
        printf("Jogador %c, digite a linha e a coluna (1 a 3): ", distinguirJogador(tipo));
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (!posicaoDisponivel(tab, linha, coluna)) {
            printf("Posicao indisponivel. Tente novamente.\n");
        }
    } while (!posicaoDisponivel(tab, linha, coluna));
    
    marcaJogada(tab, linha, coluna, tipo);
    enviaJogada(jr, linha, coluna);
}