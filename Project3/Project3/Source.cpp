#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

	unsigned int i, nPerguntas = 0, nRespostasDadas = 0, pNumero, pBase[2], pResposta, rCertas = 0;
	int sair;
	float percCorretas = 0.00;
	char nome[50];
	srand((unsigned int)time(NULL));
	fflush(stdin);
	do {
		void verificar() {
			if (pResposta == pNumero) {
				printf("\nCORRETO!\n");
				rCertas++;
			}
			else if (pResposta<0 || pResposta>255) {
				printf("\nO jogo só tem numeros de 0 a 255. Tens que responder dentro desse limite. Tenta de novo.\n");
			}
			else if (pBase[1] == 0) {
				printf("\nINCORRETO! A resposta é %d.\n", pNumero);
			}
			else if (pBase[1] == 1) {
				printf("\nINCORRETO! A resposta é %x.\n", pNumero);
			}
			else if (pBase[1] == 2) {
				printf("\nINCORRETO! A resposta é %o.\n", pNumero);
			}
		}

		printf("\n\n\nBEM VINDO AO JOGO DE CONVERSÃO DE BASES\n");
		printf("\nQual é o teu nome?\n");
		fflush(stdin);
		gets(nome);
		fflush(stdin);
		printf("\nOlá %s. Então, quantas rondas vais jogar?\nRondas: ", nome);
		scanf("%d", &nPerguntas);

		do {
			for (i = 0; i<nPerguntas; i++)
			{
				pNumero = rand() % 256;
				pBase[0] = rand() % 3;
				do {
					pBase[1] = rand() % 3;
				} while (pBase[0] == pBase[1]);
				do {
					printf("\nPERGUNTA %d de %d\n", i + 1, nPerguntas);
					if (pBase[0] == 0) {// 0 = decimal
						printf("\nQuanto é %d decimal em ", pNumero);
					}
					else if (pBase[0] == 1) {// 1 = hexadecimal
						printf("\nQuanto é %x hexadecimal em ", pNumero);
					}
					else if (pBase[0] == 2) {// 2 = octal
						printf("\nQuanto é %o octal em ", pNumero);
					}

					if (pBase[1] == 0) { // 0 = decimal
						printf("decimal (Base 10)?\nResposta: ");
						scanf("%d", &pResposta);
						fflush(stdin);
						verificar();
					}
					else if (pBase[1] == 1) {  // 1 = hexadecimal
						printf("hexadecimal (Base 16)?\nResposta: ");
						scanf("%x", &pResposta);
						fflush(stdin);
						verificar();
					}
					else if (pBase[1] == 2) { // 2 = octal
						printf("octal (Base 8)?\nResposta: ");
						scanf("%o", &pResposta);
						fflush(stdin);
						verificar();
					}
					nRespostasDadas++;
				} while (pResposta<0 || pResposta>255);
			}
		} while (nPerguntas>nRespostasDadas);
		percCorretas = (rCertas * 100) / nPerguntas;
		printf("\nConseguiste acertar %d em %d! | %.2f%% | Parabéns!\n", rCertas, nPerguntas, percCorretas);
		printf("\nQueres jogar outra vez? (Escreve '0' para sair e '1' para jogar outra vez.)\n");
		scanf("%d", &sair);
		fflush(stdin);
	} while (sair == 1);
	return 0;
}