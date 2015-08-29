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
	int ano;
} Filme;

typedef struct dadosSessao {
	int sala;
	int qtdLugares;
	float preco;
	Filme filme;
} Sessao;

void imprimeFilme(Filme filme);
void listarFilmes(Filme filmes[]);
void buscarFilmesPorGenero(char chave[30], Filme filmes[]);

int main(int argc, char *argv[]) {
	return 0;
}

void imprimeFilme(Filme filme) {
	printf("\n########################\n");
	printf("Nome: %s\n", filme.nome);
	printf("Genero: %s\n", filme.genero);
	printf("Sinopse: %s\n", filme.sinopse);

	switch (filme.status) {
		case breve:
			printf("Status: Em Breve\n");
		break;
		case exibicao:
			printf("Status: Em Exibicao\n");
		break;
		case fora_exibicao:
			printf("Status: Fora de Exibicao\n");
		break;
	}

	printf("Ano: %d\n", filme.ano);
	printf("\n########################\n");
}

void listarFilmes(Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		 imprimeFilme(filmes[i]);
	}
}

void buscarFilmesPorGenero(char chave[30], Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (filmes[i].genero == chave) {
			imprimeFilme(filmes[i]);
		}
	}
}