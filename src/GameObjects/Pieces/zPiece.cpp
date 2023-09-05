#include "zPiece.hpp"

zPiece::zPiece() : piece(pieceSize::threeXthree)
{
	char **zPieceMap = emptyPieceMap(pieceSize::threeXthree);
	zPieceMap[1][0] = 1;
	zPieceMap[1][1] = 1;
	zPieceMap[2][1] = 1;
	zPieceMap[2][2] = 1;
	setPieceMaping(zPieceMap);
}