#include "pos.h"
#include <math.h>
POS * pos_new(double x, double y)
{
	POS* newPos = (POS*)calloc(1, sizeof(POS));
	newPos->x = x;
	newPos->y = y;
	return newPos;
}

void pos_destroy(POS * p)
{
	free(p);
}

double pos_distance(POS * p1, POS * p2)
{
	
	return sqrt(pow(p2->x - p1->x , 2) + pow(p2->y - p1->y,2));
}
