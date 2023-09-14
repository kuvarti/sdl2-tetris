#include <iostream>
#include "game.hpp"

gameClass::gameClass(Vector2 mapSize)
{
	createGameMap(mapSize);
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 1000, SDL_WINDOW_OPENGL);
	_gameState = gameState::IDLE;
	gameLoop();
}

void gameClass::gameLoop(void)
{
	while (_gameState != gameState::EXIT)
	{
		inputHandler();
	}
}

void gameClass::inputHandler(void)
{
	if (SDL_PollEvent(&_event) == true)
	{
		switch (_event.type)
		{
			case SDL_QUIT:
				_gameState = gameState::EXIT;
				break;
		}
	}
}

void gameClass::createGameMap(Vector2 mapSize)
{
	_map = new piecePart *[mapSize.getX() + 1];
	for (int i = 0; i < mapSize.getX(); i++)
	{
		_map[i] = new piecePart[mapSize.getY() + 1];
		for (int j = 0; j < mapSize.getY(); j++)
			_map[i][j] = '0';
		_map[i][mapSize.getY()] = 0;
	}
	_map[mapSize.getX()] = nullptr;
	for (size_t i = 0; i < 5; i++)
		_nextPiece.push(newRandomPiece());
	_activePiece = newRandomPiece();
}
