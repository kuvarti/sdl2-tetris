#include "Gamewindow.hpp"
#include <iostream>

gamewindow::gamewindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Window Initialization Error: " << SDL_GetError() << std::endl;
		exit(0);
	}
	else
	{
		window = SDL_CreateWindow("MyGamee", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
									1280, 720, 0);
		if (window == NULL)
		{
			std::cerr << "Window Creation Error : " << SDL_GetError() << std::endl;
			exit(0);
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			if (screenSurface == NULL)
			{
				std::cerr << "Error leading image : "<< SDL_GetError() << std::endl;
				exit(0);
			}
		}
	}
}

gamewindow::~gamewindow()
{
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
}

SDL_Window *gamewindow::getwindow()
{
	return (this->window);
}
