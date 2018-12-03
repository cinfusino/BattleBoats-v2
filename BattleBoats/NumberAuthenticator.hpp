#ifndef Domain_AccountManagement_NumberAuthenticator_hpp
#define Domain_AccountManagement_NumberAuthenticator_hpp

#include <string>
#include <iostream>
#include "AuthenticatorHandler.hpp"

namespace Domain::AccountManagement
{

	class NumberAuthenticator : public Domain::AccountManagement::AuthenticatorHandler
	{
	public:
		NumberAuthenticator();

		bool Authenticate();

		~NumberAuthenticator();
	};

	inline NumberAuthenticator::NumberAuthenticator()
	{}

	inline NumberAuthenticator::~NumberAuthenticator()
	{}

	inline bool NumberAuthenticator::Authenticate()
	{
		std::cout << "\nPlease check your Authenticator and enter the code below.\nCode:";

		int key;
		std::cin >> key;

		if (!std::cin)
		{
			std::cout << "\nInvalid code!";
			return false;
		}

		std::cout << "\nCode accepted!";
		return true;
	}


}


#endif // Domain_AccountManagement_NumberAuthenticator_hpp
