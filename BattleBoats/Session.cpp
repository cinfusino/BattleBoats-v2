#include <memory>
#include <string>
#include <iostream>


#include "Session.hpp"
#include "PlayerSession.hpp"
#include "AdminSession.hpp"

namespace Domain::BattleBoats
{
	std::unique_ptr<Session> Session::createSession(const std::string & role)
	{
		
		if (role == "Player")
		{
			return std::make_unique<Domain::BattleBoats::PlayerSession>();
		}
		else if (role == "Admin")
		{
			return std::make_unique<Domain::BattleBoats::AdminSession>();
		}
		else
		{
			std::cout << "Error\n";
		}

	}


}

