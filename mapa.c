#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

struct Mapa {
    unsigned int    ordem;
    unsigned int    pos_ocupadas;

    void*         **grid;
    fptr_print      print;
    fptr_libera     libera;
};

Mapa *criaMapa(unsigned int ordem, fptr_print print_f, fptr_libera libera_f) {
    Mapa *new = malloc(sizeof(Mapa));

    new->ordem = ordem;
    new->pos_ocupadas = 0;
    new->grid = calloc(new->ordem, sizeof(unsigned int));

    new->print = print_f;
    new->libera = libera_f;

    return new;
}

void atualizaMapa(Mapa *mapa, int opcao);

void insereMapa(Mapa *mapa, void *data, int pos[2]) {
    mapa->grid[ pos[0] ][ pos[1] ] = data;
}

void imprimeMapa(Mapa *mapa) {
    for(int i = 0; i < mapa->ordem; i++) {
        for(int j = 0; j < mapa->ordem; j++) {
            mapa->print( mapa->grid[i][j] );
        }
    }
}

void liberaMapa(Mapa *mapa) {
    for(int i = 0; i < mapa->ordem; i++) {
        for(int j = 0; j < mapa->ordem; j++) {
            mapa->libera( mapa->grid[i][j] );
        }
        
    }
}

bool mapaEstaCheio(Mapa *mapa) { return mapa->pos_ocupadas == mapa->ordem*mapa->ordem; }