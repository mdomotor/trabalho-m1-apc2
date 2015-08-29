#include <stdio.h>
#include <stdlib.h>

/***********************************************************
* Nome Aluno: Lucas da Silva Marques	RA: 40795448805 *
* Nome Aluno: Mara Regina Domotor		RA: 42566937850 *
* Data: 29/08/2015 *
* Descrição do programa: Trabalho M1 - Sistema de Cinema *
************************************************************/

enum statusFilme { breve, exibicao, fora_exibicao };

struct filmes
{
	char filme[50];
	char genero[30];
	char sinopse[500];
	enum statusFilme status;
	char ano[4];
};

struct dadosSessao {
	int sala;
	int qtdLugares;
	float preco;
	struct filmes filme;
};

void listarFilmes(dadosSessao )

int main(int argc, char *argv[]) {
	return 0;
}
