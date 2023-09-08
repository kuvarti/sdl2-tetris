#include "game.hpp"

gameClass::gameClass(Vector2 mapSize = Vector2(20, 10))
{
	_map = new char *[mapSize.getX() + 1];
	for (int i = 0; i < mapSize.getX(); i++)
	{
		_map[i] = new char[mapSize.getY() + 1];
		for (int j = 0; j < mapSize.getY(); j++)
			_map[i][j] = '0';
		_map[i][mapSize.getY()] = NULL;
	}
	_map[mapSize.getX()] = nullptr;
}