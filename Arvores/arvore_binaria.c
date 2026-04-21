#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArvoreBinaria *ab_cria(void){
    ArvoreBinaria *ab = (ArvoreBinaria *) malloc(sizeof(ArvoreBinaria));
    ab->raiz = NULL;
    return ab;
}


NoArvoreBinaria *ab_cria_no(char *v, NoArvoreBinaria *sae, NoArvoreBinaria *sad){
    NoArvoreBinaria *novo = (NoArvoreBinaria *) malloc(sizeof(NoArvoreBinaria));
    strcpy(novo->info, v);
    novo->sae = sae;
    novo->sad = sad;
    return novo;
}


void ab_define_raiz(ArvoreBinaria *a, NoArvoreBinaria *r){
    if(a->raiz == NULL){
        a->raiz = r;
    }
}


int ab_vazia(ArvoreBinaria *a){
    if(a->raiz == NULL){
        return 1;
    }else{
        return 0;
    }
}

int pertence_aux(NoArvoreBinaria *raiz, char *v){
    if(raiz == NULL){
        return 0;
    }
    if(strcmp(raiz->info, v)==0){
        return 1;
    }
    return pertence_aux(raiz->sae, v)||pertence_aux(raiz->sad, v);
}


int ab_pertence(ArvoreBinaria *a, char *v){
    return pertence_aux(a->raiz, v);
}

int folhas_aux(NoArvoreBinaria *no){
    if(no == NULL){
        return 0;
    }
    if(no->sae==NULL && no->sad==NULL){
        return 1;
    }else{
        return folhas_aux(no->sae) + folhas_aux(no->sad);
    }
}


int ab_folhas(ArvoreBinaria *a){
    if(a == NULL||a->raiz == NULL){
        return 0;
    }
    return folhas_aux(a->raiz);
}


int num_nos_aux(NoArvoreBinaria *no){
    if(no == NULL){
        return 0;
    }else{
        return 1 + num_nos_aux(no->sae) + num_nos_aux(no->sad);
    }
}

int ab_num_nos(ArvoreBinaria *a){
    if(a == NULL||a->raiz == NULL){
        return 0;
    }
    return num_nos_aux(a->raiz);
}


int altura_aux(NoArvoreBinaria *no) {
    if (no == NULL) {
        return -1;
    }
    int ae = altura_aux(no->sae);
    int ad = altura_aux(no->sad);
    if (ae > ad) {
        return ae + 1;
    } else {
        return ad + 1;
    }
}

int ab_altura(ArvoreBinaria *a){
    if(a == NULL||a->raiz == NULL){
        return -1;
    }
    return altura_aux(a->raiz);
}

int igual_aux(NoArvoreBinaria *r1, NoArvoreBinaria *r2){
    if(r1 == NULL&&r2 == NULL){
        return 1;
    }
    if(r1 ==NULL||r2 == NULL){
        return 0;
    }
    if(strcmp(r1->info, r2->info)!=0){
        return 0;
    }
    return igual_aux(r1->sae, r2->sae) && igual_aux(r1->sad, r2->sad);   
}

int ab_igual(ArvoreBinaria *a1, ArvoreBinaria *a2){
    if (a1 == NULL|| a2 ==NULL){
        return 0; 
    } 
    return igual_aux(a1->raiz, a2->raiz);
}


void imprime_pre_aux(NoArvoreBinaria *no, char *s){
    strcat(s, "<");
    if(no != NULL){
        strcat(s, no->info);
        imprime_pre_aux(no->sae, s);
        imprime_pre_aux(no->sad, s);
    }
    strcat(s, ">");
}

void ab_imprime_pre(ArvoreBinaria *a){
    if(a == NULL|| a->raiz == NULL){
        printf("<>\n");
    } else {
        char s[10000] = "";
        imprime_pre_aux(a->raiz, s);
        printf("%s\n", s);
    }
}


void imprime_sim_aux(NoArvoreBinaria *no, char *s){
    strcat(s, "<");
    if(no != NULL){
        imprime_sim_aux(no->sae, s);
        strcat(s, no->info);
        imprime_sim_aux(no->sad, s);
    }
    strcat(s, ">");
}

void ab_imprime_sim(ArvoreBinaria *a){
    if(a == NULL|| a->raiz == NULL){
        printf("<>\n");
    } else {
        char s[10000] = "";
        imprime_sim_aux(a->raiz, s);
        printf("%s\n", s);
    }
}


void imprime_pos_aux(NoArvoreBinaria *no, char *s){
    strcat(s, "<");
    if(no != NULL){
        imprime_pos_aux(no->sae, s);
        imprime_pos_aux(no->sad, s);
        strcat(s, no->info);
    }
    strcat(s, ">");
}

void ab_imprime_pos(ArvoreBinaria *a){
    if(a == NULL ||a->raiz == NULL){
        printf("<>\n");
    } else {
        char s[10000] = "";
        imprime_pos_aux(a->raiz, s);
        printf("%s\n", s);
    }
}


void libera_aux(NoArvoreBinaria *no){
    if(no!=NULL){
        libera_aux(no->sae);
        libera_aux(no->sad);
        free(no);
    }
}

void ab_libera(ArvoreBinaria *a){
    if(a!=NULL){
        libera_aux(a->raiz);
        free(a);
    }
}

