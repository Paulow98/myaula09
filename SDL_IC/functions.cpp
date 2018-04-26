#include "functions.h"

WORLD*  setWorld(ini_t* config)
{
	srand(time(NULL));
	int nHPlayers, nZPlayers, nHumans, nZombies;
	int rX, rY;

	WORLD* world = (WORLD*)malloc(sizeof(WORLD));

	ini_sget(config, "world", "xDim", "%d", &world->xsize);
	ini_sget(config, "world", "yDim", "%d", &world->ysize);

	ini_sget(config, "general", "nHumans", "%d", &nHumans);
	ini_sget(config, "general", "nZombies", "%d", &nZombies);
	ini_sget(config, "general", "nHPlayers", "%d", &nHPlayers);
	ini_sget(config, "general", "nZPlayers", "%d", &nZPlayers);

	int nAgentsToPlace = nHumans + nZombies;
	world->agents = (AGENT*)calloc(nAgentsToPlace, sizeof(AGENT));
	world->agentsSize = nAgentsToPlace;

	int nagents = 1;

	world->grid = (AGENT**)malloc(world->xsize * sizeof(AGENT*));
	for (int i = 0; i < world->xsize; i++)
		world->grid[i] = (AGENT*)malloc(world->ysize * sizeof(AGENT));


	/* ******************************* */
	/* Populate the my_world variable. */
	/* ******************************* */

	for (int i = 0; i < world->xsize; ++i) {
		for (int j = 0; j < world->ysize; ++j) {

			/* Possible agent in grid. By default we assume there is none. */
			AGENT ag = { None, 0, 0,{ i,j } };

			do
			{
				ag = { None, 0, 0,{ i,j } };
				if (nHumans > 0)
				{
					rX = rand() % world->xsize;
					rY = rand() % world->ysize;
					if (world->grid[rX][rY].type != Zombie && world->grid[rX][rY].type != Human)
					{
						world->grid[rX][rY].type = Human;
						if (nHPlayers > 0)
						{
							world->grid[rX][rY].playable = 1;
							nHPlayers--;
						}
						else
							world->grid[rX][rY].playable = 0;
						nHumans--;
						nAgentsToPlace--;
						world->grid[rX][rY].id = nagents++;
						world->grid[rX][rY].pos = { rX,rY };
						world->agents[nagents - 2] = world->grid[rX][rY];
					}
				}
				else if (nZombies > 0)
				{
					rX = rand() % world->xsize;
					rY = rand() % world->ysize;
					if (world->grid[rX][rY].type != Zombie && world->grid[rX][rY].type != Human)
					{
						world->grid[rX][rY].type = Zombie;
						if (nZPlayers > 0)
						{
							world->grid[rX][rY].playable = 1;
							nZPlayers--;
						}
						else
							world->grid[rX][rY].playable = 0;
						nZombies--;
						nAgentsToPlace--;
						world->grid[rX][rY].id = nagents++;
						world->grid[rX][rY].pos = { rX,rY };
						world->agents[nagents - 2] = world->grid[rX][rY];
					}
				}
			} while (nAgentsToPlace > 0);
			/* Give 10% probablity of agent being playable by user. */


			/* Assign possible agent to grid at (i,j). */




		}
	}

	for (int i = 0; i < world->xsize; i++)
	{
		for (int j = 0; j < world->ysize; j++)
		{
			if (world->grid[i][j].type != Zombie && world->grid[i][j].type != Human)
				world->grid[i][j] = { None, 0, 0,{ i,j } };
		}
	}

	if (nHPlayers > 0 || nZPlayers > 0)
	{
		for (int i = 0; i < world->xsize; i++)
		{
			for (int j = 0; j < world->ysize; j++)
			{
				if (world->grid[i][j].type == Human && nHPlayers > 0)
				{
					world->grid[i][j].playable = 1;
					nHPlayers--;
				}
				else if (world->grid[i][j].type == Zombie && nZPlayers > 0) {
					world->grid[i][j].playable = 1;
					nZPlayers--;
				}
			}
		}
	}


	return world;
}

