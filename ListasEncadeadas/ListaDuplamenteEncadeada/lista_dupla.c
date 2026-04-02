#include "lista_Dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NoListaDupla *dllCria(void){
    return NULL;
}

NoListaDupla *dllInsere(NoListaDupla *head, char *v){
    NoListaDupla *novo = (NoListaDupla*) malloc(sizeof(NoListaDupla));
    strcpy(novo->info, v); 
    novo->prox = head;
    novo->ant = NULL;
    if (head != NULL){
        head->ant = novo;
    }
    return novo;
}

void dllImprime(NoListaDupla *head){
    int i = 1;
    while (head != NULL){
        printf("%d. %s\n", i, head->info);
        i++;
        head = head->prox;
    }
}

int dllVazia(NoListaDupla *head){
    return head == NULL;
}

NoListaDupla *dllBusca(NoListaDupla *head, char *v){
    while (head != NULL){
            if (strcmp(head->info, v) == 0){
                return head;
            }
            head = head->prox;
        }
        return NULL;
}

int dllComprimento(NoListaDupla *head){
    int comprimento = 0;    
    while (head != NULL){
        comprimento++;
        head = head->prox;
    }
    return comprimento;
}

NoListaDupla *dllUltimo(NoListaDupla *head){
    if (head == NULL){
        return NULL;
    }
    while (head->prox != NULL){
        head = head->prox;
    }
    return head;
}

NoListaDupla *dllRetira(NoListaDupla *head, char *v){
    NoListaDupla *busca = dllBusca(head, v);
    if (busca != NULL){
        if (busca->ant == NULL){ 
            NoListaDupla *temp = busca;      
            head = busca->prox;        
            if (head != NULL){
                head->ant = NULL; 
            }
            free(temp);
        }
        else if (busca->prox == NULL){
            NoListaDupla *temp = busca;
            busca->ant->prox = NULL;
            free(temp);
        }
        else{
            NoListaDupla *temp = busca;
            busca->ant->prox = busca->prox;
            busca->prox->ant = busca->ant;            
            free(temp);
        }
    }   
    return head;
}

void dllLibera(NoListaDupla *head){
    NoListaDupla *p = head;
    while (p != NULL){
        NoListaDupla *temp = p;
        p = p->prox;
        free(temp);
    }
}

NoListaDupla *dllInsereFim(NoListaDupla *head, char *v){
    if (head == NULL){
       return dllInsere(NULL, v);
    }
    
    if (head->prox == NULL){
        NoListaDupla *novo = (NoListaDupla*) malloc(sizeof(NoListaDupla));
        strcpy(novo->info, v);
        novo->prox = NULL;
        head->prox = novo;
        novo->ant = head;
    } else{
        dllInsereFim(head->prox, v);
    }
    return head;
}

NoListaDupla *dllInserePosEsp(NoListaDupla *head, char *v, int pos){
    NoListaDupla *checkpoint = head;
    int comp = dllComprimento(head);
    if(pos==1){
        return dllInsere(head, v);
    }
    if(pos>comp || pos <= 0){
        printf("posição inválida\n");
        return head;
    }
    pos -=1;
    //printf("Posicao: %d\n", pos);
    //printf("Comprimento: %d\n", comp);  
    int i = 0;
    NoListaDupla *ant;
    NoListaDupla *seguinte;
    while(i<pos){
        ant = head;
        head = head->prox; 
        i++;
    }
    seguinte = ant->prox;
    //printf("O anterior eh: %s\n", ant->info);
    //printf("O seguinte eh: %s\n", seguinte->info);
    NoListaDupla *novo = (NoListaDupla *) malloc(sizeof(NoListaDupla));
    strcpy(novo->info, v);
    novo->ant = ant;
    ant->prox = novo;
    novo->prox = seguinte;
    seguinte->ant = novo;
    return checkpoint;
}

NoListaDupla *dllRetiraPosEsp(NoListaDupla *head, int pos){
    NoListaDupla *checkpoint = head;
    int comp = dllComprimento(head);
    if(pos==1){
        NoListaDupla *temp = head;      
        head = head->prox;        
        if (head != NULL){
            head->ant = NULL; 
        }
        free(temp);
        return head;
    }
    if(pos>comp || pos <= 0){
        printf("posição inválida\n");
    }
    if(pos==comp){
        NoListaDupla *ult = dllUltimo(head);
        NoListaDupla *antP = ult->ant;
        antP->prox = NULL;
        ult->ant = NULL;
        free(ult);
        return head;
    }
    pos -=1;
    int i = 0;
    NoListaDupla *ant;
    NoListaDupla *elementoQueroApagar;
    NoListaDupla *seguinte;
    while(i<pos){
        ant = head;
        head = head->prox; 
        i++;
    }
    elementoQueroApagar = ant->prox;
    seguinte = elementoQueroApagar->prox;
    ant->prox = seguinte;
    seguinte->ant = ant;
    free(elementoQueroApagar);
    return checkpoint;
}

NoListaDupla *dllElementoNaPosEsp(NoListaDupla *head, int posEsp){
    int i = 1;
    while (head != NULL && i < posEsp){
        head = head->prox;
        i++;
    }
    if (head == NULL){
        printf("posicao invalida\n");
        return NULL;
    }
    //printf("%s\n", head->info);
    return head;
}

NoListaDupla *dllMoverMusica(NoListaDupla *head, int posAtual, int posDesejada){
    NoListaDupla *ele = dllElementoNaPosEsp(head, posAtual);
    if (ele == NULL){
        printf("Posição inválida\n");
        return head;
    }
    char info[100];
    strcpy(info, ele->info);
    head = dllRetiraPosEsp(head, posAtual);
    if (posAtual < posDesejada){
        posDesejada-=1; 
    }
    head = dllInserePosEsp(head, info, posDesejada);
    return head;
}