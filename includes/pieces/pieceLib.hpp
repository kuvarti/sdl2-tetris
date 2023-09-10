#pragma once
#include "piece.hpp"

class tPiece : public piece
{
public:
	tPiece(); //* pieceSize::threeXthree
	~tPiece(){};
};

class zPiece : public piece
{
public:
	zPiece(); //* pieceSize::threeXthree
	~zPiece(){};
};

class rzPiece : public piece
{
public:
	rzPiece(); //* pieceSize::threeXthree
	~rzPiece(){};
};

class lPiece : public piece
{
public:
	lPiece(); //* pieceSize::threeXthree
	~lPiece(){};
};

class rlPiece : public piece
{
public:
	rlPiece(); //* pieceSize::threeXthree
	~rlPiece(){};
};

class iPiece : public piece
{
public:
	iPiece(); //* pieceSize::fourXfour
	~iPiece(){};
};

class sPiece : public piece
{
public:
	sPiece(); //* pieceSize::fourXfour
	~sPiece(){};
};

piece *newRandomPiece(void);