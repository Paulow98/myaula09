#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "g2.h"
#include "g2_win32.h"

const unsigned int comp = 300;
const unsigned int alt = 200;


int main() {

	int dev;

	srand((unsigned int)time(NULL));

	dev = g2_open_win32(comp, alt);

	for (unsigned int i = 0; i < comp; i++) {
		for (unsigned int j = 0; j < alt; j++) {
			g2_pen(dev, rand() % 27);
			g2_plot(dev, i, j);
		}
	}

	getchar();
	g2_close(dev);
}
