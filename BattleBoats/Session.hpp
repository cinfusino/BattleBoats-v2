#ifndef Domain_BattleBoats_Session_hpp
#define Domain_BattleBoats_Session_hpp


#include <memory>
#include <string>
#include <vector>

namespace Domain::BattleBoats
{
	struct Session 
	{

		Session() = default;

		virtual std::vector<std::string> getCommands() = 0;

		static std::unique_ptr<Session> createSession(const std::string & role);

		virtual void launchCommand(const std::string & command) = 0;

		virtual ~Session() = 0;
	};


	inline Session::~Session() {}


}


#endif // !Domain_BattleBoats_Session_hpp