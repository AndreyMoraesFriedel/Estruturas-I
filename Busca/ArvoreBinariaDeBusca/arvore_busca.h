struct noArvoreBusca {
    int info; //valor inteiro armazenado no no;
    struct noArvoreBusca *esq; //ponteiro para a sub ́arvore esquerda;
    struct noArvoreBusca *dir; //ponteiro para a sub ́arvore direita;
};
typedef struct noArvoreBusca NoArvoreBusca;

struct arvoreBusca {
    NoArvoreBusca *raiz; //ponteiro para o n ́o raiz principal da  ́arvore.
};
typedef struct arvoreBusca ArvoreBusca;

ArvoreBusca *abb_cria(void); 
//instancia uma nova  ́arvore vazia;

int abb_vazia(ArvoreBusca *a); 
//retorna 1 se a  ́arvore estiver vazia, ou 0 caso contr ́ario;

NoArvoreBusca *abb_busca_aux(NoArvoreBusca *no, int v);
NoArvoreBusca *abb_busca(ArvoreBusca *a, int v); 
//busca o valor v na  ́arvore e retorna o endere ̧co do n ́o encontrado, ou NULL caso o valor n ̃ao esteja na  ́arvore;

NoArvoreBusca *abb_insere_aux(NoArvoreBusca *no, int v);
void abb_insere(ArvoreBusca *a, int v); 
//insere o valor v na  ́arvore, respeitando a propriedade da  ́arvore bin ́aria de busca;

NoArvoreBusca *abb_retira_aux(NoArvoreBusca *no, int v);
void abb_retira(ArvoreBusca *a, int v); 
//remove o valor v da  ́arvore, se ele existir;

int abb_pertence(ArvoreBusca *a, int v); 
//retorna 1 se o valor v pertence `a  ́arvore, ou 0 caso contr ́ario;

int num_nos_aux(NoArvoreBusca *no);
int abb_num_nos(ArvoreBusca *a); 
//retorna a quantidade total de n ́os da  ́arvore;

int folhas_aux(NoArvoreBusca *no);
int abb_folhas(ArvoreBusca *a); 
//retorna a quantidade de n ́os do tipo folha;

int altura_aux(NoArvoreBusca *no);
int abb_altura(ArvoreBusca *a); 
//retorna a altura da  ́arvore;

void abb_imprime_crescente_aux(NoArvoreBusca *no);
void abb_imprime_crescente(ArvoreBusca *a); 
//imprime os valores da  ́arvore em ordem crescente;

void abb_imprime_decrescente_aux(NoArvoreBusca *no);
void abb_imprime_decrescente(ArvoreBusca *a); 
//imprime os valores da  ́arvore em ordem decrescente;

void libera_aux(NoArvoreBusca *no);
void abb_libera(ArvoreBusca *a); 
//libera toda a mem ́oria usada pela  ́arvore.
