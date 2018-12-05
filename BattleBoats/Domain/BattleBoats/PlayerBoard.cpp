#include <string>
#include <iostream>

#include "PlayerBoard.hpp"
#include "AircraftCarrierBoat.hpp"
#include "BattleshipBoat.hpp"
#include "CruiserBoat.hpp"
#include "SubmarineBoat.hpp"
#include "DestroyerBoat.hpp"


namespace Domain::BattleBoats 
{
	PlayerBoard::PlayerBoard()
	{
		createGrid();
		createFleet();
	}

	void PlayerBoard::createFleet()
	{

		Fleet[0] = std::make_unique<Domain::BattleBoats::DestroyerBoat>();
		Fleet[1] = std::make_unique<Domain::BattleBoats::CruiserBoat>();
		Fleet[2] = std::make_unique<Domain::BattleBoats::SubmarineBoat>();
		Fleet[3] = std::make_unique<Domain::BattleBoats::BattleshipBoat>();
		Fleet[4] = std::make_unique<Domain::BattleBoats::AircraftCarrierBoat>();

	}

	void PlayerBoard::printGrid()
	{
		std::cout << "\n\nYOUR BOARD\n";
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				std::cout << Grid[r][c].getSymbol() << " ";
			}
			std::cout << "\n";
		}
	}

	void PlayerBoard::placeBoat(std::shared_ptr<Domain::BattleBoats::Boat> boat)
	{
		int length = boat->getLength();
		for (int i = length; i > 0; i--)
		{
			std::cout << "\nEnter location coordinate (XY):";
			std::string submitCell;
			std::cin >> submitCell;
			//convert to char to int
			int chosenColumn = submitCell[0] - '0';
			int chosenRow = submitCell[1] - '0';
			bool valid = false;
			Cell * chosenCell = NULL;
			if ((chosenColumn < 10) && (chosenColumn >= 0))
			{
				if ((chosenRow < 10) && (chosenRow >= 0))
				{
					chosenCell = getCell(chosenRow, chosenColumn);

					valid = true;
					bool taken = chosenCell->getPresent();
					if (taken == true)
					{
						valid = false;
					}
				}
			}
			if (valid == false)
			{
				std::cout << "Cell is invalid, please try again";
				i++;
			}
			else
			{
				chosenCell->setPresent(true);
				chosenCell->setSymbol(boat->getSymbol());
				printGrid();
			}
		}
	}

	void PlayerBoard::placeFleet()
	{
		for (int i = 0; i < 5; i++)
		{
			placeBoat(Fleet[i]);
		}
	}

	void PlayerBoard::performGuess()
	{
		bool valid = false;
		while (valid == false)
		{

			int chosenColumn = rand() % 10;
			int chosenRow = rand() % 10;

			Cell * chosenCell = NULL;
			if ((chosenColumn < 10) && (chosenColumn >= 0))
			{
				if ((chosenRow < 10) && (chosenRow >= 0))
				{
					chosenCell = getCell(chosenRow, chosenColumn);

					valid = true;
					bool taken = chosenCell->getGuessed();
					if (taken == true)
					{
						valid = false;
					}
				}
			}
			if (valid == true)
			{
				chosenCell->setGuessed(true);
				if (chosenCell->getPresent())
				{
					//hit
					decrementHealth();
					chosenCell->setSymbol('X');
					std::cout << "\nAI Hit Coordinate: (" << chosenCell->getColumn() << ", " << chosenCell->getRow() << ")!";
				}
				else
				{
					//miss
					chosenCell->setSymbol('O');
				}

				//printGrid();
			}
		}
	}


}
