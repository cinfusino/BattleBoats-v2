#include <iostream>
#include <string>
#include <memory>

#include "ConsoleUI.hpp"
#include "HardCodedPersistance.hpp"
#include "FiledPersistance.hpp"
#include "Session.hpp"
#include "LoggerHandler.hpp"
#include "ConsoleLogger.hpp"
#include "FiledValidation.hpp"
#include "HardCodedValidation.hpp"

namespace UI
{
	ConsoleUI::ConsoleUI()
		:_persistanceData (new TechnicalServices::Persistance::FiledPersistance),
		_loggerPtr (new TechnicalServices::Logging::ConsoleLogger),
		_validator (new Domain::AccountManagement::FiledValidation)
	{
		_logger << "ConsoleUI Initialized";
	}

	ConsoleUI::~ConsoleUI()
	{
		_logger << "ConsoleUI Shutdown";
	}

	void ConsoleUI::launch()
	{
		_logger << "ConsoleUI Launched";

		std::cout << "\n1. Log in\n2. Create Account\n3. Shut down";
		std::cout << "\nPlease enter a command:";
		
		int selection;

		//NEEDS PROPER LOOP
		std::cin >> selection;
		if (selection == 1)
		{
			createSession();
		}
		else if (selection == 2)
		{
			createAccount();
		}
		else
		{
			std::cout << "\nEnding.";
		}
		


	}

	void ConsoleUI::createSession()
	{
		std::vector<std::string> validRoles = _persistanceData->findRoles();
		std::string selectedRole;

		do
		{
			std::string userName;
			std::cout << "\nUsername: ";
			std::cin >> userName;

			std::string userPassword;
			std::cout << "\nPassword: ";
			std::cin >> userPassword;

			//Testing read from file
			/*std::cout << "\nRIGHT HERE";
			TechnicalServices::Persistance::UserCredentials findUser = _persistanceData->findCredentialsByName(userName);

			std::cout << "\nUsername:" << findUser.userName << "\nPassword:" << findUser.userPassword << "\nRoles:";

			for (int i = 0; i < findUser.roles.size(); i++)
			{
				std::cout << "\n" << findUser.roles[i];
			}*/
			unsigned roleSelection;
			do
			{
				for (unsigned i = 0; i != validRoles.size(); i++)
				{
					std::cout << i << ". " << validRoles[i] << "\n";
				}
				std::cout << "\nSelect Role: ";
				std::cin >> roleSelection;
			} while (roleSelection >= validRoles.size());

			selectedRole = validRoles[roleSelection];

			if (_validator->isValid({ userName, userPassword, {selectedRole} }))
			{
				_logger << "Login Successful for [" + userName + "] as role [" + selectedRole + "].";
				break;
			}
			std::cout << "** Login failed\n";
			_logger << "Login failure for \"" + userName + "\" as role \"" + selectedRole + "\"";

		} while (true);

		std::unique_ptr <Domain::BattleBoats::Session> sessionControl = Domain::BattleBoats::Session::createSession(selectedRole);

		std::vector<std::string> commands = sessionControl->getCommands();

		std::string selectedCommand;
		unsigned commandSelection;

		do
		{
			for (unsigned i = 0; i != commands.size(); i++)
			{
				std::cout << "\n" << i << ". " << commands[i];
			}
			std::cout << "\nSelect Command: ";
			std::cin >> commandSelection;
		} while (commandSelection >= commands.size());

		selectedCommand = commands[commandSelection];

		sessionControl->launchCommand(selectedCommand);
		

	}

	void ConsoleUI::createAccount()
	{
		std::cout << "\nCREATE ACCOUNT";

		std::string userName;
		std::cout << "\nUsername: ";
		std::cin >> userName;

		std::string userPassword;
		std::cout << "\nPassword: ";
		std::cin >> userPassword;

		//New users can only be Players.
		TechnicalServices::Persistance::UserCredentials newUser(userName, userPassword, {"Player"});

		_persistanceData->createNewUser(newUser);

		

	}

}