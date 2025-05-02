#include <stdio.h>
#include <stdlib.h>

#include "../includes/peca.h"

struct Peca {
    char value;
    int pos[2];
};

Peca *criaPeca(int pos[2]) {
    Peca *new = malloc(sizeof(Peca));

    new->pos[0] = pos[0];
    new->pos[1] = pos[1];

    if (rand() % 2 == 0) new->value = '2';
    else                 new->value = '4';

    return new;
}

void atualizaPeca(void *data, int pos[2]) {
    ((Peca*)data)->value = '?';
    ((Peca*)data)->pos[0] = pos[0];
    ((Peca*)data)->pos[1] = pos[1];
}

void imprimePeca(void *data) {;
    if ((Peca*)data) printf(" %c", ((Peca*)data)->value);
    else printf(" +");
}

void liberaPeca(void *data) {
    if (!data) return;
    free( (Peca*)data );
}