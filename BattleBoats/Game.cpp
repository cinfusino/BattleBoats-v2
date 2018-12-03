#include <memory>
#include <iostream>

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

	Game::~Game()
	{
		delete baseBoard;
		delete attackBoard;
	}

}