#include "piece.hpp"
#include <iostream>

piece::piece(pieceSize pSize)
{
	_ownPieceSize = pSize;
	_pieceMaping = emptyPieceMap(pSize);
}

int piece::setPieceMaping(char **newmap)
{
	if (_ownPieceSize == pieceSize::threeXthree && newmap[2] && !newmap[3])
	{
		for (int i = 0; i < 2; i++)
		{
			if (!newmap[i][2] || newmap[i][3])
				throw inCorrectMap();
		}
	}
	else if (_ownPieceSize == pieceSize::fourXfour && newmap[3] && !newmap[4])
	{
		for (int i = 0; i < 3; i++)
		{
			if (!newmap[i][3] || newmap[i][4])
				throw inCorrectMap();
		}
	}
	else
		throw inCorrectMap();
	deletePieceMapping();
	_pieceMaping = newmap;
	return 0;
}

void piece::deletePieceMapping(void)
{
	int max = _ownPieceSize == pieceSize::threeXthree ? 3 : 4;
	for (int i = 0; i < max; i++)
		delete[] _pieceMaping[i];
	delete[] _pieceMaping;
}

void piece::printmap(void)
{
	int max = _ownPieceSize == pieceSize::threeXthree ? 3 : 4;
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			if (_pieceMaping[i][j] == 0)
				std::cout << '0';
			else
				std::cout << '1';
		}
		std::cout << std::endl;
	}
}

char **emptyPieceMap(pieceSize type)
{
	int max;
	char **ret;
	if (type == pieceSize::threeXthree)
		max = 3;
	else
		max = 4;
	ret = new char *[max];
	for (int i = 0; i < max; i++)
	{
		ret[i] = new char[max];
		for (int j = 0; j < max; j++)
			ret[i][j] = 0;
	}
	return ret;
}
