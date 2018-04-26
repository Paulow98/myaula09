#include <stdio.h>

/* Declaracao de enum para estilo de tipo de letra */
typedef enum {
	ITALIC = 0x1, /* 0001 */
	BOLD = 0x2, /* 0010 */
	UNDERLINE = 0x4, /* 0100 */
	STRIKEOUT = 0x8  /* 1000 */
} FONT_STYLE;

/* Funcao para mostrar estilo */
void showstyle(int style) {
	printf(" (0x%X)", style);
	if (style & ITALIC)    printf(" Italic");
	if (style & BOLD)      printf(" Bold");
	if (style & UNDERLINE) printf(" Underline");
	if (style & STRIKEOUT) printf(" Strikeout");
	printf("\n");
}

int main() {

	/* Variaveis definindo diferentes estilos */
	int style1 = ITALIC | BOLD;
	int style2 = 0;
	int style3 = STRIKEOUT | BOLD;
	int style4 = BOLD | UNDERLINE | ITALIC;

	/* Mostrar estilos definidos na variavel */
	printf("style1:");
	showstyle(style1);

	printf("style2:");
	showstyle(style2);

	printf("style3:");
	showstyle(style3);

	printf("style4:");
	showstyle(style4);

	return 0;

}