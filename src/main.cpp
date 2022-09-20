#include <iostream>
#include "game.hpp"

int	main(void)
{
	gameClass game;
	game.win = new gamewindow();

	game.isRun = true;
	while (game.isRun)
	{
		while (SDL_PollEvent(&game.event) != 0)
		{
			if (game.event.type == SDL_QUIT)
				game.isRun = false;
		}
		SDL_UpdateWindowSurface(game.win->getwindow());
	}
}
