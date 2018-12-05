#include <memory>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>

#include "LoggerHandler.hpp"
#include "ConsoleLogger.hpp"
#include "Session.hpp"
#include "Game.hpp"
#include "PlayerSession.hpp"

#include "ConfigManager.hpp"

namespace Domain::BattleBoats
{

	PlayerSession::PlayerSession()
		: _loggerPtr(configManager->getLogger())
	{
		_logger << "PlayerSession Created.";
	}


	std::vector<std::string> PlayerSession::getCommands()
	{
		return { "Play Game", "Edit Profile", "View Statistics", "View Game Information", "Submit Bug Report", "Shut Down" };
	}


	void PlayerSession::launchCommand(const std::string & command)
	{
		if (command == "Play Game")
		{
			_logger << "Play Game Selected";
			//create a new game
			std::unique_ptr<Domain::BattleBoats::Game> playerGame(new Domain::BattleBoats::Game);
			playerGame->playGame();
			playerGame->putStats();
		}
		if (command == "Edit Profile")
		{
			_logger << "Edit Profile Selected";
			std::cout << "Edit Profile";
		}
		if (command == "View Statistics")
		{
			_logger << "View Statistics Selected";
			std::ifstream logFile("PlayerStats.txt");
			if (logFile.is_open())
			{
				std::cout << logFile.rdbuf();
			}
		}
		if (command == "View Game Information")
		{
			_logger << "View Game Information Selected";
			std::cout << "\nVersion 0.0.1";
			std::cout << "\n\nGame Rules:";
			std::cout << "\n\nDeveloper Contact Information:\n\nJason Chandler : <>@csu.fullerton.edu\n\nJustin Chandler : <>@csu.fullerton.edu\n\nCarmine Infusino : c.infusino@csu.fullerton.edu";
		}
		if (command == "Submit Bug Report")
		{
			_logger << "Submit Bug Report Selected";
			std::string reportContents;

			std::cout << "\nSubmit Bug Report\nEnter your report below. Press ENTER to submit.\n";

			std::cin.ignore();

			std::ofstream reportFile("BugReports.txt", std::ios::app);

			std::getline(std::cin, reportContents);

			auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

			#pragma warning(suppress : 4996)  // Turns off MSVC warning
			reportFile << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << '\n' << reportContents << "\n\n";

			reportFile.close();

			std::cout << "\nReport Submitted.";
		}


	}
}