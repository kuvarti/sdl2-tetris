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
			int temp = _pieceMaping[i][j].getValue();
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
			int temp = _pieceMaping[i][j].getValue();
			_pieceMaping[i][j] = _pieceMaping[max - 1 - j][i];
			_pieceMaping[max - 1 - j][i] = _pieceMaping[max - 1 - i][max - 1 - j];
			_pieceMaping[max - 1 - i][max - 1 - j] = _pieceMaping[j][max - 1 - i];
			_pieceMaping[j][max - 1 - i] = temp;
		}
	}
	std::cout << "zPiece: Rotate right" << std::endl;
}

int piece::setPieceMaping(piecePart **newmap)
{
	if (_ownPieceSize == pieceSize::threeXthree && newmap[2] && !newmap[3])
	{
		for (int i = 0; i < 2; i++)
		{
			if (!newmap[i][2].getValue() || newmap[i][3].getValue())
				throw inCorrectMap();
		}
	}
	else if (_ownPieceSize == pieceSize::fourXfour && newmap[3] && !newmap[4])
	{
		for (int i = 0; i < 3; i++)
		{
			if (!newmap[i][3].getValue() || newmap[i][4].getValue())
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
			std::cout << _pieceMaping[i][j].getValue();
		std::cout << std::endl;
	}
}

piecePart **emptyPieceMap(pieceSize type)
{
	int max;
	piecePart **ret;
	if (type == pieceSize::threeXthree)
		max = 3;
	else
		max = 4;
	ret = new piecePart *[max + 1];
	for (int i = 0; i < max; i++)
	{
		ret[i] = new piecePart[max + 1];
		for (int j = 0; j < max; j++)
			ret[i][j] = '0';
		ret[i][max] = 0;
	}
	ret[max] = nullptr;
	return ret;
}
