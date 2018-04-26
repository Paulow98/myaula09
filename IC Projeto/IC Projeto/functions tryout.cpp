#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define sizeX 20
#define sizeY 20

typedef struct {
	int x, y, v;
	char* type;
}PLAYER;

void showWorld(int** w)
{
	system("cls");
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			printf(" %d ", w[i][j]);
		}
		printf("\n");
	}
}

int dist(PLAYER*p, int p1, int p2)
{
	return sqrt(pow(p[p2].x - p[p1].x, 2) + pow(p[p2].y - p[p1].y, 2));
}
int dist(PLAYER p1, PLAYER p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


void followNearest(PLAYER* pArray, PLAYER p1)
{
	PLAYER t = pArray[0];
	int disttmp = 100;
	for (int i = 0; i < sizeof(pArray) - 1; i++)
	{
		if (dist(p1,pArray[i]) < disttmp && pArray[i].type != "zombie") {
			t = pArray[i];
			disttmp = dist(p1, pArray[i]);
		}
	}
	if (p1.x < t.x)
	{
		p1.x++;
	}
	else if (p1.x > t.x)
	{
		p1.x--;
	}
	if (p1.y < t.y) {
		p1.y++;
	}
	if (p1.y > t.y)
	{
		p1.y--;
	}
	
}
void followNearest(PLAYER p1, PLAYER target)
{
	if (p1.x < target.x)
	{
		p1.x++;
	}
	else if (p1.x > target.x)
	{
		p1.x--;
	}
	if (p1.y < target.y) {
		p1.y++;
	}
	if (p1.y > target.y)
	{
		p1.y--;
	}

}



void updateWorld(PLAYER* p, int** w)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			w[i][j] = 0;
		}
	}
	for (int i = 0; i < sizeof(p) - 1; i++)
	{
		w[p[i].x][p[i].y] = p[i].v;
	}
	
}


int main()
{
	int **world = (int**)malloc(sizeX * sizeof(int));
	for (int i = 0; i < sizeX; i++) {
		world[i] = (int*)malloc(sizeY * sizeof(int));
	}
	PLAYER* p = (PLAYER*)malloc(sizeof(PLAYER) * 3);
	p[0] = { 1,1,1, "player" };
	p[1] = { 10,12,2, "zombie"};
	p[2] = { 16,15,3, "zombie" };
	
	for (;;) {
		updateWorld(p, world);
		showWorld(world);
		followNearest(p[1],p[0]);
	}
	printf("\n\n");
	int dist = 0;
	
	
	system("pause");
	return 0;
}

