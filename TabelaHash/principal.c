#include "tabela_hash.h"
#include <stdio.h>

int main(){
	printf("Problema Aplicado: Cadastro de Estudantes\n");
	TabelaHash *th = hsh_cria();
	int matriculas[] = {1001, 1128, 1255, 1382, 2002, 2129, 2256, 3003, 3130,4010, 5020, 6030, 7040, 8050, 9060};
	printf("Inserindo Alunos:\n");
	Aluno *alunos[15];
	for(int i = 0;i<15;i++){
		printf("Inserindo aluno %d de matricula %d\n", i+1,matriculas[i]);
		alunos[i] = hsh_set(th, matriculas[i], "generico", "generico@gmail.com", 8.0);
	}
	int extin[] = {1001, 1128, 1255, 20, 55, 77};
	for(int i = 0;i<6;i++){
		printf("Estudante de matricula: %d %s\n", extin[i], hsh_get(th, extin[i])!=NULL?"foi encontrado":"e inexistente");
	}
	printf("Atualizando aluno:\n");
	Aluno *andrey = hsh_set(th, 9060, "andrey", "andrey@gmail.com", 10.0);
	printf("Nome atualizado: %s\n", andrey->nome);
	printf("Media atualizada: %.1f\n", andrey->mediaGeral);
	printf("Removendo cabeca de lista de colisao <1382>\n");
	hsh_remove(th, 1382);
	printf("Matricula 1382 %s\n",hsh_get(th, 1382)==NULL?"removida":"ainda existe");
	printf("Removendo elemento do meio da lista <1128>\n");
	hsh_remove(th, 1128);
	printf("Matricula 1128 %s\n", hsh_get(th, 1128)==NULL?"removida":"ainda existe");
	printf("Removendo matricula inexistente <33>\n");
	hsh_remove(th, 33);
	printf("Imprimindo Tabela Hash:\n");
	hsh_imprime(th);
	printf("Quantidade Total de estudantes:%d\n", hsh_quantidade(th));
	printf("Quantidade de colisoes:%d\n", hsh_colisoes(th));
	printf("Tamanho da maior lista da tabela:%d\n", hsh_maior_lista(th));
	printf("Liberando Memoria da tabela\n");
	hsh_libera(th);
	return 0;
}
