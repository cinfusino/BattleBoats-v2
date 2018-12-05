#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

#include "ConsoleLogger.hpp"
#include "AdminSession.hpp"

#include "ConfigManager.hpp"


namespace Domain::BattleBoats
{
	 AdminSession::AdminSession()
		: _loggerPtr(configManager->getLogger()),
		 _authenticator(configManager->getAuthenticator())
	{
		_logger << "AdminSession Created.";
	}



	 std::vector<std::string> AdminSession::getCommands()
	{
		return { "Change Configuration", "View User Logs", "View Bug Reports", "Delete User", "Shut Down" };
	}

	 void AdminSession::launchCommand(const std::string & command)
	{

		if (command == "Change Configuration")
		{
			_logger << "Change Configuration selected.";
			

			_authenticator->Authenticate();

			//Display current settings.

			std::cout << "\nCurrent Settings:\n";
			std::ifstream configFile("ConfigFile.txt");
			if (configFile.is_open())
			{
				std::cout << "\n" << configFile.rdbuf();
			}
			configFile.close();

			std::vector<std::string> newConfig;
			std::string UISetting, LoggerSetting, PersistanceSetting, AuthenticatorSetting, ValidationSetting;
			
			std::cout << "\nEnter new UI Setting: ";
			std::cin >> UISetting;

			std::cout << "\nEnter new Logger Setting: ";
			std::cin >> LoggerSetting;

			std::cout << "\nEnter new Persistance Setting: ";
			std::cin >> PersistanceSetting;

			std::cout << "\nEnter new Authenticator Setting: ";
			std::cin >> AuthenticatorSetting;

			std::cout << "\nEnter new Validation Setting: ";
			std::cin >> ValidationSetting;

			newConfig.push_back(UISetting);
			newConfig.push_back(LoggerSetting);
			newConfig.push_back(PersistanceSetting);
			newConfig.push_back(AuthenticatorSetting);
			newConfig.push_back(ValidationSetting);


			//Replace old file...
			remove("FiledUser.txt");

			//...with new file.
			std::ofstream outputFile("ConfigFile.txt");
			std::ostream_iterator<std::string> output_iterator(outputFile, "\n");
			std::copy(newConfig.begin(), newConfig.end(), output_iterator);

			

		}
		if (command == "View User Logs")
		{
			_logger << "View User Logs selected.";
			std::ifstream logFile("SystemLogs.txt");
			if (logFile.is_open())
			{
				std::cout << logFile.rdbuf();
			}
		}
		if (command == "View Bug Reports")
		{
			_logger << "View Bug Reports selected.";
			std::ifstream reportFile("BugReports.txt");
			if (reportFile.is_open())
			{
				std::cout << reportFile.rdbuf();
			}
		}
		if (command == "Delete User")
		{
			_logger << "Delete User selected.";
			_authenticator->Authenticate();
			//Display available users to delete.
			std::ifstream userFile("FiledUsers.txt");
			if (userFile.is_open())
			{
				std::cout << userFile.rdbuf();
			}
			userFile.close();

			//Get user to delete
			std::string userToDelete;
			std::cout << "Enter name of user to delete:";
			std::cin >> userToDelete;

			//Store all file data into vector
			std::vector<std::string> fileLines;
			std::ifstream inputFile("FiledUsers.txt");

			for (std::string line; std::getline(inputFile, line);)
				fileLines.push_back(line);

			//Delete User from vector
			for (unsigned i = 0; i < fileLines.size(); i++)
			{
				if (fileLines[i] == userToDelete)
				{
					fileLines.erase(fileLines.begin() + i, fileLines.begin() + i + 4);
					break;
				}
			}

			inputFile.close();

			//Replace old file...
			remove("FiledUser.txt");

			//...with new file.
			std::ofstream outputFile("FiledUsers.txt");
			std::ostream_iterator<std::string> output_iterator(outputFile, "\n");
			std::copy(fileLines.begin(), fileLines.end(), output_iterator);


		}
	}
}