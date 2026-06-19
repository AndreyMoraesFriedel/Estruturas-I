#define TAM 127

struct aluno {
   int matricula; //chave usada para inserir, buscar e remover estudantes;
   char nome[81]; //nome do estudante;
   char email[81]; //e-mail do estudante;
   float mediaGeral; //media geral do estudante;
   struct aluno *prox; //ponteiro para o proximo estudante na lista de colisao;
};
typedef struct aluno Aluno;

struct tabelaHash {
   Aluno *vet[TAM]; //vetor de ponteiros para as listas encadeadas da tabela hash.
};
typedef struct tabelaHash TabelaHash;

TabelaHash *hsh_cria(void);
//instancia uma nova tabela hash, inicializando todas as posicoes com NULL;

static int hsh_hash(int matricula);  
//calcula o  ́ındice da tabela a partir da matrıcula;

Aluno *hsh_get(TabelaHash *tab, int matricula); 
//busca e retorna o estudante com a matr ́ıcula informada, ou NULL se n ̃ao for encontrado;

Aluno *hsh_set(TabelaHash *tab, int matricula, char *nome, char *email, float mediaGeral);
//insere um novo estudante ou atualiza os dados de um estudante j ́a cadastrado;

void hsh_remove(TabelaHash *tab, int matricula);
//remove o estudante com a matr ́ıcula informada, se ele existir;

int hsh_contem(TabelaHash *tab, int matricula); 
//retorna 1 se a matr ́ıcula estiver cadastrada, ou 0 caso contr ́ario;

int hsh_quantidade(TabelaHash *tab); 
//retorna a quantidade total de estudantes cadastrados;

int hsh_colisoes(TabelaHash *tab); 
//retorna a quantidade de elementos que estao em posi ̧c ̃oes com colis ̃ao;

int hsh_maior_lista(TabelaHash *tab); 
//retorna o tamanho da maior lista encadeada da tabela;

void hsh_imprime(TabelaHash *tab); 
//imprime o conteu ́do completo da tabela hash;

void hsh_libera(TabelaHash *tab); 
//libera toda a mem ́oria utilizada pela tabela hash.