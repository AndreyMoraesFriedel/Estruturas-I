#include "busca.h"
#include <stdio.h>

int main(){
   //PARTE2
   int *v = cria_vetor_ordenado(10);
   imprime_vetor(v, 10);
   printf("\n");
   char *nomes[] = {"linear", "linear_ord", "binaria", "binaria_rec"};
   int tes[] = {0, 10, 20};
   for(int i = 0;i<3;i++){
      ResultadoBusca bl = busca_linear(v, 10, tes[i]);
      ResultadoBusca blo = busca_linear_ordenada(v, 10, tes[i]);
      ResultadoBusca bbi = busca_binaria(v, 10, tes[i]);
      ResultadoBusca bbr = busca_binaria_recursiva(v, 10, tes[i]);
      ResultadoBusca rbs[] = {bl, blo, bbi, bbr};
      for(int j = 0;j<4;j++){
         printf("%s: ", nomes[j]);
         printf("Valor procurado %d, indice retornado %d, qt comparacoes %d\n", tes[i], rbs[j].indice, rbs[j].comparacoes);
      }
      printf("\n");
   }
   libera_vetor(v);
   //PARTE3
   int valores[] = {10, 100, 1000, 10000, 100000};
   for(int j = 0;j<2;j++){
      printf("%s\n", j==0?"Ultimo elemento do vetor:":"Elemento nao esta no vetor:");
      for(int i = 0;i<5;i++){
         int *v = cria_vetor_ordenado(valores[i]);
         int t = j==0?v[valores[i]-1]:-2;
         ResultadoBusca bl = busca_linear(v, valores[i], t);
         ResultadoBusca blo = busca_linear_ordenada(v, valores[i], t);
         ResultadoBusca bbi = busca_binaria(v, valores[i], t);
         ResultadoBusca bbr = busca_binaria_recursiva(v, valores[i], t);
         if(i==0){
            printf("%-10s %-10s %-10s %-10s %-10s %-10s\n","n", "elem", "linear", "linear_ord", "binaria", "binaria_rec");
         }
         printf("%-10d %-10d %-10d %-10d %-10d %-10d\n", valores[i], t, bl.comparacoes, blo.comparacoes, bbi.comparacoes, bbr.comparacoes);
      }
      printf("\n");  
   } 
   return 0;
}