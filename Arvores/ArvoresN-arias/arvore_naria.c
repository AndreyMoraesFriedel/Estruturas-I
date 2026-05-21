#include "arvore_naria.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ArvoreNaria *an_cria(void){
    ArvoreNaria *an = (ArvoreNaria*) malloc(sizeof(ArvoreNaria));
    an->raiz = NULL;
    return an;
} 

NoArvoreNaria *an_cria_no(char *v){
    NoArvoreNaria *nan = (NoArvoreNaria *) malloc(sizeof(NoArvoreNaria));
    strcpy(nan->info, v);
    nan->prim = NULL;
    nan->prox = NULL;
    return nan;
} 

void an_define_raiz(ArvoreNaria *a, NoArvoreNaria *r){
    a->raiz = r;
} 

void an_insere_filho(NoArvoreNaria *pai, NoArvoreNaria *filho){
    filho->prox = pai->prim;
    pai->prim = filho;
} 

int an_vazia(ArvoreNaria *a){
    return a->raiz == NULL;
} 

int an_pertence(ArvoreNaria *a, char *v){
    if(an_vazia(a)){
	return 0;
    }
    return an_pertence_aux(a->raiz, v);
}

int an_pertence_aux(NoArvoreNaria *no, char *v){
    if (no == NULL) {
        return 0;
    }
    if(strcmp(no->info, v) == 0){
        return 1;
    }else{
        NoArvoreNaria *p = no->prim;
	    while(p!=NULL){
            if(an_pertence_aux(p, v)){
                return 1;
            }
            p = p->prox;
        }
    }
    return 0;
}

int an_num_nos(ArvoreNaria *a){
   if(an_vazia(a)){
	return 0;
   }
   return an_num_nos_aux(a->raiz);
} 

int an_num_nos_aux(NoArvoreNaria *no){
   if(no == NULL){
	return 0;
   }
   return 1 + an_num_nos_aux(no->prim) + an_num_nos_aux(no->prox);
}

int an_folhas(ArvoreNaria *a){
    if(an_vazia(a)){
	return 0;
    }
    return an_folhas_aux(a->raiz);
} 

int an_folhas_aux(NoArvoreNaria *no){
    if(no==NULL){
	return 0;
    }
    if(no->prim==NULL){
	return 1 + an_folhas_aux(no->prox);
    }
    return an_folhas_aux(no->prim) + an_folhas_aux(no->prox);
}

int an_altura(ArvoreNaria *a){
    if(an_vazia(a)){
	return -1;
    }
    return an_altura_aux(a->raiz);
} 

int an_altura_aux(NoArvoreNaria *no){
   int hmax = -1;
   NoArvoreNaria *p = no->prim;
   while(p!=NULL){
      int h = an_altura_aux(p);
      if(h>hmax){
          hmax = h;
      }
      p = p->prox;
   }
   return hmax + 1;
}

int an_igual(ArvoreNaria *a1, ArvoreNaria *a2){
   return an_igual_aux(a1->raiz, a2->raiz);
}

int an_igual_aux(NoArvoreNaria *no, NoArvoreNaria *no2){
   if(no==NULL&&no2==NULL){
	return 1;
   }
   if(no==NULL||no2==NULL){
	return 0;
   }
   if(strcmp(no->info, no2->info)!=0){
	return 0;
   }else{
      return an_igual_aux(no->prim, no2->prim)&&
      an_igual_aux(no->prox, no2->prox);
   }
   
} 

void an_imprime(ArvoreNaria *a){
    if(an_vazia(a)){
	printf("Esta arvore esta vazia\n");
    }else{
	an_imprime_aux(a->raiz);
        printf("\n");
    }    
}

void an_imprime_aux(NoArvoreNaria *no){
    if (no==NULL) return;
    printf("<%s", no->info);
    NoArvoreNaria *p = no->prim;
    while(p!=NULL){
        an_imprime_aux(p);
        p = p->prox;
    }
    printf(">");
} 

void an_libera(ArvoreNaria *a){
   if(!an_vazia(a)){
	an_libera_aux(a->raiz);
    }
    free(a);
}

void an_libera_aux(NoArvoreNaria *no){
    if (no == NULL) return;
    NoArvoreNaria *p = no->prim;
    while(p!=NULL){
        NoArvoreNaria *aux = p;
	p = p->prox;
        an_libera_aux(aux);
    }
    free(no);
} 