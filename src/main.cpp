#include <iostream>
#include "game.hpp"
#include "pieceLib.hpp"

void deneme(piece *tmp)
{
	tmp->printmap();
	for (int i = 0; i < 3; i++)
	{
		tmp->rotateRight();
		tmp->printmap();
	}
	delete tmp;
}

int main(void)
{
	gameClass game(Vector2(20, 10));

}
