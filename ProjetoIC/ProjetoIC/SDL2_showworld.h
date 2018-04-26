#ifndef SDL2
#define SLD2
#include<SDL.h>
#include<stdio.h>
#include<SDL_image.h>
#undef main
//The window we'll be rendering to
SDL_Window* Window;
//The surface contained by the window
SDL_Surface* ScreenSurface;

//The image we will load and show on the screen
SDL_Surface* HelloWorld;
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

	

#endif
