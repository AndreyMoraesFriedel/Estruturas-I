#include "lista_simples.h"
#include <stdlib.h>
#include <stdio.h>

NoLista *sllCria(void){
        return NULL;
}

NoLista *sllInsere(NoLista *head, int v){
        NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
        novo->info = v;
        novo->prox = head;
        return novo;
}

NoLista *sllInsereFim(NoLista *head, int v){
        if(head->prox == NULL){
                NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
                novo->info = v;
                head->prox = novo;
        } else{
                sllInsereFim(head->prox, v);
        }
        return head;
}

void sllImprime(NoLista *head){
        NoLista *p = head;
        while(p!=NULL){
                printf("%f\n", p->info);
                p = p->prox;
        }
}

void sllImprimeRecursivo(NoLista *head){
        if(head!=NULL){
                printf("%f\n", head->info);
                sllImprimeRecursivo(head->prox);
        }
}

int sllVazia(NoLista *head){
        if(head==NULL){
                return 1;
        }else{
                return 0;
        }
}

NoLista *sllBusca(NoLista *head, int v){
        NoLista *p = head;
        while(p!=NULL){
                if(p->info==v){
                        return p;
                }
                p = p->prox;
        }
        return NULL;
}

int sllComprimento(NoLista *head){
        int tam = 0;
        NoLista *p = head;
        while(p!=NULL){
                tam += 1;
                p = p->prox;
        }
        return tam;
}

int sllComprimentoRecursivo(NoLista *head){
        if(head==NULL){
                return 0;
        }
        return 1 + sllComprimentoRecursivo(head->prox);
}

NoLista *sllUltimo(NoLista *head){
        if(head==NULL){
                return NULL;
        }
        NoLista *p = head;
        NoLista *ant;
        while(p!=NULL){
                ant = p;
                p = p->prox;
        }
        return ant;
}

NoLista *sllRetira(NoLista *head, int v){
        if(head==NULL){
                return NULL;
        }
        NoLista *vr = sllBusca(head, v);
        if(vr!=NULL){
                if(vr==head){
                        head = head->prox;
                        free(vr);
                        return head;
                }
                NoLista *ant;
                NoLista *p = head;
                while(p!=vr){
                        ant = p;
                        p = p->prox;
                }
                ant->prox = vr->prox;
                free(vr);
                return head;
        }else{
                return head;
        }
}

NoLista *sllRetiraRecursivo(NoLista *head, int v){
        if (head == NULL){
                return NULL;
        } else if (head->info == v){
                NoLista *aux = head;
                head = head->prox;
                free(aux);
        } else{
                head->prox = sllRetiraRecursivo(head->prox, v);
        }
        return head;
}

void sllLibera(NoLista *head){
        NoLista *p = head;
        NoLista *ant;
        while(p!=NULL){
                ant = p;
                p = p->prox;
                free(ant);
        }
}

void sllLiberaRecu(NoLista *head){
        if (head != NULL){
                NoLista *prox = head->prox;
                free(head);
                sllLiberaRecu(prox);
        }
}

int sllIgual(NoLista *lista1, NoLista *lista2){
        if(lista1 == NULL && lista2 == NULL){
                return 1;
        }else{
                if(sllComprimento(lista1) != sllComprimentoRecursivo(lista2)){
                        return 0;
                }else{
                        while(lista1!=NULL){
                                if(lista1->info!=lista2->info){
                                        return 0;
                                }
                                lista1 = lista1->prox;
                                lista2 = lista2->prox;
                        }
                }            
        }
        return 1;
}


int sllIgualRecursivo(NoLista *lista1, NoLista *lista2){
        if(lista1 == NULL && lista2 == NULL){
                return 1;
        }else{
                if(lista1 == NULL || lista2 == NULL){
                        return 0;
                }else{
                        if(lista1->info!=lista2->info){
                                return 0;
                        }
                }
        }
        return sllIgualRecursivo(lista1->prox,lista2->prox);
}

