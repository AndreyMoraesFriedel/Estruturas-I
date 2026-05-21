struct noArvoreNaria {
    char info[50]; //string armazenada no no;
    struct noArvoreNaria *prim; //ponteiro para o primeiro filho do no;
    struct noArvoreNaria *prox; //ponteiro para o proximo irmao do no;
};
typedef struct noArvoreNaria NoArvoreNaria;

struct arvoreNaria {
    NoArvoreNaria *raiz; //ponteiro para o n ́o raiz principal da  ́arvore.
};
typedef struct arvoreNaria ArvoreNaria;

ArvoreNaria *an_cria(void); 
//instancia uma nova  ́arvore vazia;
NoArvoreNaria *an_cria_no(char *v); 
//cria e retorna um novo n ́o contendo a string v;
void an_define_raiz(ArvoreNaria *a, NoArvoreNaria *r); 
//define o n ́o raiz principal da  ́arvore;
void an_insere_filho(NoArvoreNaria *pai, NoArvoreNaria *filho); 
//insere o n ́o filho como filho do n ́o pai;
int an_vazia(ArvoreNaria *a); 
//retorna 1 se a  ́arvore estiver vazia, ou 0 caso contr ́ario;
int an_pertence(ArvoreNaria *a, char *v); 
//verifica se a string v est ́a armazenada em algum n ́o da  ́arvore;
int an_pertence_aux(NoArvoreNaria *no, char *v);

int an_num_nos(ArvoreNaria *a); 
//retorna a quantidade total de n ́os da  ́arvore;
int an_num_nos_aux(NoArvoreNaria *no);

int an_folhas(ArvoreNaria *a); 
//retorna a quantidade de n ́os do tipo folha da  ́arvore;
int an_folhas_aux(NoArvoreNaria *no);

int an_altura(ArvoreNaria *a); 
//retorna a altura da  ́arvore;
int an_altura_aux(NoArvoreNaria *no);

int an_igual(ArvoreNaria *a1, ArvoreNaria *a2); 
//verifica se duas  ́arvores possuem exatamente a mesma estrutura e os mesmos valores;
int an_igual_aux(NoArvoreNaria *no, NoArvoreNaria *no2);

void an_imprime(ArvoreNaria *a); 
//imprime a  ́arvore em formato textual, deixando clara a hierarquia entre os n ́os;
void an_imprime_aux(NoArvoreNaria *no);

void an_libera(ArvoreNaria *a); 
//libera toda a mem ́oria usada pela  ́arvore.
void an_libera_aux(NoArvoreNaria *no);