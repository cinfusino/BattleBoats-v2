#ifndef Domain_BattleBoats_PlayerSession_hpp
#define Domain_BattleBoats_PlayerSession_hpp

#include <memory>
#include <string>

#include "Session.hpp"
#include "Game.hpp"

namespace Domain::BattleBoats
{
	class PlayerSession : public Domain::BattleBoats::Session
	{
	public:
		using Session::Session;

		std::vector<std::string> getCommands() override;

		void launchCommand(const std::string & command) override;

		~PlayerSession() override;
	};


	inline std::vector<std::string> PlayerSession::getCommands()
	{
		return { "Play Game", "Edit Profile", "View Statistics", "View Game Information", "Submit Bug Report", "Shut Down" };
	}


	inline void PlayerSession::launchCommand(const std::string & command)
	{
		if (command == "Play Game")
		{
			std::cout << "\nPlaying Game...";
			//create a new game
			std::unique_ptr<Domain::BattleBoats::Game> playerGame(new Domain::BattleBoats::Game);
			playerGame->playGame();
		}
		if (command == "Edit Profile")
		{
			std::cout << "Edit Profile";
		}
		if (command == "View Statistics")
		{
			std::cout << "View Statistics";
		}
		if (command == "View Game Information")
		{
			std::cout << "\nVersion 0.0.1";
			std::cout << "\n\nGame Rules:";
			std::cout << "\n\nDeveloper Contact Information:\n\nJason Chandler : <>@csu.fullerton.edu\n\nJustin Chandler : <>@csu.fullerton.edu\n\nCarmine Infusino : c.infusino@csu.fullerton.edu";
		}
		if (command == "Submit Bug Report")
		{
			std::cout << "Submit Bug Report";
		}


	}


	inline PlayerSession::~PlayerSession() {}

}
#endif // !Domain_BattleBoats_PlayerSession_hpp
