#ifndef Domain_BattleBoats_AdminSession_hpp
#define Domain_BattleBoats_AdminSession_hpp

#include <memory>
#include <string>
#include <fstream>
#include "Session.hpp"

namespace Domain::BattleBoats
{
	class AdminSession : public Domain::BattleBoats::Session
	{
	public:
		using Session::Session;

		std::vector<std::string> getCommands() override;
		void launchCommand(const std::string & command) override;
		~AdminSession() override;
	};


	inline std::vector<std::string> AdminSession::getCommands()
	{
		return { "Change Configuration", "View User Logs", "View Bug Reports", "Delete User", "Shut Down" };
	}

	inline void AdminSession::launchCommand(const std::string & command)
	{
		
		if (command == "Change Configuration")
		{
			std::cout << "Change Configuration";
		}
		if (command == "View User Logs")
		{
			std::ifstream logFile("SystemLogs.txt");
			if (logFile.is_open())
			{
				std::cout << logFile.rdbuf();
			}
		}
		if (command == "View Bug Reports")
		{
			std::cout << "View Bug Reports";
		}
		if (command == "Delete User")
		{
			std::cout << "Delete User";
		}
	}

	inline AdminSession::~AdminSession() {}

}
#endif // !Domain_BattleBoats_PlayerSession_hpp
