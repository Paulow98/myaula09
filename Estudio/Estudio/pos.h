#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct { double x, y; } POS;
POS *pos_new(double x, double y);
void pos_destroy(POS *p);
double pos_distance(POS *p1, POS *p2);
