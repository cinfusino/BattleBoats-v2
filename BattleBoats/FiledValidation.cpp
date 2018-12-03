#include <algorithm>

#include "FiledValidation.hpp"
#include "ConsoleLogger.hpp"
#include "FiledPersistance.hpp"

#include "WordAuthenticator.hpp"
#include "NumberAuthenticator.hpp"



namespace Domain::AccountManagement
{
	FiledValidation::FiledValidation()
		: _persistentData(new TechnicalServices::Persistance::FiledPersistance),
		_loggerPtr(new TechnicalServices::Logging::ConsoleLogger),
		_authenticator(new Domain::AccountManagement::WordAuthenticator)
	{
		_logger << "FiledValidation being used and has been successfully initialized";
	}


	// Destructor
	FiledValidation::~FiledValidation() noexcept
	{
		_logger << "FiledValidation shutdown successfully";
	}



	// Operations
	bool FiledValidation::isValid(const UserCredentials & credentials)
	{
		
		UserCredentials credentialsFromDB = _persistentData->findCredentialsByName(credentials.userName);

	
		if ( credentials.userName == credentialsFromDB.userName
			&& credentials.userPassword == credentialsFromDB.userPassword
			&& std::any_of(credentialsFromDB.roles.cbegin(), credentialsFromDB.roles.cend(),
				[&](const std::string & role) { return credentials.roles.size() > 0 && credentials.roles[0] == role; }
			)
			&&_authenticator->Authenticate()
			) return true;


		return false;
	}

}