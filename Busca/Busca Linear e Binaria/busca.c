#include "busca.h"
#include <stdio.h>
#include <stdlib.h>


int *cria_vetor_ordenado(int n){
   if (n<=0) {
      return NULL; 
   }
   int *v = (int *) malloc(n * sizeof(int));
   if(v==NULL){
      return NULL;
   }
   for(int i = 0;i<n;i++){
	   v[i] = i * 2;
   }
   return v;
}

void imprime_vetor(int vet[], int n){
   for(int i = 0;i<n;i++){
	printf("%d ", vet[i]);
   }
   printf("\n");
}

ResultadoBusca busca_linear(int vet[], int n, int elem){
    ResultadoBusca rb;
    rb.indice = -1;
    rb.comparacoes = 0;
    for(int i = 0;i<n;i++){
	rb.comparacoes +=1;
 	if(elem == vet[i]){
	    rb.indice = i;
	    break;
	}
    }
    return rb;
}

ResultadoBusca busca_linear_ordenada(int vet[], int n, int elem){
   ResultadoBusca rb;
   rb.indice = -1;
   rb.comparacoes = 0;
   for(int i = 0;i<n;i++){
	rb.comparacoes += 1;
	if(elem == vet[i]){
	   rb.indice = i;
	   return rb;
	}else{
	   if(elem < vet[i]){
	      return rb;
	   }
	}
   }
   return rb;
}

ResultadoBusca busca_binaria(int vet[], int n, int elem){
   int ini = 0;
   int fim = n-1;

   ResultadoBusca rb;
   rb.indice = -1;
   rb.comparacoes = 0;

   while(ini<=fim){
      rb.comparacoes+=1;
      int meio = ini+(fim-ini)/2;

      if(elem<vet[meio]){
         fim = meio-1;
      }else if(elem>vet[meio]){
         ini = meio+1;
      }else{
         rb.indice = meio;
         return rb;
      }
   }
   return rb;
}

ResultadoBusca busca_binaria_recursiva(int vet[], int n, int elem){
   return busca_binaria_recursiva_aux(vet, 0, n-1,elem, 0);
}

ResultadoBusca busca_binaria_recursiva_aux(int vet[], int ini, int fim, int elem, int comparacoes){
   ResultadoBusca rb;
   rb.indice = -1;
   rb.comparacoes = comparacoes;
   if(ini>fim){
      return rb;
   }
   rb.comparacoes++;
   int meio = ini + (fim-ini)/2;
   if(elem<vet[meio]){
      return busca_binaria_recursiva_aux(vet,ini,meio-1, elem, rb.comparacoes);
   }else{
      if(elem>vet[meio]){
         return busca_binaria_recursiva_aux(vet, meio+1, fim, elem, rb.comparacoes);
      }else{
	 rb.indice = meio;
         return rb;
      }
   }   
}

void libera_vetor(int *vet){
   free(vet);
   vet = NULL;
}
