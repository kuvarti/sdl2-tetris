#ifndef GAMEWINDOW_HPP
# define GAMEWINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class gamewindow
{
public:
	gamewindow();
	~gamewindow();

	SDL_Window *getwindow();

	int as();

private:
	SDL_Surface		*screenSurface;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
protected:
};


#endif
