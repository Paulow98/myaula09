#pragma once
#include<iostream>
#include<time.h>
class humanos
{
	int vida;
	int vidaMax;
	int força;
	int pos[2];
	
public:
	humanos();
	void atacar(humanos* t);
	
	int pegaX();
	void setaX(int newX);

	int pegaY();
	void setaY(int newY);

	int pegaVida();
	void subVida(int valor);
	void addVida(int valor);
	void setaVida(int newVida);

	void setaPos(int newX, int newY);
	int pegaVidaMax();

	void setaForça(int newForça);
	int pegaForça();
	void mover();
	~humanos();
};

