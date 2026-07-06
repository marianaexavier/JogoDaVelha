#include <stdio.h>
#include "Partida.h"
#include "Tabuleiro.h"
#include "JogadorRemoto.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Erro! Uso correto: %s <IP_DO_SERVIDOR>\n", argv[0]);
        printf("Exemplo: %s 192.168.1.5\n", argv[0]);
        return 1;
    }

    char *ip_servidor = argv[1];
    int tipo = O;
    JogadorRemoto jr;

    configuraJogadores(&jr, tipo, ip_servidor);
    inicia(&jr, tipo);

}