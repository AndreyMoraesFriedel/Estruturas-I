struct noArvoreBinaria {
    char info[50]; //info: string armazenada no n ́o;
    struct noArvoreBinaria *sae; //sae: ponteiro para a sub ́arvore da esquerda;
    struct noArvoreBinaria *sad; //sad: ponteiro para a sub ́arvore da direita;
};
typedef struct noArvoreBinaria NoArvoreBinaria;

struct arvoreBinaria {
    NoArvoreBinaria *raiz; //raiz: ponteiro para o no raiz principal da  ́arvore.
};
typedef struct arvoreBinaria ArvoreBinaria;

ArvoreBinaria *ab_cria(void); 
// instancia uma nova  ́arvore vazia;

NoArvoreBinaria *ab_cria_no(char *v, NoArvoreBinaria *sae, NoArvoreBinaria *sad); 
//cria e retorna um novo no com a string v e ponteiros para suas sub ́arvores esquerda e direita;

void ab_define_raiz(ArvoreBinaria *a, NoArvoreBinaria *r); 
// define o n ́o raiz principal da  ́arvore;

int ab_vazia(ArvoreBinaria *a); 
// retorna 1 se a  ́arvore estiver vazia, ou 0 caso contr ́ario;

int ab_pertence(ArvoreBinaria *a, char *v); 
// verifica se a string v est ́a armazenada em algum n ́o da  ́arvore;

int pertence_aux(NoArvoreBinaria *raiz, char *v);

int ab_folhas(ArvoreBinaria *a); 
// retorna a quantidade de n ́os do tipo folha da  ́arvore;

int folhas_aux(NoArvoreBinaria *no);

int num_nos_aux(NoArvoreBinaria *no);

int ab_num_nos(ArvoreBinaria *a); 
// retorna a quantidade total de n ́os da  ́arvore;

int igual_aux(NoArvoreBinaria *r1, NoArvoreBinaria *r2);

int altura_aux(NoArvoreBinaria *no);

int ab_altura(ArvoreBinaria *a); 
// retorna a altura da  ́arvore;

int ab_igual(ArvoreBinaria *a1, ArvoreBinaria *a2); 
// verifica se as duas  ́arvores tˆem exatamente a mesma estrutura e os mesmos valores;

void imprime_pre_aux(NoArvoreBinaria *no, char *s);

void ab_imprime_pre(ArvoreBinaria *a); 
// imprime a  ́arvore em pr ́e-ordem;

void imprime_sim_aux(NoArvoreBinaria *no, char *s);

void ab_imprime_sim(ArvoreBinaria *a);
// imprime a  ́arvore em ordem sim ́etrica;

void imprime_pos_aux(NoArvoreBinaria *no, char *s);

void ab_imprime_pos(ArvoreBinaria *a); 
// imprime a  ́arvore em p ́os-ordem;

void libera_aux(NoArvoreBinaria *no);

void ab_libera(ArvoreBinaria *a); 
// libera toda a mem ́oria usada pela  ́arvore.

