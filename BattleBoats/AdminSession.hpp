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
#include "Session.hpp"
#include "FiledPersistance.hpp"
#include "AuthenticatorHandler.hpp"

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
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler>			_loggerPtr;
		std::unique_ptr<Domain::AccountManagement::AuthenticatorHandler>	_authenticator;

		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
	};

	

	inline AdminSession::~AdminSession() {}

}
#endif // !Domain_BattleBoats_PlayerSession_hpp
