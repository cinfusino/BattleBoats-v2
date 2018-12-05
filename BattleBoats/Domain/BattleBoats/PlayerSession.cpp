#include <memory>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <iterator>

#include "LoggerHandler.hpp"
#include "ConsoleLogger.hpp"
#include "Session.hpp"
#include "Game.hpp"
#include "PlayerSession.hpp"
#include "ConfigManager.hpp"

namespace Domain::BattleBoats
{

	PlayerSession::PlayerSession()
		: _loggerPtr(configManager->getLogger()),
		_persistanceData(configManager->getPersistance()),
		_authenticator(configManager->getAuthenticator())
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
			
			_authenticator->Authenticate();
			//Get user to delete
			std::string userName;
			std::cout << "\nPlease Re-Enter Username:";
			std::cin >> userName;

			std::string userPassword;
			std::cout << "\Enter new Password: ";
			std::cin >> userPassword;


			//Store all file data into vector
			std::vector<std::string> fileLines;
			std::ifstream inputFile("FiledUsers.txt");

			for (std::string line; std::getline(inputFile, line);)
				fileLines.push_back(line);

			//Delete User from vector
			for (unsigned i = 0; i < fileLines.size(); i++)
			{
				if (fileLines[i] == userName)
				{
					fileLines.erase(fileLines.begin() + i, fileLines.begin() + i + 4);
					break;
				}
			}

			inputFile.close();


			//Replace old file...
			remove("FiledUsers.txt");

			//...with new file.
			std::ofstream outputFile("FiledUsers.txt");
			std::ostream_iterator<std::string> output_iterator(outputFile, "\n");
			std::copy(fileLines.begin(), fileLines.end(), output_iterator);

			outputFile << "\n";
			outputFile.close();


			TechnicalServices::Persistance::UserCredentials newUser(userName, userPassword, { "Player" });
			_persistanceData->createNewUser(newUser);


		}
		if (command == "View Statistics")
		{
			_logger << "View Statistics Selected";
			std::ifstream logFile("PlayerStats.txt");
			if (logFile.is_open())
			{
				std::cout << "\n" << logFile.rdbuf();
			}
		}
		if (command == "View Game Information")
		{
			_logger << "View Game Information Selected";
			std::cout << "\nVersion 0.0.1";
			std::cout << "\n\nBattle Boats:\n A naval themed guessing game played against AI. "
				<< "\nThe player is first shown a grid on which they must arrange all of their available boats. "
				<< "\nOnce placed, the guessing phase begins." 
				<< "\nOn alternating turns, the player or AI will guess where the boats have been placed on the opposing grid."
				<< "\nFor every space containing a boat correctly guessed, the owner of the boat loses a health point. "
				<< "\nThe game is over when either the player or the AI has 0 remaining health points. "
				<<"\nThe first to reduce their opponent to 0 health points wins the game.";
			std::cout << "\n\nDeveloper Contact Information:\n\nJason Chandler : jason_chandler@csu.fullerton.edu\n\nJustin Chandler : justin_chandler@csu.fullerton.edu\n\nCarmine Infusino : c.infusino@csu.fullerton.edu";
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