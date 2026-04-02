#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

Pilha *pilha_cria(void){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    if (p == NULL){ // Caso malloc falhe
        printf("Erro de alocação\n");
        exit(1);
    }

    p->topo = NULL;
    return p;
}

void pilha_push(Pilha *p, float v){
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));

    novo->info = v;
    novo->prox = p->topo;

    p->topo = novo;
}

float pilha_pop(Pilha *p){
    if (p->topo == NULL){
        printf("Erro ao retirar elemento da pilha. Pilha vazia.\n");
        exit(1);
    }

    float valor = p->topo->info;
    NoLista *temp = p->topo;

    p->topo = p->topo->prox;
    free(temp);

    return valor;
}

int pilha_vazia(Pilha *p){
    return p->topo == NULL;
}

float pilha_top(Pilha *p){
    if (p->topo == NULL){
        printf("Erro ao retornar topo da pilha. Pilha vazia.\n");
        exit(1);
    }

    return p->topo->info;
}

void pilha_libera(Pilha *p){
    // Passa um a um apagando e apontando para o prox
    // Liberando a lista da pilha
    while (p->topo != NULL){
        NoLista *temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }
    //liberando a propria pilha
    free(p);
}

void pilha_imprime(Pilha *p){
    if (p->topo == NULL){
        printf("Erro ao imprimir pilha. Pilha vazia.\n");
        exit(1);
    }
    
    NoLista *temp = p->topo;
    while (temp != NULL){
        printf("%f\n", temp->info);
        temp = temp->prox;
    }
}