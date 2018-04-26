#include "GameManager.h"
#include "showWorld.h"


void fillWorld(WORLD * w)
{
	for (int i = 0; i < w->xDim; i++)
	{
		for (int j = 0; j < w->yDim; j++)
		{
			w->pos[i][j] = 0;
		}

	}
	
}

void move(WORLD*  w, PLAYER* p, int dir)
{
	switch (dir)
	{
	case 4: // esquerda
		if (p->pos.x == 0)
			p->pos.x = w->xDim - 1;
		else
			p->pos.x--;
		break;
	case 2: // baixo
		if (p->pos.y == w->yDim - 1)
			p->pos.y = 0;
		else
			p->pos.y++;
		break;
	case 6: // direita
		if (p->pos.x == w->xDim -1)
			p->pos.x = 0;
		else
			p->pos.x++;
		break;
	case 8: // cima
		if (p->pos.y == 0)
			p->pos.y = w->yDim - 1;
		else
			p->pos.y--;
		break;

	}
}

int main()
{
	bool jogo = true;
	WORLD * world;
	world = (WORLD*)malloc(sizeof(WORLD));
	PLAYER * player;
	player = (PLAYER*)malloc(sizeof(PLAYER));
	player->pos.x = 10;
	player->pos.y = 10;
	setWorldRules(world);
	do {
		int dir;
		fillWorld(world);
		range(world, player, 2, 2);
		updateWorld(world, player);

		showWorld(world);
		printf("x: %d, y:%d\n", player->pos.x, player->pos.y);
		printf("Direcao: ");
		scanf("%d", &dir);
		move(world, player, dir);
	} while (jogo);
	return 0;
}