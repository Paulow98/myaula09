#include "humanos.h"



humanos::humanos()
{
}



void humanos::atacar(humanos * t)
{
	t->subVida(for�a);
}

int humanos::pegaX()
{
	return pos[0];
}

void humanos::setaX(int newX)
{
	pos[0] = newX;
}

int humanos::pegaY()
{
	return pos[1];
}

void humanos::setaY(int newY)
{
	pos[1] = newY;
}

int humanos::pegaVida()
{
	return vida;
}

void humanos::subVida(int valor)
{
	vida -= valor;
}

void humanos::addVida(int valor)
{
	vida += valor;
}

void humanos::setaVida(int newVida)
{
	vida = newVida;
}

void humanos::setaPos(int newX, int newY)
{
	pos[0] = newX;
	pos[1] = newY;
}

int humanos::pegaVidaMax()
{
	return vidaMax;
}

void humanos::setaFor�a(int newFor�a)
{
	for�a = newFor�a;
}

int humanos::pegaFor�a()
{
	return for�a;
}


humanos::~humanos()
{
}
