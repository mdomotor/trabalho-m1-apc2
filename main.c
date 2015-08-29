#include <stdio.h>
#include <stdlib.h>

/***********************************************************
* Nome Aluno: Lucas da Silva Marques	RA: 40795448805 *
* Nome Aluno: Mara Regina Domotor		RA: 42566937850 *
* Data: 29/08/2015 *
* Descrição do programa: Trabalho M1 - Sistema de Cinema *
************************************************************/

typedef enum statusFilme {
	breve,
	exibicao,
	fora_exibicao
} StatusFilme;

typedef struct filmes {
	char nome[50];
	char genero[30];
	char sinopse[500];
	StatusFilme status;
	char ano[4];
} Filme;

typedef struct dadosSessao {
	int sala;
	int qtdLugares;
	float preco;
	Filme filme;
} Sessao;

void listarFilmes(Filme filmes[]);

Filme inserirFilme();

int main(int argc, char *argv[]) {
	return 0;
}

Filme inserirFilme() {
	Filme novoF;
	
	printf("Novo Filme: \nTitulo: ");
	fgets(novoF.nome, 50, stdin);
	printf("Genero: ");
	fgets(novoF.genero, 30, stdin);
	printf("Sinopse: ");
	fgets(novoF.sinopse, 500, stdin);
	printf("Status: (0. em breve / 1. em exibicao / 2. fora de exibicao) ");
	scanf("%i", novoF.status);
	fflush(stdin);
	printf("Ano de Lancamento: ");
	fgets(novoF.ano, 4, stdin);
}
