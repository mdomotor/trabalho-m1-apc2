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
	BREVE=0,
	EXIBICAO,
	FORA_EXIBICAO
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

const char * imprimeStatus(StatusFilme status);
StatusFilme recebeStatus(int status);

Filme inserirFilme();
void imprimeFilme(Filme filme);
void listarFilmes(Filme filmes[]);
int alterarStatus();
void buscarFilmesPorGenero(char chave[30], Filme filmes[]);
void buscarFilmesPorNome(char chave[50], Filme filmes[]);
void buscarFilmesPorStatus(int chave, Filme filmes[]);
int checaFilme(char nome[50], Filme filmes[]);

int main(int argc, char *argv[]) {

	printf("\n-----------------------------\n");
	printf("Sistema de Gerenciamento de Sessoes\n");

	return 0;
}

// imprime valor do enum StatusFilme
const char * imprimeStatus(StatusFilme status) {
	switch(status) {
		case 0:
			return "Em Breve";
		break;
		case 1:
			return "Em Exibicao";
		break;
		case 2:
			return "Fora de Exibicao";
		break;
	}
}

// retorne o valor do enum StatusFilme
StatusFilme recebeStatus(int status) {
	switch(status) {
		case 0:
			return BREVE;
		break;
		case 1:
			return EXIBICAO;
		break;
		case 2:
			return FORA_EXIBICAO;
		break;
	}
}

// funcao para imprimir o filme
void imprimeFilme(Filme filme) {
	printf("\n-----------------------------\n");
	printf("Nome: %s\n", filme.nome);
	printf("Genero: %s\n", filme.genero);
	printf("Sinopse: %s\n", filme.sinopse);

	switch (filme.status) {
		case BREVE:
			printf("Status: Em Breve\n");
		break;
		case EXIBICAO:
			printf("Status: Em Exibicao\n");
		break;
		case FORA_EXIBICAO:
			printf("Status: Fora de Exibicao\n");
		break;
	}

	printf("Ano: %d\n", filme.ano);
	printf("\n-----------------------------\n");
}

// funcao para inserir novos filmes
Filme inserirFilme() {
	Filme novoF;
	
	printf("\n-----------------------------\n");
	printf("Novo Filme:\n");
	printf("Titulo:");
	fgets(novoF.nome, 50, stdin);
	printf("Genero: ");
	fgets(novoF.genero, 30, stdin);
	printf("Sinopse: ");
	fgets(novoF.sinopse, 500, stdin);
	printf("Status: (0. em breve / 1. em exibicao / 2. fora de exibicao) ");
	int i;
	scanf("%i", &i);
	novoF.status = recebeStatus(i);
	fflush(stdin);
	printf("Ano de Lancamento: ");
	scanf("%i", &novoF.ano);
	fflush(stdin);
	
	return novoF;
}

// funcao para listar todos os filmes
void listarFilmes(Filme filmes[]) {
	printf("\n-----------------------------\n");
	printf("Lista de filmes:\n\n");
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		 imprimeFilme(filmes[i]);
	}
}

// funcao para alterar status do filme
int alterarStatus() {
	int status;
	
	printf("\n-----------------------------\n");
	printf("Alterar filme:\nDigite o novo status (0. em breve / 1. em exibicao / 2. fora de exibicao): ");
	scanf("%i", &status);
	fflush(stdin);
	
	return recebeStatus(status);
}

// funcao para listar os filmes por genero
void buscarFilmesPorGenero(char chave[30], Filme filmes[]) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", chave);

	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(chave, filmes[i].genero) == 0)
			imprimeFilme(filmes[i]);
	}
}

// funcao para listar os filmes por nome
void buscarFilmesPorNome(char chave[50], Filme filmes[]) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", chave);

	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(chave, filmes[i].nome) == 0)
			imprimeFilme(filmes[i]);
	}
}

// funcao para listar os filmes por status 
void buscarFilmesPorStatus(int chave, Filme filmes[]) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", imprimeStatus(chave));

	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (filmes[i].status == chave) {
			imprimeFilme(filmes[i]);
		}
	}
}

int checaFilme(char nome[50], Filme filmes[]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(filmes[i].nome, nome) == 0)
			return 0;
		else
			return 1;
	}
}