#include "arvore_busca.h"
#include <stdio.h>
#include <stdlib.h>

ArvoreBusca *abb_cria(void){
    ArvoreBusca *abb = (ArvoreBusca *) malloc(sizeof(ArvoreBusca));
    abb->raiz = NULL;
    return abb;
} 

int abb_vazia(ArvoreBusca *a){
    return a->raiz == NULL;
}

NoArvoreBusca *abb_busca_aux(NoArvoreBusca *no, int v){
    if(no==NULL){
        return NULL;
    }else{
        if(v<no->info){ 
            return abb_busca_aux(no->esq, v);
        }else{
            if(v>no->info){
		return abb_busca_aux(no->dir, v);
            }else{
                return no;
            }
        }
    }
}  

NoArvoreBusca *abb_busca(ArvoreBusca *a, int v){
    if(a==NULL||a->raiz==NULL){
	return NULL;
    }
    return abb_busca_aux(a->raiz, v);
}

NoArvoreBusca *abb_insere_aux(NoArvoreBusca *no, int v){
    if (no==NULL) {
        NoArvoreBusca *novo = (NoArvoreBusca *) malloc(sizeof(NoArvoreBusca));
        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if(v<no->info){
        no->esq = abb_insere_aux(no->esq,v);
    }else{ 
        no->dir = abb_insere_aux(no->dir, v);
    }    
    return no;
}

void abb_insere(ArvoreBusca *a, int v) {
    if (a !=NULL) {
        a->raiz = abb_insere_aux(a->raiz, v);
    }
}

NoArvoreBusca *abb_retira_aux(NoArvoreBusca *no, int v){
    if(no==NULL){
        return NULL;
    }else{
        if(v<no->info){
            no->esq = abb_retira_aux(no->esq, v);
        }else{
            if(v>no->info){
                no->dir = abb_retira_aux(no->dir, v);
            }else{
                if(no->esq==NULL&&no->dir==NULL){
                    free(no);
                    return NULL;
                }else{
                    if(no->esq==NULL){
                        NoArvoreBusca *temp = no->dir;
                        free(no);
                        return temp;
                    }else{
                        if(no->dir==NULL){
                            NoArvoreBusca *temp = no->esq;
                            free(no);
                            return temp;
                        }else{
                            NoArvoreBusca *p = no->esq;
                            while(p->dir!=NULL){
                                p = p->dir;
                            }
                            no->info = p->info;
                            no->esq = abb_retira_aux(no->esq, p->info);
                        }
                    }
                }
            }
        }
    }
    return no;
}


void abb_retira(ArvoreBusca *a, int v){
    if (a!=NULL) {
        a->raiz = abb_retira_aux(a->raiz, v);
    }
} 

int abb_pertence(ArvoreBusca *a, int v){
    return abb_busca(a, v)!=NULL;
} 

int num_nos_aux(NoArvoreBusca *no){
    if(no == NULL){
        return 0;
    }else{
        return 1 + num_nos_aux(no->esq) + num_nos_aux(no->dir);
    }
}

int abb_num_nos(ArvoreBusca *a){
    if(a == NULL||a->raiz == NULL){
        return 0;
    }
    return num_nos_aux(a->raiz);
} 

int folhas_aux(NoArvoreBusca *no){
    if(no == NULL){
        return 0;
    }
    if(no->esq==NULL && no->dir==NULL){
        return 1;
    }else{
        return folhas_aux(no->esq) + folhas_aux(no->dir);
    }
}

int abb_folhas(ArvoreBusca *a){
    if(a == NULL||a->raiz == NULL){
        return 0;
    }
    return folhas_aux(a->raiz);
} 

int altura_aux(NoArvoreBusca *no){
    if (no == NULL) {
        return -1;
    }
    int ae = altura_aux(no->esq);
    int ad = altura_aux(no->dir);
    if (ae>ad) {
        return ae + 1;
    }else{
        return ad + 1;
    }
}

int abb_altura(ArvoreBusca *a){
    if(a == NULL||a->raiz == NULL){
        return -1;
    }
    return altura_aux(a->raiz);
} 

void abb_imprime_crescente_aux(NoArvoreBusca *no){
    if(no==NULL) return;
    abb_imprime_crescente_aux(no->esq);
    printf("%d ", no->info);
    abb_imprime_crescente_aux(no->dir);
}

void abb_imprime_crescente(ArvoreBusca *a){
    if(a!=NULL){
        abb_imprime_crescente_aux(a->raiz);
    }
} 

void abb_imprime_decrescente_aux(NoArvoreBusca *no){   
    if(no==NULL) return;
    abb_imprime_decrescente_aux(no->dir);
    printf("%d ", no->info);
    abb_imprime_decrescente_aux(no->esq);
}

void abb_imprime_decrescente(ArvoreBusca *a){
    if(a!=NULL){
        abb_imprime_decrescente_aux(a->raiz);
    }
} 

void libera_aux(NoArvoreBusca *no){
    if(no!=NULL){
        libera_aux(no->esq);
        libera_aux(no->dir);
        free(no);
    }
}

void abb_libera(ArvoreBusca *a){
    if(a!=NULL){
        libera_aux(a->raiz);
        free(a);
    }
} 