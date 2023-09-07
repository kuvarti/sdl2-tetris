#include <iostream>
#include "game.hpp"
#include "pieceLib.hpp"

// int main(void)
// {
// 	std::string answer;
// 	std::cout << "Type 1 for Console Version" << std::endl
// 			  << "Type 2 for Graphics Verion (not teady yet)" << std::endl
// 			  << " Input: ";
// 	std::cin >> answer;
// 	while (1)
// 	{
// 		if (answer == "1")
// 		{
// 		}
// 		else if (answer == "2")
// 		{
// 		}
// 		else if (answer == "q")
// 			return 0;
// 	}
// }

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
	std::cout << "\nhere is rlPiece: " << std::endl;
	deneme(new rlPiece());
}