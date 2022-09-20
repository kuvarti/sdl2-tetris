#ifndef GAME_HPP
# define GAME_HPP

#include <SDL2/SDL.h>
#include "SDL2/SDL_events.h"
#include "Gamewindow.hpp"

class gameClass
{
public:
	bool		isRun;
	SDL_Event	event;
	gamewindow	*win;
private:
};

#endif
