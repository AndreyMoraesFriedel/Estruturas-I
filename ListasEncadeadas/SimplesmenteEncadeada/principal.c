#include <stdio.h>
#include "lista_simples.h"

int main(){
        NoLista *lista;
        NoLista *lista2;
        lista = sllCria();
        if(sllVazia(lista) == 1){
                printf("Lista Esta Vazia\n");
        }
        printf("Inserindo valores na lista\n");
        lista = sllInsere(lista, 1);
        lista = sllInsereFim(lista, 2);
        lista = sllInsereFim(lista, 4);
        lista = sllInsereFim(lista, 3);
        lista = sllInsereFim(lista, 5);
        
        lista2 = sllInsere(lista2, 1);
        lista2 = sllInsereFim(lista2, 2);
        lista2 = sllInsereFim(lista2, 4);
        lista2 = sllInsereFim(lista2, 3);
        lista2 = sllInsereFim(lista2, 5);
        //lista2 = sllInsereFim(lista2, 6);
        printf("Comparando as duas listas:\n");
        //printf("Elas sao iguais? %s\n", sllIgualRecursivo(lista, lista2) ? "Sim" : "Nao");
        printf("Elas sao iguais? %s\n", sllIgual(lista, lista2) ? "Sim" : "Nao");

        if(sllVazia(lista) == 0){
                printf("Lista nao esta vazia\n");
        }
        //sllImprime(lista);
        sllImprimeRecursivo(lista);
        printf("Comprimento da Lista: \n");
        printf("%i\n", sllComprimentoRecursivo(lista));
        int v = 3;
        int f = 0;
        NoLista *bv = sllBusca(lista, v);
        NoLista *bf = sllBusca(lista, f);
        if(bv!=NULL){
                printf("O valor %i esta na lista\n", v);
        }
        if(bf==NULL){
                printf("O valor %i nao esta na lista\n", f);
        }
        NoLista *ultimo = sllUltimo(lista);
        if(ultimo!=NULL){
                printf("Ultimo numero da lista %f\n", ultimo->info);
        }
        printf("Remover elemento %i\n", v);
        lista = sllRetiraRecursivo(lista, v);
        //sllImprime(lista);
        sllImprimeRecursivo(lista);
        printf("Liberando as listas\n");
        sllLiberaRecu(lista);
        sllLibera(lista2);
        lista = NULL;
        lista2 = NULL;
        return 0;

}