void move(AGENT p, WORLD * w, int dir)
{
	int x1=0,y1=0,x = 0, y = 0;
	for (int i = 0; i < w->xsize; i++) {
		for (int j = 0; j < w->ysize; j++)
		{
			if (w->grid[i][j].id == p.id ) {
				x = i;
				y = j;
				x1 = i;
				y1 = j;
			}
		}
	}
	if (w->grid[x][y].playable)
	{
		switch (dir)
		{
		case 1:
			if (x <= 0)
				x = w->xsize - 1;
			else
				x--;
			if (y >= w->ysize - 1)
				y = 0;
			else
				y++;
			break;
		case 2:
			if (y >= w->ysize - 1)
				y = 0;
			else
				y++;
			break;
		case 3:
			if (x >= w->xsize - 1)
				x = 0;
			else
				x++;
			if (y >= w->ysize - 1)
				y = 0;
			else
				y++;
			break;
		case 6:
			if (x >= w->xsize - 1)
				x = 0;
			else
				x++;
			break;
		case 9:
			if (x >= w->xsize - 1)
				x = 0;
			else
				x++;
			if (y <= 0)
				y = w->ysize - 1;
			else
				y--;
			break;
		case 8:
			if (y <= 0)
				y = w->ysize - 1;
			else
				y--;
			break;
		case 7:
			if (x <= 0)
				x = w->xsize - 1;
			else
				x--;
			if (y <= 0)
				y = w->ysize - 1;
			else
				y--;
			break;
		case 4:
			if (x <= 0)
				x = w->xsize - 1;
			else
				x--;
			break;
		default:
			break;
		}
		
		w->grid[x][y] = w->grid[x1][y1];
		w->grid[x][y].pos = { x,y };
		w->grid[x1][y1] = { None,0 ,0, {x1,y1} };
		updateAgents(w->grid[x][y], w);
	}
}

void move(AGENT p, int r, WORLD* w)
{

	int oldX = p.pos.x, oldY = p.pos.y;

	if (p.type == Zombie)
	{
		for (int i = 0; i < w->xsize; i++) {
			for (int j = 0; j < w->ysize; j++)
			{
				if(w->grid[i][j].type == Human && distance(p.pos, w->grid[i][j].pos) <= r && distance(p.pos, w->grid[i][j].pos) > 1)
				{ 
					
					if (p.pos.x < i)
						p.pos.x++;
					else if (p.pos.x > i)
						p.pos.x--;
					if (p.pos.y < j)
						p.pos.y++;
					else if (p.pos.y > j)
						p.pos.y--;
					w->grid[p.pos.x][p.pos.y] = w->grid[oldX][oldY];
					w->grid[p.pos.x][p.pos.y].pos = { p.pos.x,p.pos.y };
					w->grid[oldX][oldY] = { None,0 ,0,{oldX,oldY} };

				}
			}
		}
	}
	else if (p.type == Human)
	{
		for (int i = 0; i < w->xsize; i++) {
			for (int j = 0; j < w->ysize; j++)
			{
				if (w->grid[i][j].type == Zombie && distance(p.pos, w->grid[i][j].pos) <= r)
				{

					if (p.pos.x < i) 
					{
						if (p.pos.x <= 0)
							p.pos.x = w->xsize - 1;
						else
							p.pos.x--;
					}
					else if (p.pos.x > i) 
					{
						if (p.pos.x >= w->xsize - 1)
							p.pos.x = 0;
						else
						p.pos.x++;
					}
					if (p.pos.y < j)
					{
						if (p.pos.y <= 0)
							p.pos.y = w->ysize - 1;
						else
							p.pos.y--;
					}
					else if (p.pos.y > j)
					{
						if (p.pos.y >= w->ysize - 1)
							p.pos.y = 0;
						else
							p.pos.y++;
					}
					w->grid[p.pos.x][p.pos.y] = w->grid[oldX][oldY];
					w->grid[p.pos.x][p.pos.y].pos = { p.pos.x,p.pos.y };
					w->grid[oldX][oldY] = { None,0 ,0,{ oldX,oldY } };

				}
			}
		}
	}
}

