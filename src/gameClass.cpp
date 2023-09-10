#include <iostream>
#include "game.hpp"

gameClass::gameClass(Vector2 mapSize = Vector2(20, 10))
{
	_map = new char *[mapSize.getX() + 1];
	for (int i = 0; i < mapSize.getX(); i++)
	{
		_map[i] = new char[mapSize.getY() + 1];
		for (int j = 0; j < mapSize.getY(); j++)
			_map[i][j] = '0';
		_map[i][mapSize.getY()] = 0;
	}
	_map[mapSize.getX()] = nullptr;
	for (size_t i = 0; i < 5; i++)
		_nextPiece.push(newRandomPiece());
	_activePiece = newRandomPiece();
}

void gameClass::getPieceInfo()
{
	piece *tmp = _nextPiece.front();
	tmp->printmap();
}
