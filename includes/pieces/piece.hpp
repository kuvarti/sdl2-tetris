#pragma once
#include <exception>
#include "Vector2.hpp"

struct inCorrectMap : public std::exception
{
	const char *what() const throw() { return "Given Map is Incorrect"; };
};

enum pieceSize
{
	fourXfour,
	threeXthree
};

class piecePart
{
public:
	piecePart() { _value = 0; };
	piecePart(char value) { _value = value; };
	~piecePart(){};

	piecePart operator=(const piecePart &p)
	{
		this->_value = p._value;
		return *this;
	};
	piecePart operator=(const char &p)
	{
		this->_value = p;
		return *this;
	};

	char getValue() const { return _value; };

private:
	void *img;
	char _value;
};

class piece
{
public:
	piece(pieceSize);
	~piece() { deletePieceMapping(); }

	void rotateLeft(void);
	void rotateRight(void);

	void printmap(void);

	Vector2 _loc;

protected:
	int setPieceMaping(piecePart **);

private:
	void deletePieceMapping(void);

	piecePart **_pieceMaping;
	pieceSize _ownPieceSize;
};

piecePart **emptyPieceMap(pieceSize);