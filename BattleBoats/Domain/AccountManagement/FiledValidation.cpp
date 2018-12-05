#include <algorithm>

#include "FiledValidation.hpp"
#include "ConsoleLogger.hpp"
#include "FiledPersistance.hpp"

#include "WordAuthenticator.hpp"
#include "NumberAuthenticator.hpp"
#include "ConfigManager.hpp"



namespace Domain::AccountManagement
{

	FiledValidation::FiledValidation()
		: _persistentData(configManager->getPersistance()),
		_loggerPtr(configManager->getLogger()),
		_authenticator(configManager->getAuthenticator())
	{
		_logger << "FiledValidation initialized.";
	}


	// Destructor
	FiledValidation::~FiledValidation() 
	{
		_logger << "FiledValidation shutdown.";
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