#include <stdio.h>
#include <stdlib.h>

#include "../includes/mapa.h"

struct Mapa {
    int pontuacao;
    int ordem;
    int pos_ocupadas;

    void* **grid;
    fptr_print print;
    fptr_libera libera;
};

int getPontuacao(Mapa *mapa) {
    if (!mapa) return 0;
    return mapa->pontuacao;
}

int getOrdem(Mapa *mapa) {
    if (!mapa) return 0;
    return mapa->ordem;
}

int getPosOcupadas(Mapa *mapa) {
    if (!mapa) return 0;
    return mapa->pos_ocupadas;
}

Mapa *criaMapa(int ordem, fptr_print print_f, fptr_libera libera_f) {
    Mapa *new = malloc(sizeof(Mapa));

    new->pontuacao = 0;
    new->ordem = ordem;
    new->pos_ocupadas = 0;
    new->grid = malloc(ordem * sizeof(void**));
    for (int i = 0; i < ordem; i++)
        new->grid[i] = malloc(ordem * sizeof(void*));

    new->print = print_f;
    new->libera = libera_f;

    return new;
}

#define VAZIO '+'
#define A(op) (op == 'a' || op == 'A')
#define D(op) (op == 'd' || op == 'D')
#define S(op) (op == 's' || op == 'S')
#define W(op) (op == 'w' || op == 'W')

void atualizaMapa(Mapa *mapa, char opcao) {
    if (A(opcao)) {
        for(int i = 0; i < mapa->ordem; i++) {
            for(int j = mapa->ordem-1; j >= 0; j--) {
                for (int k = j-1; k >= 0; k--) {
                    if (mapa->grid[i][k] == NULL) {
                        mapa->grid[i][k] = mapa->grid[i][j];
                        mapa->grid[i][j] = NULL;
                    }
                }
            }
        }
    }

    else if(D(opcao)) {
        for(int i = 0; i < mapa->ordem; i++) {
            for(int j = 0; j < mapa->ordem; j++) {
                for (int k = j+1; k < mapa->ordem; k++) {
                    if (mapa->grid[i][k] == NULL) {
                        mapa->grid[i][k] = mapa->grid[i][j];
                        mapa->grid[i][j] = NULL;
                    }
                }
            }
        }
    }

    else if(S(opcao)) {
        for(int i = 0; i < mapa->ordem; i++) {
            for(int j = 0; j < mapa->ordem; j++) {
                for (int k = i+1; k < mapa->ordem; k++) {
                    if (mapa->grid[k][j] == NULL) {
                        mapa->grid[k][j] = mapa->grid[i][j];
                        mapa->grid[i][j] = NULL;
                    }
                }
            }
        }
    }
    else if(W(opcao)) {
        for(int i = mapa->ordem-1; i >= 0; i--) {
            for(int j = 0; j < mapa->ordem; j++) {
                for (int k = i-1; k >= 0; k--) {
                    if (mapa->grid[k][j] == NULL) {
                        mapa->grid[k][j] = mapa->grid[i][j];
                        mapa->grid[i][j] = NULL;
                    }
                }
            }
        }
    }
}

void insereMapa(Mapa *mapa, void *data, int pos[2]) {
    mapa->grid[ pos[0] ][ pos[1] ] = data;
    mapa->pos_ocupadas++;
}

void *getConteudoPosicaoMapa(Mapa *mapa, int i, int j) { return mapa->grid[i][j]; }

void imprimeMapa(Mapa *mapa) {
    printf("Jogo: 2048, grid: %d x %d\n", mapa->ordem, mapa->ordem);
    printf("Pontuacao: %d\n\n", mapa->pontuacao);
    for(int i = 0; i < mapa->ordem; i++) {
        printf("\t");
        for(int j = 0; j < mapa->ordem; j++) {
            mapa->print( mapa->grid[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void liberaMapa(Mapa *mapa) {
    for(int i = 0; i < mapa->ordem; i++) {
        for(int j = 0; j < mapa->ordem; j++) {
            mapa->libera( mapa->grid[i][j] );
        }
        free(mapa->grid[i]);
    }
    free(mapa->grid);
    free(mapa);
}

bool mapaEstaCheio(Mapa *mapa) { return mapa->pos_ocupadas == mapa->ordem*mapa->ordem; }