void move(AGENT p, WORLD * w)
{
	int oldX = p.pos.x, oldY = p.pos.y;
	AGENT t = findCloser(p,w);
	if (p.type == Zombie)
	{		
		if (distance(p, w->grid[t.pos.x][t.pos.y]) <= worldDistance(p, w->grid[t.pos.x][t.pos.y], w->xsize, w->ysize))
			{
				if (p.pos.x < t.pos.x)
					p.pos.x++;
				else if (p.pos.x > t.pos.x)
					p.pos.x--;
				if (p.pos.y < t.pos.y)
					p.pos.y++;
				else if (p.pos.y > t.pos.y)
					p.pos.y--;
			}
		else
			{
				switch (inSection(p, w))
				{
				case 1:
					switch (inSection(w->grid[t.pos.x][t.pos.y], w))
					{
					case 2:
						if (p.pos.y < t.pos.y)
							p.pos.y++;
						else if (p.pos.y > t.pos.y)
							p.pos.y--;
						if (p.pos.x <= 0)
							p.pos.x = w->xsize - 1;
						p.pos.x--;
						break;
					case 3:
						if (p.pos.x <= 0)
							p.pos.x = w->xsize - 1;
						else
							p.pos.x--;
						if (p.pos.y <= 0)
							p.pos.y = w->ysize - 1;
						else
							p.pos.y--;
						break;
					case 4:
						if (p.pos.x < t.pos.x)
							p.pos.x++;
						else if (p.pos.x > t.pos.x)
							p.pos.x--;
						if (p.pos.y <= 0)
							p.pos.y = w->ysize - 1;
						else
							p.pos.y--;
						break;
					}
					break;
				case 2:
					switch (inSection(w->grid[t.pos.x][t.pos.y], w))
					{
					case 1:
						if (p.pos.y < t.pos.y)
							p.pos.y++;
						else if (p.pos.y > t.pos.y)
							p.pos.y--;
						if (p.pos.x >= w->xsize - 1)
							p.pos.x = 0;
						p.pos.x++;
						break;
					case 3:
						if (p.pos.x < t.pos.x)
							p.pos.x++;
						else if (p.pos.x > t.pos.x)
							p.pos.x--;
						if (p.pos.y <= 0)
							p.pos.y = w->ysize - 1;
						else
							p.pos.y--;
						break;
					case 4:
						if (p.pos.x >= w->xsize - 1)
							p.pos.x = 0;
						else
							p.pos.x++;
						if (p.pos.y <= 0)
							p.pos.y = w->ysize - 1;
						else
							p.pos.y--;
						break;
					}
					break;
				case 3:
					switch (inSection(w->grid[t.pos.x][t.pos.y], w))
					{
					case 1:
						if (p.pos.x >= w->xsize - 1)
							p.pos.x = 0;
						else
							p.pos.x++;
						if (p.pos.y >= w->ysize - 1)
							p.pos.y = 0;
						else
							p.pos.y++;
						break;
					case 2:
						if (p.pos.x < t.pos.x)
							p.pos.x++;
						else if (p.pos.x > t.pos.x)
							p.pos.x--;
						if (p.pos.y >= w->ysize - 1)
							p.pos.y = 0;
						else
							p.pos.y++;
						break;
					case 4:
						if (p.pos.y < t.pos.y)
							p.pos.y++;
						else if (p.pos.y > t.pos.y)
							p.pos.y--;
						if (p.pos.x >= w->xsize - 1)
							p.pos.x = 0;
						p.pos.x++;
						break;
					}
					break;
				case 4:
					switch (inSection(w->grid[t.pos.x][t.pos.y], w))
					{
					case 1:
						if (p.pos.x < t.pos.x)
							p.pos.x++;
						else if (p.pos.x > t.pos.x)
							p.pos.x--;
						if (p.pos.y >= w->ysize - 1)
							p.pos.y = 0;
						else
							p.pos.y++;
						break;
					case 2:
						if (p.pos.x <= 0)
							p.pos.x = w->xsize - 1;
						else
							p.pos.x--;
						if (p.pos.y >= w->ysize - 1)
							p.pos.y = 0;
						else
							p.pos.y++;
						break;
					case 3:
						if (p.pos.y < t.pos.y)
							p.pos.y++;
						else if (p.pos.y > t.pos.y)
							p.pos.y--;
						if (p.pos.x <= 0)
							p.pos.x = w->xsize - 1;
						p.pos.x--;
						break;
					}
					break;
				}
			}
		if (w->grid[p.pos.x][p.pos.y].type == None)
		{
			w->grid[p.pos.x][p.pos.y] = w->grid[oldX][oldY];
			w->grid[p.pos.x][p.pos.y].pos = { p.pos.x,p.pos.y };
			w->grid[oldX][oldY] = { None,0 ,0,{ oldX,oldY } };
			updateAgents(w->grid[p.pos.x][p.pos.y], w);
		}
	
		
	}
	else if (p.type == Human)
	{
		
		if (p.pos.x < t.pos.x)
		{
			if (p.pos.x <= 0)
				p.pos.x = w->xsize - 1;
			else
				p.pos.x--;
		}
		else if (p.pos.x > t.pos.x)
		{
			if (p.pos.x >= w->xsize - 1)
				p.pos.x = 0;
			else
				p.pos.x++;
		}
		if (p.pos.y < t.pos.y)
		{
			if (p.pos.y <= 0)
				p.pos.y = w->ysize - 1;
			else
				p.pos.y--;
		}
		else if (p.pos.y > t.pos.y)
		{
			if (p.pos.y >= w->ysize - 1)
				p.pos.y = 0;
			else
				p.pos.y++;
		}
		if (w->grid[p.pos.x][p.pos.y].type == None) 
		{
			w->grid[p.pos.x][p.pos.y] = w->grid[oldX][oldY];
			w->grid[p.pos.x][p.pos.y].pos = { p.pos.x,p.pos.y };
			w->grid[oldX][oldY] = { None,0 ,0,{ oldX,oldY } };
			updateAgents(w->grid[p.pos.x][p.pos.y], w);
		}

	}
	
}

