#include <stdio.h>
#include <stdlib.h>

#include "../includes/mapa.h"
#include "../includes/peca.h"

#define SIZE 8

int rpos() { return rand()%SIZE; }

void criaPosicaoValida(Mapa *mapa, int pos[2]) {
    while (true) {
        pos[0] = rpos();    pos[1] = rpos();
        if (getConteudoPosicaoMapa(mapa, pos[0], pos[1]) == NULL) break;
    }
}

int main() {
    Mapa *mapa = criaMapa(SIZE, imprimePeca, liberaPeca);
    int pos[2] = {0, 0};
    criaPosicaoValida(mapa, pos);
    insereMapa(mapa, criaPeca(pos), pos);
    imprimeMapa(mapa);

    char opcao = '\0';
    while (true) {
        /** le jogada */
        scanf("%c%*c", &opcao);
        atualizaMapa(mapa, opcao);
        
        /** atualiza o mapa pós jogada adicionando mais uma peça */
        criaPosicaoValida(mapa, pos);
        insereMapa(mapa, criaPeca(pos), pos);
        
        imprimeMapa(mapa);
        if (mapaEstaCheio(mapa) == true) break;
    }

    printf("Fim de jogo!\n");
    printf("Pontuacao alcançada: %d\n", getPontuacao(mapa));

    liberaMapa(mapa);
    return 0;
}