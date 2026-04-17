#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fila *fila_cria(int tam){
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->vet = (int*) malloc(tam * sizeof(int));
    f->tam = tam;
    f->ini = 0;
    f->n = 0;
    return f;
}


void fila_enqueue(Fila *f, int v){
    if(f->n == f->tam){
        printf("ERRO, a fila esta cheia\n");
        //exit(1);
    }else{
        int fim = (f->ini + f->n) % f->tam;
        f->vet[fim] = v;
        f->n++;
    }
} 


int fila_dequeue(Fila *f){
    if(f->n == 0){
        printf("ERRO, a fila esta vazia\n");
        //exit(1);
    }else{
        int aux = f->vet[f->ini];
        f->ini = (f->ini+1)%f->tam;
        f->n--;
        return aux;
    }
} 


int fila_vazia(Fila *f){
    if(f->n==0){
        return 1;
    }
    return 0;
} 


void fila_imprime(Fila *f){
    if(f->n==0){
        printf("ERRO fila vazia\n");
        exit(1);
    }
    int aux = f->ini;
    for(int i = 0;i<f->n;i++){
        printf("Elemento %d e o %d da lista\n", f->vet[aux], (i+1));
        aux = (aux+1)%f->tam;
    }
} 


void fila_reset(Fila *f){
    f->ini = 0;
    f->n = 0;
} 


Fila *fila_concatena(Fila *f1, Fila *f2){
    Fila *f3 = fila_cria(f1->n + f2->n);
    int i = 0;
    int aux = f1->ini;
    while(i<f1->n){
        fila_enqueue(f3, f1->vet[aux]);
        aux = (aux + 1) % f1->tam;
        i++;
    }
    i = 0;
    aux = f2->ini;
    while(i<f2->n){
        fila_enqueue(f3, f2->vet[aux]);
        aux = (aux + 1) % f2->tam;
        i++;
    }
    return f3;
}


Fila *fila_merge(Fila *f1, Fila *f2){
    Fila *f3 = fila_cria(f1->n+f2->n);
    int i1 = 0; 
    int i2 = 0;
    int aux1 = f1->ini;
    int aux2 = f2->ini;
    while ((i1<f1->n)||(i2<f2->n))
    {
        if (i1 < f1->n){
            fila_enqueue(f3, f1->vet[aux1]);
            aux1 = (aux1 + 1) % f1->tam;
            i1++;
        }if (i2 < f2->n){
            fila_enqueue(f3, f2->vet[aux2]);
            aux2 = (aux2 + 1) % f2->tam;
            i2++;
        }
    }
    return f3;
} 


void fila_libera(Fila *f){
    free(f->vet);
    free(f);
} 
