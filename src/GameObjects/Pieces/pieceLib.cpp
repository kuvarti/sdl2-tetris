#include "pieceLib.hpp"
#include <iostream>

tPiece::tPiece() : piece(pieceSize::threeXthree)
{
	char **emptymap = emptyPieceMap(pieceSize::threeXthree);
	emptymap[0][1] = '1';
	emptymap[1][0] = '1';
	emptymap[1][1] = '1';
	emptymap[1][2] = '1';
	setPieceMaping(emptymap);
}

zPiece::zPiece() : piece(pieceSize::threeXthree)
{
	char **zPieceMap = emptyPieceMap(pieceSize::threeXthree);
	zPieceMap[0][0] = '1';
	zPieceMap[0][1] = '1';
	zPieceMap[1][1] = '1';
	zPieceMap[1][2] = '1';
	setPieceMaping(zPieceMap);
}

rzPiece::rzPiece() : piece(pieceSize::threeXthree)
{
	char **emptymap = emptyPieceMap(pieceSize::threeXthree);
	emptymap[0][1] = '1';
	emptymap[0][2] = '1';
	emptymap[1][0] = '1';
	emptymap[1][1] = '1';
	setPieceMaping(emptymap);
}

lPiece::lPiece() : piece(pieceSize::threeXthree)
{
	char **emptymap = emptyPieceMap(pieceSize::threeXthree);
	emptymap[0][2] = '1';
	emptymap[1][0] = '1';
	emptymap[1][1] = '1';
	emptymap[1][2] = '1';
	setPieceMaping(emptymap);
}

rlPiece::rlPiece() : piece(pieceSize::threeXthree)
{
	char **emptymap = emptyPieceMap(pieceSize::threeXthree);
	emptymap[0][0] = '1';
	emptymap[1][0] = '1';
	emptymap[1][1] = '1';
	emptymap[1][2] = '1';
	setPieceMaping(emptymap);
}

iPiece::iPiece() : piece(pieceSize::fourXfour)
{
	char **emptymap = emptyPieceMap(pieceSize::fourXfour);
	emptymap[1][0] = '1';
	emptymap[1][1] = '1';
	emptymap[1][2] = '1';
	emptymap[1][3] = '1';
	setPieceMaping(emptymap);
}

sPiece::sPiece() : piece(pieceSize::fourXfour)
{
	char **emptymap = emptyPieceMap(pieceSize::fourXfour);
	emptymap[1][1] = '1';
	emptymap[1][2] = '1';
	emptymap[2][1] = '1';
	emptymap[2][2] = '1';
	setPieceMaping(emptymap);
}

piece *newRandomPiece(void)
{
	srand(time(NULL));
	int decide = rand() % 7;
	switch (decide)
	{
	case 0:
		return new tPiece();
	case 1:
		return new zPiece();
	case 2:
		return new rzPiece();
	case 3:
		return new lPiece();
	case 4:
		return new rlPiece();
	case 5:
		return new iPiece();
	case 6:
		return new sPiece();
	default:
		return nullptr;
	}
};