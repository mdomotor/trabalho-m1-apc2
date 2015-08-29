#include <stdio.h>
#include <stdlib.h>

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

void listarFilmes(Filme filmes[]);

Filme inserirFilme();

int alterarStatus();

int main(int argc, char *argv[]) {
	return 0;
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

// funcao para alterar status do filme
int alterarStatus() {
	int status;
	
	printf("Alterar filme:\nDigite o novo status (0. em breve / 1. em exibicao / 2. fora de exibicao): ");
	scanf("%i", status);
	fflush(stdin);
	
	return status;
}


