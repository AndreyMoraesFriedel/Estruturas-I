#include "tabela_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

TabelaHash *hsh_cria(void){
	TabelaHash *tb = (TabelaHash *) malloc(sizeof(TabelaHash));
	if(tb!=NULL){
		for(int i=0;i<TAM;i++){
			tb->vet[i] = NULL;
		}
	}
	return tb;
}

static int hsh_hash(int matricula){
	return matricula % TAM;
}

Aluno *hsh_get(TabelaHash *tab, int matricula){
	int ind = hsh_hash(matricula);
	Aluno *head = tab->vet[ind];
	while(head!=NULL){
		if(head->matricula==matricula){
			return head;
		}
		head = head->prox;
	}
	return NULL;
}

Aluno *hsh_set(TabelaHash *tab, int matricula, char *nome, char *email, float mediaGeral){
    int ind = hsh_hash(matricula);
    Aluno *head = tab->vet[ind];
    Aluno *atual = head;
    while(atual!=NULL){
        if(atual->matricula==matricula){
            strcpy(atual->nome, nome);
            strcpy(atual->email, email);
            atual->mediaGeral = mediaGeral;
            return atual; 
        }
        atual = atual->prox;
    }
    Aluno *novo = (Aluno *) malloc(sizeof(Aluno));
    if(novo!=NULL){
	    novo->matricula = matricula;
	    strcpy(novo->nome, nome);
	    strcpy(novo->email, email);
	    novo->mediaGeral = mediaGeral;
	    novo->prox = head;
	    tab->vet[ind] = novo;
    }
    return novo; 
}

void hsh_remove(TabelaHash *tab, int matricula){
    int ind = hsh_hash(matricula);
    Aluno *aux = tab->vet[ind];
    Aluno *ant = NULL;
    int naoEncontrou = 1;
    while(aux!=NULL){
        if(aux->matricula==matricula){
	    naoEncontrou = 0;
            if(ant==NULL){
                tab->vet[ind] = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            free(aux);
            break;
        }
        ant = aux;
        aux = aux->prox;
    }
    if(naoEncontrou){
	    printf("Matricula nao encontrada na tabela hash\n");
    }
}

int hsh_contem(TabelaHash *tab, int matricula){
	return hsh_get(tab, matricula)!=NULL;
}

int hsh_quantidade(TabelaHash *tab){
	int qt = 0;
	for(int i = 0;i<TAM;i++){
		Aluno *ck = tab->vet[i];
		while(ck!=NULL){
			qt++;
			ck = ck->prox;
		}
	}
	return qt;
}

int hsh_colisoes(TabelaHash *tab){
	int qt = 0;
	for(int i = 0;i<TAM;i++){
		Aluno *v = tab->vet[i];
		int aux = 0;
		while(v!=NULL){
			aux==1?qt++:aux++;
			v = v->prox;
		}
	}
	return qt;
}

int hsh_maior_lista(TabelaHash *tab){
	int maior = 0;
	for(int i = 0;i<TAM;i++){
		int qt = 0;
		Aluno *v = tab->vet[i];
		while(v!=NULL){
			qt++;
			v = v->prox;
		}
		if(qt>maior){
			maior = qt;
		}
	}
	return maior;
}

void hsh_imprime(TabelaHash *tab){
	for(int i = 0;i<TAM;i++){
		Aluno *v = tab->vet[i];
		while(v!=NULL){
			printf("Matricula: %d\n", v->matricula);
			printf("Nome: %s\n", v->nome);
			printf("Email: %s\n", v->email);
			printf("Media Geral: %.1f\n\n", v->mediaGeral);
			v = v->prox;
		}
	}
}

void hsh_libera(TabelaHash *tab){
	for(int i = 0;i<TAM;i++){
		Aluno *head = tab->vet[i];
		while(head!=NULL){
			Aluno *prox = head->prox;
			free(head);
			head = prox;
		}
	}
	free(tab);
}
