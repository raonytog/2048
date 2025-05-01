#ifndef _MAPA_H_
#define _MAPA_H

#include <stdbool.h>

typedef void (*fptr_print)(void *data);
typedef void (*fptr_libera)(void *data);

typedef struct Mapa Mapa;

Mapa *criaMapa(unsigned int ordem, fptr_print print_f, fptr_libera libera_f);

void atualizaMapa(Mapa *mapa, int opcao);

void insereMapa(Mapa *mapa, void *data, int pos[2]);

void imprimeMapa(Mapa *mapa);

void liberaMapa(Mapa *mapa);

bool mapaEstaCheio(Mapa *mapa);


#endif // !_MAPA_H_