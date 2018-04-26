#include "GameManager.h"

void setWorldRules(WORLD * world)
{
	ini_t *config = ini_load("config.ini");
	ini_sget(config, "world", "xDim", "%d", &world->xDim);
	ini_sget(config, "world", "yDim", "%d", &world->yDim);

	ini_sget(config, "general", "nHumans", "%d", &world->nHumans);
	ini_sget(config, "general", "nZombies", "%d", &world->nZombies);
	ini_sget(config, "general", "nHPlayers", "%d", &world->nHPlayers);
	ini_sget(config, "general", "nZPlayers", "%d", &world->nZPlayers);
	ini_sget(config, "general", "maxTurns", "%d", &world->maxTurns);

	world->pos = (int**)malloc(world->xDim * sizeof(int));
	for(int i = 0; i< world->yDim;i++) world->pos[i] = (int*)malloc(world->yDim * sizeof(int));

	ini_free(config);
}