#include <stdio.h>
#include <stdlib.h>

#include "includes/mapa.h"
#include "includes/peca.h"

#define SIZE 8

int rpos() { return rand()%SIZE; }

int main() {
    int pos[2] = { rand()%8, rand()%8 };
    Mapa *mapa = criaMapa(SIZE, imprimePeca, liberaPeca);
    insereMapa(mapa, criaPeca(pos), pos);

    char opcao;
    while (mapaEstaCheio(mapa) == false) {
        /** le jogada */
        scanf("%c%*c", &opcao);
        atualizaMapa(mapa, opcao);

        /** atualiza o mapa pós jogada adicionando mais uma peça */
        pos[0] = rpos(); pos[1] = rpos();
        insereMapa(mapa, criaPeca(pos), pos);

        imprimeMapa(mapa);
    }

    liberaMapa(mapa);
    return 0;
}