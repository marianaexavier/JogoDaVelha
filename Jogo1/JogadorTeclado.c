#include <stdio.h>
#include "JogadorTeclado.h"
#include "Tabuleiro.h"

static char distinguirJogador(int tipo) {
    if (tipo == X) return 'X';
    return 'O';
}

void joga(int tipo) {
    int linha, coluna;

    do {
    printf("Jogador %c, digite a linha e a coluna (1 a 3): ", distinguirJogador(tipo));
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;

    if (!posicaoDisponivel(linha, coluna)) {
        printf("Posicao indisponivel. Tente novamente.\n");
    }
    } while (!posicaoDisponivel(linha, coluna));
    
    marcaJogada(linha, coluna, tipo);
}