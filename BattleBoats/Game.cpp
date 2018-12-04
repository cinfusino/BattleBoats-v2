#include <memory>
#include <iostream>
#include <fstream>


#include "Game.hpp"
#include "Board.hpp"
#include "AIBoard.hpp"
#include "PlayerBoard.hpp"


namespace Domain::BattleBoats
{

	Game::Game() 
	{
		attackBoard->placeFleet();
		//attackBoard->printGrid();

		baseBoard->printGrid();
		baseBoard->placeFleet();
	}

	void Game::playGame()
	{
		

		while (!baseBoard->getDefeatFlag() && !attackBoard->getDefeatFlag())
		{
			attackBoard->printGrid();
			baseBoard->printGrid();
			attackBoard->performGuess();


			attackBoard->printGrid();
			baseBoard->printGrid();
			baseBoard->performGuess();
		}

		if (!baseBoard->getDefeatFlag())
		{
			std::cout << "\nYOU WON!";

		}
		else
		{
			std::cout << "\nYOU LOST!";

		}



	}

	void Game::putStats()
	{
		int missCount = attackBoard->getHealth();
		int hitCount = 17 - missCount;
		int hitsTaken = baseBoard->getHealth();
		int winCount = 0;
		if (!baseBoard->getDefeatFlag())
		{
			winCount++;
		}

		std::ofstream statFile("PlayerStats.txt", std::ios::app);
		if (statFile.is_open())
		{
			statFile << "Hits: " << hitCount << " Misses: " << missCount << " Wins: " << winCount << "\n\n";

		}


		statFile.close();




	}


	Game::~Game()
	{}

}