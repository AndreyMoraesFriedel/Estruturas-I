#ifndef PILHA_H
#define PILHA_H

struct noLista {
    float info;
    struct noLista *prox;
};

typedef struct noLista NoLista;

struct pilha {
    NoLista *topo;
};

typedef struct pilha Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
float pilha_top(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);

#endif