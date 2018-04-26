
/**
* Function that creates and sets up all the initial values of the variables.
@note Uses the ini.h functions.
@param name of the config file.
@return a pointer to a world.

*/


/*
* This file is part of "2º Projeto de Introdução à Computação 2017/2018"
* (2oPIC1718).
*
* 2oPIC1718 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* 2oPIC1718 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with 2oPIC1718. If not, see <http://www.gnu.org/licenses/>.
* */

/**
* @file
* This file is an example of: a) how to use the API defined in the showworld.h
* header (mandatory for the project); and, b) how to use the concrete simple
* implementation of the API (provided in the simple_showworld.h and
* simple_showworld.c files).
*
* @author Nuno Fachada
* @date 2017
* @copyright [GNU General Public License version 3 (GPLv3)](http://www.gnu.org/licenses/gpl.html)
* */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simple_showworld.h"
#include "ini.h"
#include "showworld.h"
#include "functions.h"

/* This function is an implementation of the definition provided by the
* ::get_agent_info_at() function pointer. It only works for AGENT and WORLD
* example structures defined in this file. */
unsigned int example_get_ag_info(void *world, unsigned int x, unsigned int y);



/**
* This `main` function is only an example of: a) how to use the API defined in
* the showworld.h header (mandatory for the project); and, b) how to use the
* concrete simple implementation of the API (provided in the
* simple_showworld.h and simple_showworld.c files).
*
* @return Always zero.
* */
int main() {

	ini_t * config = ini_load("config.ini");
	/* An instance of a WORLD structure. */
	WORLD*  my_world = setWorld(config);
	

	int asdX, asdY,zX,zY;
	
	
	for (;;) {

		/*for (int i = 0; i < my_world->xsize; i++)
		{
			for (int j = 0; j < my_world->ysize; j++)
			{
				if (my_world->grid[i][j].type == Human)
				{
					asdX = i;
					asdY = j;
				}
				if (my_world->grid[i][j].type == Zombie)
				{
					zX = i;
					zY = j;
				}
			}
		}*/
		
		
		
		shuffle(my_world->agents, my_world->agentsSize);
		
		for (int i = 0; i < my_world->agentsSize; i++)
		{
			
			/*printf("Playing:%d\n", i);
			for (int j = 0; j < my_world->agentsSize; j++)
			{
				printf("Type:%d,Id: %d, isPlayable? %d, x:%d,y:%d, CloserId:%d\n"
					, my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y].type
					, my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y].id
					, my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y].playable
					, my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y].pos.x
					, my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y].pos.y
					, findCloser(my_world->grid[my_world->agents[j].pos.x][my_world->agents[j].pos.y], my_world).id);
			}*/
			/*int dir;
			scanf("%d", &dir);*/
			//system("pause");
			//system("cls");
			simple_show_world(my_world, my_world->xsize, my_world->ysize, example_get_ag_info);
			printf("Turn of the agent with ID:%d\nW", my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y].id);

			if (my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y].type == Zombie
				&& totalDistance(findCloser(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world)
					, my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world->xsize, my_world->ysize) <= 1 && my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y].playable == 0)
			{
				infect(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], findCloser(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world), my_world);
			}
			else if (my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y].playable)
			{
				int opt;
				if (my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y].type == Zombie)
				{
					printf("Want to infect or move?\n1)Infect\n2)Move\nChoice:");
					scanf("%d", &opt);
					switch (opt)
					{
					case 1:
						infect(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], findCloser(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world), my_world);
						break;
					case 2:
						printf("Move to wich direction?");
						scanf("%d", &opt);
						move(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world, opt);
						break;
					}
				}
				else
				{
					printf("Move to wich direction?");
					scanf("%d", &opt);
					move(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world, opt);
				}
				
				
			}else
			move(my_world->grid[my_world->agents[i].pos.x][my_world->agents[i].pos.y], my_world);
			system("cls");
			

		}
		
		
		/*for (int i = 0; i < my_world->xsize; i++)
		{
			for (int j = 0; j < my_world->ysize; j++)
			{
				
				printf("%d,%d:%2d   ", my_world->grid[i][j].pos.x, my_world->grid[i][j].pos.y, my_world->grid[i][j].id);
			}
			printf("\n");
		}*/
		//shuffle(my_world->agents, my_world->agentsSize);
		//printf("Hx:%d,Hy:%d, Type: %d\n", my_world->grid[asdX][asdY].pos.x, my_world->grid[asdX][asdY].pos.y, my_world->grid[asdX][asdY].type);
		//printf("Zx:%d,Zy:%d, Type: %d\n", my_world->grid[zX][zY].pos.x, my_world->grid[zX][zY].pos.y, my_world->grid[zX][zY].type);
		//printf("Local distance: %d \nWorld distance: %d\n", distance(my_world->grid[zX][zY].pos, my_world->grid[asdX][asdY].pos)
		//	, worldDistance(my_world->grid[zX][zY].pos, my_world->grid[asdX][asdY].pos, my_world->xsize, my_world->ysize));
		//printf("Section H:%d\nSection Z:%d\n", inSection(my_world->grid[asdX][asdY], my_world), inSection(my_world->grid[zX][zY], my_world));
		//printf("y in pos 0 agents:%d\n", my_world->agents[0].pos.y);
		//printf("size of array agents:%d\n", my_world->agentsSize);
		//int dir;
		////scanf("%d", &dir);
		////move(my_world->grid[asdX][asdY], 4, my_world);
		//move(my_world->grid[asdX][asdY], my_world);	
		//
		//move(my_world->grid[zX][zY], my_world);
		//infect(my_world->grid[zX][zY], my_world->grid[asdX][asdY], my_world);

		//
		
		
		
	
		//system("pause");
	}
	
	destroyWorld(my_world);
	ini_free(config);
	/* Bye. */
	return 0;
}

