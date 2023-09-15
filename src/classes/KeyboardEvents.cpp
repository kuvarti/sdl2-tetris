#include "game.hpp"
#include "iostream"

int keyboardEvent::handleKeyDown(gameClass &gameclass, SDL_Event &event)
{
	if (PRESSED_KEY == SDLK_w || PRESSED_KEY == SDLK_UP)
		std::cout << "up / w" << std::endl; //* Piece/Menu Action
	if (PRESSED_KEY == SDLK_a || PRESSED_KEY == SDLK_LEFT)
		std::cout << "left / a" << std::endl; //* Piece/Menu Action
	if (PRESSED_KEY == SDLK_s || PRESSED_KEY == SDLK_DOWN)
		std::cout << "down / s" << std::endl; //* Piece/Menu Action
	if (PRESSED_KEY == SDLK_d || PRESSED_KEY == SDLK_RIGHT)
		std::cout << "right / d" << std::endl; //* Piece/Menu Action
	if (PRESSED_KEY == SDLK_RETURN || PRESSED_KEY == SDLK_SPACE)
		std::cout << "enter / space" << std::endl; //* Piece/Menu Action
	if (PRESSED_KEY == SDLK_ESCAPE)
		std::cout << "esc" << std::endl; //* Gamestate status
	return 0;
}
