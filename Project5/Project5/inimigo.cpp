#include "inimigo.h"



inimigo::inimigo()
{
	srand(time_t(NULL));
	setaForça(rand() % 10);
	setaVida(rand() % 15);
	setaPos(0, 0);

}

inimigo::~inimigo()
{
}
