struct fila {
    int tam; //capacidade maxima da fila
    int n; //quantidade atual de elementos armazenados
    int ini; //́ındice da posicao do proximo elemento a ser removido
    int *vet; //vetor de inteiros usado para armazenar os elementos
};
typedef struct fila Fila;

/*
O  ́ındice da proxima posicao livre no final da fila nao deve ser armazenado em um atributo
separado. Sempre que necessario, ele deve ser calculado pela expressao:
fim = (ini + n) % tam;
*/

Fila *fila_cria(int tam);
/*instancia uma nova fila vazia com capacidade m ́axima igual
a tam;*/

void fila_enqueue(Fila *f, int v); 
/*insere o valor v no final da fila. Se a fila estiver
cheia, a fun ̧c ̃ao deve exibir uma mensagem de erro e abortar o programa;*/

int fila_dequeue(Fila *f); 
/*remove e retorna o elemento do in ́ıcio da fila. Se a fila
estiver vazia, a fun ̧c ̃ao deve exibir uma mensagem de erro e abortar o programa;*/

int fila_vazia(Fila *f); 
/*retorna 1 se a fila estiver vazia, ou 0 caso contr ́ario;*/

void fila_imprime(Fila *f); 
/*imprime os elementos da fila na ordem correta, do in ́ıcio
para o fim;*/

void fila_reset(Fila *f); 
//esvazia a fila, reinicializando seus atributos ini e n;

Fila *fila_concatena(Fila *f1, Fila *f2); 
/*cria e retorna uma nova fila contendo, na
mesma ordem, todos os elementos de f1 seguidos de todos os elementos de f2. As filas
originais devem permanecer inalteradas;*/

Fila *fila_merge(Fila *f1, Fila *f2); 
/*cria e retorna uma nova fila contendo os ele-
mentos de f1 e f2 intercalados. Se uma das filas terminar antes da outra, os elementos
restantes da fila maior devem ser copiados ao final. As filas originais devem permanecer
inalteradas;*/

void fila_libera(Fila *f); 
/*libera a mem ́oria usada pela fila, incluindo o vetor interno
e a pr ́opria estrutura.*/