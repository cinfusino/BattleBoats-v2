#ifndef Domain_BattleBoats_PlayerSession_hpp
#define Domain_BattleBoats_PlayerSession_hpp

#include <memory>
#include <string>
#include <vector>

#include "LoggerHandler.hpp"
#include "ConsoleLogger.hpp"
#include "Session.hpp"
#include "Game.hpp"

namespace Domain::BattleBoats
{
	class PlayerSession : public Domain::BattleBoats::Session
	{
	public:
		using Session::Session;

		PlayerSession();
		std::vector<std::string> getCommands() override;

		void launchCommand(const std::string & command) override;

		~PlayerSession() override;
	private:
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
	};

	

	inline PlayerSession::~PlayerSession() {}

}
#endif // !Domain_BattleBoats_PlayerSession_hpp
