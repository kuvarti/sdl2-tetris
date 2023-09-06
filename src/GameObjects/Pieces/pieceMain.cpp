#include "piece.hpp"
#include <iostream>

piece::piece(pieceSize pSize)
{
	_ownPieceSize = pSize;
	_pieceMaping = emptyPieceMap(pSize);
}

void piece::rotateLeft(void)
{
	int max = _ownPieceSize == pieceSize::threeXthree ? 3 : 4;
	for (int i = 0; i < max / 2; i++)
	{
		for (int j = i; j < max - i - 1; j++)
		{
			int temp = _pieceMaping[i][j];
			_pieceMaping[i][j] = _pieceMaping[j][max - 1 - i];
			_pieceMaping[j][max - 1 - i] = _pieceMaping[max - 1 - i][max - 1 - j];
			_pieceMaping[max - 1 - i][max - 1 - j] = _pieceMaping[max - 1 - j][i];
			_pieceMaping[max - 1 - j][i] = temp;
		}
	}
	std::cout << "zPiece: Rotate left" << std::endl;
}

void piece::rotateRight(void)
{
	int max = _ownPieceSize == pieceSize::threeXthree ? 3 : 4;
	for (int i = 0; i < max / 2; i++)
	{
		for (int j = i; j < max - i - 1; j++)
		{
			int temp = _pieceMaping[i][j];
			_pieceMaping[i][j] = _pieceMaping[max - 1 - j][i];
			_pieceMaping[max - 1 - j][i] = _pieceMaping[max - 1 - i][max - 1 - j];
			_pieceMaping[max - 1 - i][max - 1 - j] = _pieceMaping[j][max - 1 - i];
			_pieceMaping[j][max - 1 - i] = temp;
		}
	}
	std::cout << "zPiece: Rotate right" << std::endl;
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
			std::cout << _pieceMaping[i][j];
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
	ret = new char *[max + 1];
	for (int i = 0; i < max; i++)
	{
		ret[i] = new char[max];
		for (int j = 0; j < max; j++)
			ret[i][j] = '0';
	}
	ret[max] = nullptr;
	return ret;
}
