#include <iostream>
#include "game.hpp"

#include "zPiece.hpp"

// int main(void)
// {
// 	std::string answer;
// 	std::cout << "Type 1 for Console Version" << std::endl
// 			  << "Type 2 for Graphics Verion (not teady yet)" << std::endl
// 			  << " Input: ";
// 	std::cin >> answer;
// 	while (1)
// 	{
// 		if (answer == "1")
// 		{
// 		}
// 		else if (answer == "2")
// 		{
// 		}
// 		else if (answer == "q")
// 			return 0;
// 	}
// }

int main(void)
{
	piece *tmp;
	tmp = new zPiece();

	tmp->printmap();
	delete tmp;
	std::cin.get();
}

// gameClass game;
// game.win = new gamewindow();

// game.isRun = true;
// while (game.isRun)
// {
// 	while (SDL_PollEvent(&game.event) != 0)
// 	{
// 		if (game.event.type == SDL_QUIT)
// 			game.isRun = false;
// 	}
// 	SDL_UpdateWindowSurface(game.win->getwindow());
// }