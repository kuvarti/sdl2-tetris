#pragma once

#include <queue>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "pieceLib.hpp"
#include "Vector2.hpp"

enum class gameState
{
	IDLE,
	PLAYING,
	PAUSED,
	EXIT
};

//todo make keyboardeventclass

class gameClass
{
public:
	gameClass(Vector2);
	~gameClass(){}; // TODO: free all allocated area which is _map

	void gameLoop(void);

private: // Functions
	void createGameMap(Vector2);
	void inputHandler(void);

private: // Variables
	piece *_activePiece;
	piecePart **_map;
	std::queue<piece *> _nextPiece;

	SDL_Window *_window;
	gameState _gameState;
};
