#ifndef TechnicalServices_Persistance_PersistanceHandler_hpp
#define TechnicalServices_Persistance_PersistanceHandler_hpp

#include <string>
#include <vector>


namespace TechnicalServices::Persistance
{
	struct UserCredentials
	{
		std::string userName;
		std::string userPassword;
		std::vector<std::string> roles;
		UserCredentials() = default;
		UserCredentials(std::string n, std::string p, std::vector<std::string> r)
			:userName(n), userPassword(p), roles(r)
		{}
	};

	struct PersistanceHandler
	{
		PersistanceHandler() = default;

		virtual std::vector<std::string> findRoles() = 0;

		virtual UserCredentials findCredentialsByName(const std::string & name) = 0;

		virtual void createNewUser(const UserCredentials credentials) = 0;

		virtual ~PersistanceHandler() = 0;


	};

	inline PersistanceHandler::~PersistanceHandler() {}

}



#endif