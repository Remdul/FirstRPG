#include "FirstRPG.h"
#include <SDL.h>			// Basic Game Library
#include <SDL_image.h>		// Importing images other than .bmp
#include <SDL_mixer.h>		// Wooo for audio in my game!
#include <stdio.h>			// Uhm.... I wanted printf... please don't kill me, Chief!
#include <string>
#include <iostream>

bool init(SDL_Window * window, SDL_Surface * windowSurface){
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL cannot initialize! SDL_Error: %s\n", SDL_GetError()); // <-- This be why! Mmmm printf.

	}
	else
	{
		window = SDL_CreateWindow("Ashes of the Phoenix", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created!!!! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			windowSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	return true;
}
void shutdown(SDL_Window * window, SDL_Surface * windowSurface)
{
	//Free loaded image
	SDL_FreeSurface(windowSurface);
	windowSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path, SDL_Surface * windowSurface)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, windowSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

int main(int argc, char *argv[])
{
	// SERIOUS QUESTION -- Can I pass a pointer by reference? I need to constantly touch these.
	// I know global is bad... Especially for these two items... but how can I main them, then
	// pass to functions to perform tasks with them? Globally, easy... within main, as a pointer,
	// I would have to pass by reference....

	SDL_Window	*window = NULL;			// Render Window
	SDL_Surface	*windowSurface = NULL;	// Render stuff on Window. Two buffers!

	init(window, windowSurface);
	windowSurface = loadSurface("images/loaded.png", windowSurface);
	shutdown(window, windowSurface);

	return 0;
}



