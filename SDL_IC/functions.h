#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "showworld.h"
#include "ini.h"
#include <time.h>
/**
* Structure defining agent properties.
*
* @note This is an example which will probably not work in a fully functional
* game. Students should develop their own implementation of
* ::get_agent_info_at() and agent/world data structures.
* */
typedef struct {
	int x, y;
}POS;

typedef struct {
	AGENT_TYPE type;        /**< Agent type.        */
	unsigned char playable; /**< Is agent playable? */
	unsigned short id;      /**< Agent ID.          */
	POS pos;
} AGENT;

/**
* Structure defining world properties.
*
* @note This is an example which will probably not work in a fully functional
* game. Students should develop their own implementation of
* ::get_agent_info_at() and agent/world data structures.
* */
typedef struct {
	AGENT **grid;        /**< World is a grid composed of agents. */
	unsigned int xsize; /**< Horizontal world size.              */
	unsigned int ysize; /**< Vertical world size.                */
	AGENT* agents;
	int agentsSize;
} WORLD;

WORLD* setWorld(ini_t * config);

void move(AGENT p, WORLD* w, int dir);
void move(AGENT p, int r, WORLD* w);
void move(AGENT p, WORLD* w);

int inSection(AGENT p, WORLD *w);
AGENT findCloser(AGENT p1, WORLD *w);
int worldDistance(POS p1, POS p2, int sizeX, int sizeY);
int worldDistance(AGENT p1, AGENT p2, int sizeX, int sizeY);
int totalDistance(AGENT p1, AGENT p2, int sizeX, int sizeY);
int distance(POS p1, POS p2);
int distance(AGENT p1, AGENT p2);
void infect(AGENT p1, AGENT p, WORLD* w);
AGENT *setAgents(WORLD*w);
void updateAgents(AGENT a, WORLD* w);
void destroyWorld(WORLD* w);
void shuffle(AGENT * a, int n);