/**
* This function is an implementation of the ::get_agent_info_at() function
* definition. It only works for ::AGENT and ::WORLD structures defined in this
* example (in file example.h).
*
* It basically receives a pointer to a ::WORLD structure, obtains the AGENT
* structure in the given coordinates, and returns the agent information in a
* bit-packed `unsigned int`.
*
* @note This is an example which will probably not work in a fully functional
* game. Students should develop their own implementation of
* ::get_agent_info_at() and agent/world data structures.
*
* @param world Generic pointer to object representing the simulation world.
* @param x Horizontal coordinate of the simulation world from where to fetch
* the agent information.
* @param y Vertical coordinate of the simulation world from where to fetch
* the agent information.
* @return An integer containing bit-packed information about an agent, as
* follows: bits 0-1 (agent type), bit 2 (is agent playable), bits 3-18 (agent
* ID). Bits 19-31 are available for student-defined agent extensions.
* */
unsigned int example_get_ag_info(void *world, unsigned int x, unsigned int y) {

	/* The agent information to return. */
	unsigned int ag_info = 0;

	/* Convert generic pointer to world to a WORLD object. */
	WORLD *my_world = (WORLD *)world;

	/* Check if the given (x,y) coordinates are within bounds of the world. */
	if ((x >= my_world->xsize) || (y >= my_world->ysize)) {

		/* If we got here, then the coordinates are off bounds. As such we will
		report that the requested agent is of unknown type. No need to
		specify agent ID or playable status, since the agent is unknown. */
		ag_info = Unknown;

	}
	else {

		/* Given coordinates are within bounds, let's get and pack the request
		agent information. */

		/* Obtain agent at specified coordinates. */
		AGENT ag = my_world->grid[x][y];

		/* Is there an agent at (x,y)? */
		if (ag.type == None) {

			/* If there is no agent at the (x,y) coordinates, set agent type to
			None. No need to specify agent ID or playable status, since
			there is no agent here. */
			ag_info = None;

		}
		else {

			/* If we get here it's because there is an agent at (x,y). Bit-pack
			all the agent information as specified by the get_agent_info_at
			function pointer definition. */
			ag_info = (ag.id << 3) | (ag.playable << 2) | ag.type;

		}

	}

	/* Return the requested agent information. */
	return ag_info;
}