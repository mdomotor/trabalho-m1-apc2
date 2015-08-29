#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************
* Nome Aluno: Lucas da Silva Marques	RA: 40795448805 *
* Nome Aluno: Mara Regina Domotor		RA: 42566937850 *
* Data: 29/08/2015 *
* Descricao do programa: Trabalho M1 - Sistema de Cinema *
************************************************************/

// opcoes de status de filme
typedef enum statusFilme {
	BREVE=0,
	EXIBICAO,
	FORA_EXIBICAO
} StatusFilme;

typedef enum Menu {
	SAIR=0,
	INSERIR_FILME,
	CRIAR_SESSAO,
	LISTAR_FILMES,
	ALTERAR_STATUS,
	BUSCAR_POR_GENERO,
	BUSCAR_POR_NOME,
	BUSCAR_POR_STATUS
} Menu;

// struct com os dados do filme
typedef struct filmes {
	int codigo;
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

int contF = 0;
Filme *filmes;
int contS = 0;
Sessao *sessoes;

const char * imprimirStatus(StatusFilme status);
StatusFilme receberStatus(int status);

void inserirFilme();
void criarSessao();
void imprimirFilme(Filme filme);
void listarFilmes();
StatusFilme alterarStatus();
void buscarFilmesPorGenero(char chave[30]);
void buscarFilmesPorNome(char chave[50]);
void buscarFilmesPorStatus(int chave);
void imprimirMenu();
int checarFilme(char nome[50]);

int main(int argc, char *argv[]) {
	int menu;

	printf("\n-----------------------------\n");
	printf("Sistema de Gerenciamento de Sessoes\n");
	imprimirMenu();
	
	
	return 0;
}

// imprime valor do enum StatusFilme
const char * imprimirStatus(StatusFilme status) {
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
StatusFilme receberStatus(int status) {
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
void imprimirFilme(Filme filme) {
	printf("\n-----------------------------\n");
	printf("Codigo: %d\n", filme.codigo);
	printf("Nome: %s\n", filme.nome);
	printf("Genero: %s\n", filme.genero);
	printf("Sinopse: %s\n", filme.sinopse);
	printf("Status: %s\n", imprimirStatus(filme.status));
	printf("Ano: %d\n", filme.ano);
	printf("\n-----------------------------\n");
}

// funcao para inserir novos filmes
void inserirFilme() {
	Filme novoF;
	int i;
	char nome[50];
	char genero[30];
	char acao = 'c';
	
	printf("\n-----------------------------\n");
	printf("Novo Filme:\n");
	
	// verifica se o titulo ja existe
	do {
		printf("Titulo (obrigatorio):");
		fgets(novoF.nome, 50, stdin);
	} while (strlen(novoF.nome) < 1);

	int filmeOk = checarFilme(nome);
	
	// verifica se o titulo foi preenchido
	while (filmeOk == 0) {
		printf("Filme ja existente.\nDigite 'c' para tentar de novo ou 's' para sair: ");
		scanf("%c", &acao);
		if (acao != 'c') {
			exit(0);
		} else {
			do {
				printf("Titulo (obrigatorio):");
				fgets(nome, 50, stdin);
			} while (strlen(nome) < 1);

			filmeOk = checarFilme(nome);
		}
	}

	strcpy(novoF.nome, nome);
	
	// verifica se o genero foi preenchido
	do {
		printf("Genero (obrigatorio): ");
		fgets(genero, 30, stdin);
	} while (strlen(genero) < 1);

	strcpy(novoF.genero, genero);

	printf("Sinopse: ");
	fgets(novoF.sinopse, 500, stdin);

	// verifica se o status foi preenchido
	do {
		printf("Status (obrigatorio - 0. em breve / 1. em exibicao / 2. fora de exibicao): ");
		scanf("%i", &i);
	} while ((i >= 0)||(i <= 2));

	novoF.status = receberStatus(i);

	fflush(stdin);

	printf("Ano de Lancamento: ");
	scanf("%i", &novoF.ano);

	fflush(stdin);

	novoF.codigo = contF;

	filmes[contF] = novoF;
	contF++;
}

// funcao para criar nova sessao
void criarSessao() {
	
}

// funcao para listar todos os filmes
void listarFilmes() {
	printf("\n-----------------------------\n");
	printf("Lista de filmes:\n\n");
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		 imprimirFilme(filmes[i]);
	}
}

// funcao para alterar status do filme
StatusFilme alterarStatus() {
	int status;
	
	printf("\n-----------------------------\n");
	printf("Alterar filme:\nDigite o novo status (0. em breve / 1. em exibicao / 2. fora de exibicao): ");
	scanf("%i", &status);
	fflush(stdin);
	
	return receberStatus(status);
}

// funcao para listar os filmes por genero
void buscarFilmesPorGenero(char chave[30]) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", chave);

	int i;
	int cont=0;
	
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(strlwr(chave), strlwr(filmes[i].genero) == 0)
			imprimirFilme(filmes[i]);
			cont++;
	}
	
	if (cont==0) {
		printf("Nenhum filme encontrado.");
	}
}

// funcao para listar os filmes por nome
void buscarFilmesPorNome(char chave[50]) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", chave);

	int i;
	int cont=0;
	
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(strlwr(chave), strlwr(filmes[i].nome)) == 0)
			imprimirFilme(filmes[i]);
			cont++;
	}
	
	if (cont==0) {
		printf("Nenhum filme encontrado.");
	}
}

// funcao para listar os filmes por status 
void buscarFilmesPorStatus(int chave) {
	printf("\n-----------------------------\n");
	printf("Resultados para %s:\n", imprimirStatus(chave));

	int i;
	int cont=0;
	
	for (i = 0; i < sizeof(filmes); i++) {
		if (filmes[i].status == chave) {
			imprimirFilme(filmes[i]);
			cont++;
		}
	}
	
	if (cont==0) {
		printf("Nenhum filme encontrado.");
	}
}

// funcao para checar se o filme existe (0) ou nao (1)
int checarFilme(char nome[50]) {
	int i;
	for (i = 0; i < sizeof(filmes); i++) {
		if (strcmp(strlwr(filmes[i].nome), strlwr(nome)) == 0)
			return 0;
		else
			return 1;
	}
}

void imprimirMenu() {
	printf("MENU\n");
	printf("1 - Inserir Filme\n");
	printf("2 - Criar Sessao\n");
	printf("3 - Listar Filmes\n");
	printf("4 - Alterar Status\n");
	printf("5 - Buscar Filme por Genero\n");
	printf("6 - Buscar Filme por Nome\n");
	printf("7 - Buscar Filme por Status\n");
	printf("0 - Sair\n");
}
