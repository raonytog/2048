#ifndef _PECA_H_
#define _PECA_H_

typedef struct Peca Peca;

Peca *criaPeca(int pos[2]);

void atualizaPeca(void *data, int pos[2]);

void imprimePeca(void *data);

void liberaPeca(void *data);


#endif