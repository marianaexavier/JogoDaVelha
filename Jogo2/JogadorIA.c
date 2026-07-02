#include <stdio.h>
#include "JogadorIA.h"
#include "Tabuleiro.h"
#include "Regra.h"

void jogaIA(Tabuleiro *tab, int tipo, int tipoHumano) {
    if (regra1(tab, tipo, tipoHumano)) return;
    if (regra2(tab, tipo, tipoHumano)) return;
    if (regra3(tab, tipo)) return;
    if (regra4(tab, tipo, tipoHumano)) return;
    if (regra5(tab, tipo)) return;
    if (regra6(tab, tipo)) return;
}