int inSection(AGENT p, WORLD *w)
{
	if (p.pos.x < w->xsize / 2) {
		if (p.pos.y < w->ysize / 2)
			return 1;
		else
			return 4;
	}
	else
	{
		if (p.pos.y < w->ysize / 2)
			return 2;
		else
			return 3;
	}
	
}

AGENT findCloser(AGENT p1, WORLD * w)
{
	int dist = 999;
	AGENT t = { None,0,0,{0,0} };
	if (p1.type == Zombie)
	{
		for (int i = 0; i < w->agentsSize; i++)
		{
			if (w->agents[i].type == Human)
			{
				if (distance(p1, w->agents[i]) <= dist)
				{
					dist = distance(p1, w->agents[i]);
					t = w->agents[i];
				}
				else if (worldDistance(p1, w->agents[i], w->xsize, w->ysize) <= dist) {
					dist = worldDistance(p1, w->agents[i], w->xsize, w->ysize);
					t = w->agents[i];
				}
			}
		}
	}
	else if (p1.type == Human)
	{
		for (int i = 0; i < w->agentsSize; i++)
		{	
			if (w->agents[i].type == Zombie)
			{
				if (distance(p1, w->agents[i]) <= dist)
				{
					dist = distance(p1, w->agents[i]);
					t = w->agents[i];
				}
				else if (worldDistance(p1, w->agents[i], w->xsize, w->ysize) <= dist) {
					dist = worldDistance(p1, w->agents[i], w->xsize, w->ysize);
					t = w->agents[i];
				}
			}
		}
	}
	return t;
}

