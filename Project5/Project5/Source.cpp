#include <stdio.h>
#include<stdlib.h>

/* Recebe argumento como array. */
void func1(float vec[], int tamanho) {
	for (int i = 0; i < tamanho; ++i) {
		printf("%f\n", vec[i]);
	}
}

/* Recebe argumento como apontador. */
void func2(float *vec, int tamanho) {
	for (int i = 0; i < tamanho; ++i) {
		printf("%f\n", vec[i]);
	}
}

int main() {

	float meu_vec[] = { 1.5, 3.0, 4.5, 6.0 };

	printf("Passar como array:\n");
	func1(meu_vec, 4);

	printf("Passar como apontador:\n");
	func2(meu_vec, 4);
	system("pause");
	return 0;
}
