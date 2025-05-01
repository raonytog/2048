#include <stdio.h>
#include <stdlib.h>

#include "includes/peca.h"

struct Peca {
    int value;
    int pos[2];
};

Peca *criaPeca(int pos[2]) {
    Peca *new = malloc(sizeof(Peca));

    new->pos[0] = pos[0];
    new->pos[1] = pos[1];
    if ( (rand()%10) %2 == 0) new->value = 2;
    else new->value = 4;

    return new;
}

void atualizaPeca(Peca *peca, int pos[2]) {
    peca->value *= 2;
    peca->pos[0] = pos[0];
    peca->pos[1] = pos[1];
}

void imprimePeca(Peca *peca) {
    printf(" %d", peca->value);
}

void liberaPeca(Peca *peca) {
    free(peca);
}