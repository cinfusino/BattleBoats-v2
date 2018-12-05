#include <memory>
#include <iostream>

#include "Boat.hpp"
#include "Cell.hpp"
#include "Board.hpp"


namespace Domain::BattleBoats
{

	

	void Board::createGrid()
	{
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				Grid[r][c] = Cell(r, c);
			}
		}
	}



	Cell * Board::getCell(int r, int c)
	{
		return &Grid[r][c];
	}

	void Board::decrementHealth()
	{
		health--;
		//std::cout << "\n" << health << "\n";
		if (health == 0)
		{
			defeatFlag = true;
		}
	}

	bool Board::getDefeatFlag()
	{
		return defeatFlag;
	}

	int Board::getHealth()
	{
		return health;
	}
	

}