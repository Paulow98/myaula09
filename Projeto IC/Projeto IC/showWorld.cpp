#include "showWorld.h"

void showWorld(WORLD * world)
{
	system("cls");
	printf("\n\n\n");
	for (int i = 0; i < world->xDim; i++)
	{
		for (int j = 0; j < world->yDim; j++)
		{
			//printf("\t");
			if (world->pos[i][j] == 1)
			{
				printf(" H ");
			}
			else if (world->pos[i][j] == 2)
			{
				printf(" h ");
			}
			else
			{
				printf(" . ");
			}
			
		}
		printf("\n\n");
	}

}

void updateWorld(WORLD* w,PLAYER *p)
{
	for (int i = -1; i < 1; i++)
	{
		for (int j = -1; j < 1; j++)
		{
			if (p->pos.y <= 1 && j < -1)  // limite cima
			{
				if (j != -1)
				{
					w->pos[p->pos.y + w->yDim + j][p->pos.x + i] = 2;
				}


				w->pos[p->pos.y + w->yDim - 1][p->pos.x + i] = 2;

			}
			else if (p->pos.y >= w->yDim - 1 && j >= 1) // limite baixo
			{
				if (j > 1)
				{
					w->pos[j - 1][p->pos.x + i] = 2;
				}
				w->pos[0][p->pos.x + i] = 2;
			}
			else if (p->pos.x <= 0 && i <= -1) //limite esquerda
			{
				w->pos[p->pos.y + j][p->pos.x + w->xDim - 1] = 2;
			}
			else if (p->pos.x >= w->xDim - 1 && i >= 1) // limite direita
			{
				w->pos[p->pos.y + j][0] = 2;
			}



		}

		w->pos[p->pos.y][p->pos.x] = 1;
		
	}
}

void range(WORLD * w, PLAYER * p, int r, int v)
{
	for (int i = (r * (-1)); i < r + 1; i++)
	{
		for (int j = (r * (-1)); j < r + 1; j++)
		{
			if (p->pos.y <= 1 && j < -1)  // limite cima
			{
				if (j != -1)
				{
					w->pos[p->pos.y + w->yDim + j][p->pos.x + i] = v;
				}
				

					w->pos[p->pos.y + w->yDim - 1][p->pos.x + i] = v;
				
			}
			else if (p->pos.y >= w->yDim - 1 && j >= 1) // limite baixo
			{
				if (j > 1)
				{
					w->pos[j - 1][p->pos.x + i] = v;
				}
				w->pos[0][p->pos.x + i] = v;
			}
			else if (p->pos.x <= 0 && i <= -1) //limite esquerda
			{
				w->pos[p->pos.y + j][p->pos.x + w->xDim - 1] = v;
			}
			else if (p->pos.x >= w->xDim - 1 && i >= 1) // limite direita
			{
				w->pos[p->pos.y + j][0] = v;
			}
			
				

		}
	}
}



