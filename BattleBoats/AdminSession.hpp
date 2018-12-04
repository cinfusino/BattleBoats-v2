#ifndef Domain_BattleBoats_AdminSession_hpp
#define Domain_BattleBoats_AdminSession_hpp

#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

#include "LoggerHandler.hpp"
#include "ConsoleLogger.hpp"
#include "Session.hpp"
#include "FiledPersistance.hpp"

namespace Domain::BattleBoats
{
	class AdminSession : public Domain::BattleBoats::Session
	{
	public:
		using Session::Session;

		AdminSession();
		std::vector<std::string> getCommands() override;
		void launchCommand(const std::string & command) override;
		~AdminSession() override;

	private:
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
	};

	inline AdminSession::AdminSession()
	: _loggerPtr(new TechnicalServices::Logging::ConsoleLogger)
	{
		_logger << "PlayerSession Created.";
	}



	inline std::vector<std::string> AdminSession::getCommands()
	{
		return { "Change Configuration", "View User Logs", "View Bug Reports", "Delete User", "Shut Down" };
	}

	inline void AdminSession::launchCommand(const std::string & command)
	{
		
		if (command == "Change Configuration")
		{
			_logger << "Change Configuration selected.";
			
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
			for (int i = 0; i < fileLines.size(); i++)
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
			std::ostream_iterator<std::string> output_iterator(outputFile,"\n");
			std::copy(fileLines.begin(), fileLines.end(), output_iterator);


		}
	}

	inline AdminSession::~AdminSession() {}

}
#endif // !Domain_BattleBoats_PlayerSession_hpp
