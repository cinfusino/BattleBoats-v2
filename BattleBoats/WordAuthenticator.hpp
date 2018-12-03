#ifndef Domain_AccountManagement_WordAuthenticator_hpp
#define Domain_AccountManagement_WordAuthenticator_hpp

#include <string>
#include <iostream>
#include "AuthenticatorHandler.hpp"

namespace Domain::AccountManagement
{
	
	class WordAuthenticator : public Domain::AccountManagement::AuthenticatorHandler
	{
		public: 
			WordAuthenticator();

			bool Authenticate();

			~WordAuthenticator();
	};

	inline WordAuthenticator::WordAuthenticator()
	{}

	inline WordAuthenticator::~WordAuthenticator()
	{}

	inline bool WordAuthenticator::Authenticate()
	{
		std::cout << "\nPlease check your Authenticator and enter the code below.\nCode:";

		std::string key;
		std::cin >> key;

		if (key.find_first_of("01234566789") != std::string::npos)
		{
			std::cout << "\nInvalid code!";
			return false;
		}
		std::cout << "\nCode accepted!";
		return true;
	}
		

}


#endif // Domain_AccountManagement_WordAuthenticator_hpp