int worldDistance(POS p1, POS p2, int sizeX,int sizeY)
{
	int x1, x2, y1, y2;
	
	if (p1.x < (sizeX / 2))
	{
		x1 = -1;
		y1 = p1.y;
		x2 = sizeX;
		y2 = y1;

	}
	else
	{
		x1 = sizeX;
		y1 = p1.y;
		x2 = -1;
		y2 = y1;
	}
	POS temp = { x1,y1 }, temp2 = { x2,y2 };
	int disttmp = distance(p1, temp) + distance(temp2, p2);



	if (y1 < (sizeY / 2))
	{
		x1 = p1.x;
		y1 = 0;
		x2 = x1;
		y2 = sizeY;
	}
	else
	{
		x1 = p1.x;
		y1 = sizeY;
		x2 = x1;
		y2 = 0;
	}
	temp = { x1,y1 };
	temp2 = { x2,y2 };
	if (disttmp > (distance(p1, temp) + distance(temp2, p2)))
		return distance(p1, temp) + distance(temp2, p2);
	else
		return disttmp;
}

int worldDistance(AGENT p1, AGENT p2, int sizeX, int sizeY)
{
	int x1, x2, y1, y2;

	if (p1.pos.x < (sizeX / 2))
	{
		x1 = -1;
		y1 = p1.pos.y;
		x2 = sizeX;
		y2 = y1;

	}
	else
	{
		x1 = sizeX;
		y1 = p1.pos.y;
		x2 = -1;
		y2 = y1;
	}
	POS temp = { x1,y1 }, temp2 = { x2,y2 };
	int disttmp = distance(p1.pos, temp) + distance(temp2, p2.pos);



	if (p1.pos.y < (sizeY / 2))
	{
		x1 = p1.pos.x;
		y1 = 0;
		x2 = x1;
		y2 = sizeY;
	}
	else
	{
		x1 = p1.pos.x;
		y1 = sizeY;
		x2 = x1;
		y2 = 0;
	}
	temp = { x1,y1 };
	temp2 = { x2,y2 };
	if (disttmp > (distance(p1.pos, temp) + distance(temp2, p2.pos)))
		return distance(p1.pos, temp) + distance(temp2, p2.pos);
	else
		return disttmp;
	
}

int totalDistance(AGENT p1, AGENT p2, int sizeX, int sizeY)
{
	int tmp = distance(p1, p2);
	if (tmp > worldDistance(p1, p2, sizeX, sizeY))
		tmp = worldDistance(p1, p2, sizeX, sizeY);
	return tmp;
}

int distance(POS p1, POS p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int distance(AGENT p1, AGENT p2)
{
	return sqrt(pow(p2.pos.x - p1.pos.x, 2) + pow(p2.pos.y - p1.pos.y, 2));
}

void infect(AGENT p1, AGENT  p2, WORLD* w)
{
	if (distance(p1.pos, p2.pos) <= 1 || worldDistance(p1.pos, p2.pos, w->xsize, w->ysize) <= 1)
		w->grid[p2.pos.x][p2.pos.y].type = Zombie;
	updateAgents(w->grid[p2.pos.x][p2.pos.y], w);
	updateAgents(w->grid[p1.pos.x][p1.pos.y], w);
}

AGENT * setAgents(WORLD * w)
{
	int count = 0;
	for (int i = 0; i < w->xsize; i++)
	{
		for (int j = 0; j < w->ysize; j++) {
			if (w->grid[i][j].type != None)
				count++;
		}
				
	}
	AGENT* a = (AGENT*)malloc(sizeof(AGENT) * count);
	count = 0;
	for (int i = 0; i < w->xsize; i++)
	{
		for (int j = 0; j < w->ysize; j++) {
			if (w->grid[i][j].type != None)
				a[count++] = w->grid[i][j];
		}

	}

	return a;
}

void updateAgents(AGENT a, WORLD * w)
{
	for (int i = 0; i < w->agentsSize; i++)
	{
		if (a.id == w->agents[i].id)
		{
			w->agents[i] = a;
			i = w->agentsSize + 3;
		}
	}
}

void destroyWorld(WORLD * w)
{
	free(w);
}

void shuffle(AGENT *a, int n) { //implementation of Fisher
	int i, j;
	AGENT tmp;// create local variables to hold values for shuffle

	for (i = n - 1; i > 0; i--) { // for loop to shuffle
		j = rand() % (i + 1); //randomise j for shuffle with Fisher Yates
		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
	}
}