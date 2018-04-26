#include <stdlib.h>
#include <stdio.h>


// 1
void subst_espacos_por_underscores(char *string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ')
			string[i] = '_';
	}
}

// 2
void comprimento_string(char *string)
{
	int comprimento = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		comprimento++;
	}
	printf("%d", comprimento);
}


// 3
int compara_strings_indep_maiusc(char *str1, char *str2)
{
	char diff = 'a' - 'A';
	if (sizeof(str1) != sizeof(str2))
		return 0;
	for (int i = 0; str1[i] != '\0' ; i++)
	{
		if (str1[i] != str2[i] + diff && str1[i] != str2[i] - diff && str1[i] != str2[i])
		{
			return 0;
		}
	}
	return 1;
}




// 4
 void quantas_vezes(char *string, char c)
{
	int contador = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == c)
			contador++;
	}
	printf("%d \n", contador);
}
 
 int main()
 {

 }

