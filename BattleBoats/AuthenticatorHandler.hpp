#ifndef Domain_AccountManagement_AuthenticatorHandler_hpp
#define Domain_AccountManagement_AuthenticatorHandler_hpp

#include <string>


namespace Domain::AccountManagement
{
	
	struct AuthenticatorHandler
	{
		
		AuthenticatorHandler() = default;

		virtual bool Authenticate() = 0;

		virtual ~AuthenticatorHandler() = 0;
	};


	inline AuthenticatorHandler::~AuthenticatorHandler()
	{}


}


#endif // Domain_AccountManagement_AuthenticatorHandler_hpp
