#pragma once
#include <exception>

struct inCorrectMap : public std::exception
{
	const char *what() const throw() { return "Given Map is Incorrect"; };
};

enum pieceSize
{
	fourXfour,
	threeXthree
};

class piece
{
public:
	piece(pieceSize);
	~piece() { deletePieceMapping(); }

	void rotateLeft(void);
	void rotateRight(void);

	void printmap(void);

protected:
	int setPieceMaping(char **);

private:
	void deletePieceMapping(void);

	char **_pieceMaping;
	pieceSize _ownPieceSize;
};

char **emptyPieceMap(pieceSize);