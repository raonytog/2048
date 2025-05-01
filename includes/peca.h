#ifndef _PECA_H_
#define _PECA_H_

typedef struct Peca Peca;

Peca *criaPeca(int pos[2]);

void atualizaPeca(Peca *peca, int pos[2]);

void imprimePeca(Peca *peca);

void liberaPeca(Peca *peca);


#endif