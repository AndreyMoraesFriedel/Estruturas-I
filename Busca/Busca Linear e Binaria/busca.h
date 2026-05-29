struct resultadoBusca {
	int indice; //posi ̧c ̃ao em que o elemento foi encontrado, ou -1 caso o elemento n ̃ao esteja no vetor;
	int comparacoes; //quantidade de compara ̧c ̃oes realizadas entre o elemento procurado e elementos do vetor.
};
typedef struct resultadoBusca ResultadoBusca;

int *cria_vetor_ordenado(int n);
//cria dinamicamente um vetor ordenado com n ele-mentos;

void imprime_vetor(int vet[], int n);
//imprime os elementos do vetor;

ResultadoBusca busca_linear(int vet[], int n, int elem);
//percorre o vetor elemento a elemento at ́e encontrar elem ou at ́e chegar ao final;

ResultadoBusca busca_linear_ordenada(int vet[], int n, int elem);
//percorre o vetor ordenado e interrompe a busca quando encontrar um valor maior que elem;

ResultadoBusca busca_binaria(int vet[], int n, int elem);
//implementa a busca bin ́aria de forma iterativa;

ResultadoBusca busca_binaria_recursiva(int vet[], int n, int elem);
//fun ̧c ̃ao pu ́blica que chama a vers ̃ao recursiva da busca bin ́aria;

ResultadoBusca busca_binaria_recursiva_aux(int vet[], int ini, int fim, int elem, int comparacoes);
//fun ̧c ̃ao auxiliar recursiva que realiza a busca no intervalo ini..fim;

void libera_vetor(int *vet);
//libera o vetor alocado dinamicamente.