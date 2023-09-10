#pragma once

#include <queue>
#include "pieceLib.hpp"
#include "Vector2.hpp"

class gameClass
{
public:
	gameClass(Vector2);
	~gameClass(){};

	void getPieceInfo();

private:
	char **_map;
	piece *_activePiece;
	std::queue<piece *> _nextPiece;
};
