#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef enum {
    VAZIO  = 0,
    O      = 1,
    X      = 4,
    EMPATE = 2
} valorRep;

typedef struct {
    int M[3][3];
    int totalJogadas;
} Tabuleiro;
 
void inicializaTabuleiro(Tabuleiro *tab);
void desenha(Tabuleiro *tab);
int posicaoDisponivel(Tabuleiro *tab, int linha, int coluna);
void marcaJogada(Tabuleiro *tab, int linha, int coluna, int tipo);
int temVencedor(Tabuleiro *tab);

#endif