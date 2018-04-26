#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct {
	int *x, *y;
} POS;
typedef struct {
	int x, y;
} POS1;

typedef struct {
	POS1 pos;
} PLAYER;


typedef struct {
	int
		xDim,
		yDim,
		nZombies, 
		nHumans, 
		nZPlayers, 
		nHPlayers, 
		maxTurns,
		**pos;

} WORLD;

void showWorld(WORLD *world);
void updateWorld(WORLD* world,PLAYER* player);
void range(WORLD* w, PLAYER* p, int r, int v);

