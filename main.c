#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************
* Nome Aluno: Lucas da Silva Marques	RA: 40795448805 *
* Nome Aluno: Mara Regina Domotor		RA: 42566937850 *
* Data: 29/08/2015 *
* Descrição do programa: Trabalho M1 - Sistema de Cinema *
************************************************************/

// opcoes de status de filme
typedef enum statusFilme {
	breve,
	exibicao,
	fora_exibicao
} StatusFilme;

// struct com os dados do filme
typedef struct filmes {
	char nome[50];
	char genero[30];
	char sinopse[500];
	StatusFilme status;
	int ano;
} Filme;

// scruct com os dados da sessao
typedef struct dadosSessao {
	int sala;
	int qtdLugares;
	float preco;
	Filme filme;
} Sessao;

void imprimeFilme(Filme filme);
Filme inserirFilme();
void listarFilmes(Filme filmes[]);
int alterarStatus();
void buscarFilmesPorGenero(char chave[30], Filme filmes[]);
void buscarFilmesPorNome(char chave[50], Filme filmes[]);

int main(int argc, char *argv[]) {
	return 0;
}

// funcao para imprimir o filme
void imprimeFilme(Filme filme) {
	printf("\n-----------------------------\n");
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
	printf("\n-----------------------------\n");
}

// funcao para inserir novos filmes
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
	scanf("%i", novoF.ano);
	fflush(stdin);
	
	return novoF;
}

// funcao para listar todos os filmes
void listarFilmes(Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		 imprimeFilme(filmes[i]);
	}
}

// funcao para alterar status do filme
int alterarStatus() {
	int status;
	
	printf("Alterar filme:\nDigite o novo status (0. em breve / 1. em exibicao / 2. fora de exibicao): ");
	scanf("%i", status);
	fflush(stdin);
	
	return status;
}

// funcao para listar os filmes por genero
void buscarFilmesPorGenero(char chave[30], Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(chave, filmes[i].genero) == 0)
			imprimeFilme(filmes[i]);
	}
}

void buscarFilmesPorGenero(char chave[50], Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(chave, filmes[i].nome) == 0)
			imprimeFilme(filmes[i]);
	}
}