#include <stdio.h>
#include <stdlib.h>

#define ASIZE 7

int main(int argc, char *argv[]) {

	/* Variavel tipo ficheiro e nome do ficheiro */
	FILE *fp = NULL;
	char *filename = NULL;

	/* Variaveis a escrever no ficheiro */
	int n = 3;
	char c = 'X';
	char ac[ASIZE] = { 'a', 'b', 'c', 'd', 'e', 'f', '\n' };

	/* Programa requer que utilizador indique um ficheiro atraves da linha
	de comandos */
	if (argc >= 2) {
		filename = argv[1];
	}
	else {
		fprintf(stderr, "Por favor indica um nome de ficheiro!\n");
		exit(1);
	}

	/* Abrir ficheiro para escrita e verificar se abriu correctamente */
	fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Nao foi possivel abrir ficheiro '%s'.\n", filename);
		exit(1);
	}

	/* Escrever varias coisas no ficheiro, de varias formas */

	/* Escrever um caracter de cada vez */
	fputc(c, fp);    // Caracter na var c
	fputc('Y', fp);  // Caracter directo
	fputc(90, fp);   // Caracter via codigo ASCII (Z maiusculo)
	fputc('\n', fp); // Noval inha  

					 /* Escrever uma string directamente */
	fputs("String directamente escrita\n", fp);

	/* Escrever uma string formatada */
	fprintf(fp, "String formatada: %d %c\n", n, c);

	/* Escrever directamente os bits em memoria (de um array neste caso) */
	fwrite(ac, sizeof(char), ASIZE, fp);

	/* Fechar ficheiro. */
	fclose(fp);
	system("pause");
	return 0;
}
