#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("texte.txt", "a");
	for(int i = 0; i < 200 ; i++)
	fputs("kappa ", fp);

	fclose(fp);
}