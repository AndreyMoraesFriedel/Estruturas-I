#include <stdio.h>
#include "arvore_busca.h"

int main(){
    printf("TESTE ARVORE BINARIA DE BUSCA\n\n");
    ArvoreBusca *abb = abb_cria();
    int valores[] = {6, 2, 8, 1, 4, 3};
    printf("Arvore vazia? %s\n\n", abb_vazia(abb)?"Sim":"Nao");
    printf("Inserindo elementos:\n");
    for(int i = 0;i<6;i++){
        printf("Inserindo %d\n", valores[i]);
        abb_insere(abb, valores[i]);
    }
    printf("\n");
    printf("Arvore vazia? %s\n", abb_vazia(abb)?"Sim":"Nao");
    printf("Impressao crescente:\n");
    abb_imprime_crescente(abb);
    printf("\n\n");
    printf("Impressao decrescente:\n");
    abb_imprime_decrescente(abb);
    printf("\n\n");
    printf("Quantidade de nos: %d\n", abb_num_nos(abb));
    printf("Quantidade de folhas: %d\n", abb_folhas(abb));
    printf("Altura da arvore: %d\n\n", abb_altura(abb));
    int buscas[] = {1, 3, 6, 8, 10};
    for(int i = 0;i<5;i++){
        printf("Valor %d pertence? %s\n", buscas[i], abb_pertence(abb, buscas[i])?"Sim":"Nao");
    }
    printf("\n");
    for(int i = 0;i<5;i++){
        NoArvoreBusca *p = abb_busca(abb, buscas[i]);
        if(p!=NULL){
            printf("Valor %d encontrado\n", buscas[i]);
        }else{
            printf("Valor %d nao encontrado\n", buscas[i]);
        }
    }
    printf("\n");
    printf("Removendo no folha <3>:\n");
    abb_retira(abb, 3);
    abb_imprime_crescente(abb);
    printf("\n\n");

    printf("Recriar a arvore para no com um filho:\n");
    abb_libera(abb);
    abb = abb_cria();
    for(int i = 0;i<6;i++){
        abb_insere(abb, valores[i]);
    }

    printf("Removendo no com um filho <4>:\n");
    abb_retira(abb, 4);
    abb_imprime_crescente(abb);
    printf("\n\n");

    printf("Removendo no com dois filhos <2>:\n");
    abb_retira(abb, 2);
    abb_imprime_crescente(abb);
    printf("\n\n");

    printf("Recriar a arvore para testar raiz:\n");
    abb_libera(abb);
    abb = abb_cria();
    for(int i = 0;i<6;i++){
        abb_insere(abb, valores[i]);
    }

    printf("Removendo a raiz <6>:\n");
    abb_retira(abb, 6);
    abb_imprime_crescente(abb);
    printf("\n\n");
    abb_libera(abb);
    printf("FIM DO TESTE DA ARVORE BINARIA DE BUSCA\n\n");
    
    printf("Problema Aplicado: Consulta de Codigos de Estudantes\n\n");
    ArvoreBusca *est = abb_cria();
    printf("Arvore vazia? %s\n\n", abb_vazia(est)?"Sim":"Nao");
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 55, 65, 75, 85, 10, 25};
    printf("Inserindo codigos:\n");
    for(int i = 0;i<15; i++){
        printf("Inserindo %d\n", codigos[i]);
        abb_insere(est, codigos[i]);
    }
    printf("\n");
    printf("Codigos em ordem crescente:\n");
    abb_imprime_crescente(est);
    printf("\n\n");
    printf("Codigos em ordem decrescente:\n");
    abb_imprime_decrescente(est);
    printf("\n\n");
    int testes[] = {50, 35, 75, 15, 90, 100};
    printf("Verificando existencia de codigos:\n");
    for(int i = 0;i<6; i++){
        printf("Codigo %d: %s\n",testes[i], abb_pertence(est, testes[i])?"Existe":"Nao existe");
    }
    printf("\n");
    printf("Quantidade de total de nos: %d\n", abb_num_nos(est));
    printf("Quantidade de folhas: %d\n", abb_folhas(est));
    printf("Altura da arvore: %d\n\n", abb_altura(est));
    printf("Removendo no folha <10>:\n");
    abb_retira(est, 10);
    abb_imprime_crescente(est);
    printf("\n\n");
    printf("Removendo no com um filho <20>:\n");
    abb_retira(est, 20);
    abb_imprime_crescente(est);
    printf("\n\n");
    printf("Removendo no com dois filhos <70>:\n");
    abb_retira(est, 70);
    abb_imprime_crescente(est);
    printf("\n\n");
    abb_libera(est);
    printf("Fim do problema aplicado\n");
    return 0;
}