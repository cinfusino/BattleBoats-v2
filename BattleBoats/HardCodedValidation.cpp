#include <algorithm>

#include "HardCodedValidation.hpp"
#include "ConsoleLogger.hpp"
#include "HardCodedPersistance.hpp"

#include "WordAuthenticator.hpp"
#include "NumberAuthenticator.hpp"


namespace Domain::AccountManagement
{
	HardCodedValidation::HardCodedValidation()
		: _persistentData(new TechnicalServices::Persistance::HardCodedPersistance),   
		_loggerPtr(new TechnicalServices::Logging::ConsoleLogger),
		_authenticator(new Domain::AccountManagement::WordAuthenticator)
	{
		_logger << "HardCodedValidation being used and has been successfully initialized";
	}

	HardCodedValidation::~HardCodedValidation() 
	{
		_logger << "HardCodedValidation shutdown successfully";
	}


	bool HardCodedValidation::isValid(const UserCredentials & credentials)
	{
		
			UserCredentials credentialsFromDB = _persistentData->findCredentialsByName(credentials.userName);

			if (credentials.userName == credentialsFromDB.userName
				&& credentials.userPassword == credentialsFromDB.userPassword
				&& std::any_of(credentialsFromDB.roles.cbegin(), credentialsFromDB.roles.cend(),
					[&](const std::string & role) { return credentials.roles.size() > 0 && credentials.roles[0] == role; }
				)
				&& _authenticator->Authenticate()
				) return true;


		return false;
	}

}