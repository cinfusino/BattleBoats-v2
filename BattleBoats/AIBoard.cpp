#include <string>
#include <iostream>
#include <random>
#include <ctime>

#include "AIBoard.hpp"
#include "AircraftCarrierBoat.hpp"
#include "BattleshipBoat.hpp"
#include "CruiserBoat.hpp"
#include "SubmarineBoat.hpp"
#include "DestroyerBoat.hpp"



namespace Domain::BattleBoats 
{

	AIBoard::AIBoard()
	{
		createGrid();
		createFleet();
	}
	void AIBoard::createFleet()
	{
		/*Fleet[0] = std::make_shared<Domain::BattleBoats::DestroyerBoat>('#');
		Fleet[1] = std::make_shared<Domain::BattleBoats::CruiserBoat>('#');
		Fleet[2] = std::make_shared<Domain::BattleBoats::SubmarineBoat>('#');
		Fleet[3] = std::make_shared<Domain::BattleBoats::BattleshipBoat>('#');
		Fleet[4] = std::make_shared<Domain::BattleBoats::AircraftCarrierBoat>('#');*/
		Fleet[0] = std::make_shared<Domain::BattleBoats::DestroyerBoat>();
		Fleet[1] = std::make_shared<Domain::BattleBoats::CruiserBoat>();
		Fleet[2] = std::make_shared<Domain::BattleBoats::SubmarineBoat>();
		Fleet[3] = std::make_shared<Domain::BattleBoats::BattleshipBoat>();
		Fleet[4] = std::make_shared<Domain::BattleBoats::AircraftCarrierBoat>();

	}
	void AIBoard::printGrid()
	{
		std::cout << "\n\nATTACK BOARD \n";
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				/*cout << "[" << Grid[r][c].getRow() << ",";
				cout << Grid[r][c].getColumn() << "] = ";*/
				std::cout << Grid[r][c].getSymbol() << " ";
			}
			std::cout << "\n";
		}
	}

	void AIBoard::placeBoat(std::shared_ptr<Domain::BattleBoats::Boat> boat)
	{
		srand(time(NULL));
		int length = boat->getLength();
		for (int i = length; i > 0; i--)
		{

			int chosenColumn = rand() % 9;
			int chosenRow = rand() % 9;

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
				i++;
			}
			else
			{
				chosenCell->setPresent(true);
				chosenCell->setSymbol(boat->getSymbol());
			}
			
		}
	}

	void AIBoard::placeFleet()
	{
		for (int i = 0; i < 5; i++)
		{
			placeBoat(Fleet[i]);
		}
	}

	void AIBoard::performGuess()
	{
		bool valid = false;
		while (valid == false)
		{
			std::cout << "\nEnter missile coordinates (XY): ";
			std::string submitCell;
			std::cin >> submitCell;
			//convert to char to int
			int chosenColumn = submitCell[0] - '0';
			int chosenRow = submitCell[1] - '0';

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
			if (valid == false)
			{
				std::cout << "Cell is invalid, please try again";
			}
			else
			{
				chosenCell->setGuessed(true);
				if (chosenCell->getPresent())
				{
					//hit
					decrementHealth();
					chosenCell->setSymbol('X');
					std::cout << "\nYou Hit Coordinate: (" << chosenCell->getColumn() << ", " << chosenCell->getRow() << ")!";
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
