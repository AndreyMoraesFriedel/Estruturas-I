#include "pilha.h"
#include "calculadora.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gcc calculadora.c pilha.c principal.c -o prin && ./prin
int main(){
    Pilha *pilha = pilha_cria();
    pilha_push(pilha, 1);
    pilha_push(pilha, 2);
    pilha_push(pilha, 3);
    pilha_push(pilha, 4);
    pilha_push(pilha, 5);


    printf("Pilha com 5  elementos\n");
    pilha_imprime(pilha);

    printf("\n");

    printf("Topo da lista %f\n", pilha_top(pilha));
    printf("Pilha vazia: %d\n", pilha_vazia(pilha));

    printf("\n");

    printf("Retirando topo da lista\n");
    pilha_pop(pilha);
    pilha_imprime(pilha);

    printf("\n");

    printf("Liberando a pilha\n");
    pilha_libera(pilha);
    printf("Pilha vazia: %d\n", pilha_vazia(pilha));

    printf("\n\n=====TESTANDO CALCULADORA=====\n\n");

    char f[21] = "%.2f\n";
    Calc *cal = calc_cria(f); 
    calc_operando(cal, 1.02);
    calc_operando(cal, 2.98);
    calc_operador(cal, '+');
    calc_operando(cal, 5);
    calc_operador(cal, '-');
    calc_operando(cal, -1);
    calc_operador(cal, '*');
    calc_operando(cal, 2);
    calc_operando(cal, 2);
    calc_operador(cal, '/');
    calc_operador(cal, '/');

    printf("Liberando a Calculadora...\n");
    calc_libera(cal);
    cal = NULL;

    printf("\n\n=====FIM DO TESTE=====\n\n");
    
    printf("\n\n=====IMPLEMENTACAO CALCULADORA=====\n\n");
    Calc *c = calc_cria(f);
    char entrada[100];
    fgets(entrada, 100, stdin);
    //encontra onde está o \n e substitui por \0 (fim da string)
    //vai ajudar na hora do token/ponteiro prosseguir
    entrada[strcspn(entrada, "\n")] = '\0';
    //da uma splitzada no texto colocando \0 de delimitador no lugar dos espacos
    char *token = strtok(entrada, " ");
    //enquanto ainda existirem tokens
    while(token!=NULL){
        if(strcmp(token, "q")==0){
            break;
        }
        //token[0] é o primeiro caractere do token atual (string apontada por token)
        if(token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/'){
            calc_operador(c, token[0]);
        }else{
            //em c e atoi (ASCII para inteiro) e em c++ utilizo stoi (string para int)
            int valor = atoi(token);
            calc_operando(c, valor);
        }
        //Continua de onde parou na posicao interna e vai para o proximo token
        token = strtok(NULL, " ");
    }
    printf("\n\n=====FIM DA IMPLEMENTACAO=====\n\n");
    return 0;
}