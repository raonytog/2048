#include <stdio.h>
#include <stdlib.h>

#include "../includes/mapa.h"
#include "../includes/peca.h"

#define SIZE 8

int rpos() { return rand()%SIZE; }

int main() {
    Mapa *mapa = criaMapa(SIZE, imprimePeca, liberaPeca);
    int pos[2] = {rand()%8, rand()%8};
    insereMapa(mapa, criaPeca(pos), pos);
    imprimeMapa(mapa);

    char opcao;
    while (true) {
        /** le jogada */
        scanf("%c%*c", &opcao);
        atualizaMapa(mapa, opcao);
        if (mapaEstaCheio(mapa) == false) break;

        /** atualiza o mapa pós jogada adicionando mais uma peça */
        pos[0] = rpos(); pos[1] = rpos();
        insereMapa(mapa, criaPeca(pos), pos);

        imprimeMapa(mapa);
    }

    printf("Fim de jogo!\n");
    printf("Pontuacao alcançada: %d\n", getPontuacao(mapa));

    liberaMapa(mapa);
    return 0;
}