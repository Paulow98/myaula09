#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int pos1, int pos2)
{
	int temp = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = temp;

}
void sort(int* a) {
	int contador = 1;
	while (contador > 0)
	{
		contador = 0;
		for (int i = 0; i < sizeof(a); i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a, i, i + 1);
				contador++;
			}
		}
	}
}



//int main()
//{
//	int n;
//	int* v_reais;
//	printf("Digite o valor de n:");
//	scanf("%d", &n);
//	v_reais = (int*)malloc(sizeof(int) * n);
//	printf("\nDigite %d valores inteiros: ", n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &v_reais[i]);
//		
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ,", v_reais[i]);
//
//	}
//	printf("\n");
//	swap(v_reais, 2, 3);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ,", v_reais[i]);
//
//	}
//	
//
//
//
//	system("pause");
//	return 0;
//}


void *my_calloc(size_t num_elementos, size_t tamanho_de_cada_elemento) {
	int *tmp;
	tmp = (int*) malloc(num_elementos * tamanho_de_cada_elemento);
	for (int i = 0; i < num_elementos; i++)
		tmp[i] = 0;
	
	return tmp;
}

//int main(int argc, char* argv[]) {
//	FILE* f;
//	int total = 0;
//	f = fopen("soma.txt", "w");
//	for (int i = 0; i < argc; i++)
//	{
//		total += atoi(argv[i]);
//	}
//	fprintf(f, "%d", total);
//	
//
//	fclose(f);
//	system("pause");
//	return 0;
//}

#include "pos.h"
int main()
{	

	POS* pos1  = (POS*)malloc(sizeof(POS));
	POS* pos2 = (POS*)malloc(sizeof(POS));
	
	int x, y;
	printf("Digite o X para a pos 1:");
	scanf("%d", &x);
	printf("Digite o Y para a pos 1:");
	scanf("%d", &y);
	pos1 = pos_new(x, y);
	printf("Digite o X para a pos 2:");
	scanf("%d", &x);
	printf("Digite o Y para a pos 2:");
	scanf("%d", &y);
	pos2 = pos_new(x, y);

	int dist = pos_distance(pos1, pos2);
	printf("Distancia: %d",dist);
	system("pause");
	return 0;
}