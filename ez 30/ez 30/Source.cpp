#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	float n, s, m,a = 0,o;
	n = 15 + (rand() % 31);
	bool prime = false;
	
	do {
		a++;
		s = 2 + (rand() % 10);
		m = 2 + (rand() % 10);
		printf("Seu numero e: %d \n Desejas: \n  1) Somar seu numero por %d \n  2) Multiplicar seu numero por %d \n", n,s,m);
		if (scanf_s("%d", &o) == 1)
			n += s;
		else
			m *= m;
		for (int i = 2; i <= n / 2; ++i)
		{
			
			if ((int)n % i == 0)
			{
				prime = true;
			}
		}
		system("cls");
	} while (((int)n % 10) != 1 && ((int)n % 10) != 3 && ((int)n % 10) != 7 && !prime);

	printf("Perdeu! \n Seu numero de acertos: %d \n", a - 1);
	
	system("pause");
	return 0;
}