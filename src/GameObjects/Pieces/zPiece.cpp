#include "zPiece.hpp"

zPiece::zPiece() : piece(pieceSize::threeXthree)
{
	char **zPieceMap = emptyPieceMap(pieceSize::threeXthree);
	zPieceMap[0][0] = '1';
	zPieceMap[0][1] = '1';
	zPieceMap[1][1] = '1';
	zPieceMap[1][2] = '1';
	setPieceMaping(zPieceMap);
}