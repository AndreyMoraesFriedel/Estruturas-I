#include "calculadora.h"
#include <string.h>

Calc *calc_cria(char *f){
    Calc *novo = (Calc *) malloc(sizeof(Calc));
    if (novo == NULL){
        printf("Erro de alocação\n");
        exit(1);
    }
    strcpy(novo->f, f);
    novo->p = pilha_cria();
    return novo;
}

void calc_operando(Calc *c, float v){
    pilha_push(c->p, v);
    printf(c->f, pilha_top(c->p));
}

void calc_operador(Calc *c, char op){
    float b = pilha_pop(c->p);
    float a = pilha_pop(c->p);
    float resultado = 0; 
    switch (op)
    {
    case '+':
        resultado = a+b;
        calc_operando(c, resultado);
        break;
    case '-':
        resultado = a-b;
        calc_operando(c, resultado);
        break;
    case '*':
        resultado = a*b;
        calc_operando(c, resultado);
        break;
    case '/':
        resultado = a/b;
        calc_operando(c, resultado);
        break;
    default:
        break;
    }
}

void calc_libera(Calc *c){
    pilha_libera(c->p);
    free(c);
}