#include <SDL.h>			// Basic Game Library
#include <SDL_image.h>		// Importing images other than .bmp
#include <SDL_mixer.h>		// Wooo for audio in my game!
#include <stdio.h>			// Uhm.... I wanted printf... please don't kill me, Chief!
#include <string>
#include <iostream>

// Ewww... globals! Please note message above!
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// PROTOTYPES
SDL_Surface* loadSurface(std::string path);
