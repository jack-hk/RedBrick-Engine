#include <iostream>
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_Mixer.h>
#include <SDL_TTF.h>

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "Failed to initialise SDL!";
	}

	SDL_Window* sdlWindow = SDL_CreateWindow("Hello Karyme", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, NULL);
	if (sdlWindow == nullptr)
	{
		std::cout << "Failed to create SDL window!";
	}

	getchar();

	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();

	return 0;
}