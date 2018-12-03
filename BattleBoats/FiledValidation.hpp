#ifndef Domain_AccountManagement_FiledValidation_hpp
#define Domain_AccountManagement_FiledValidation_hpp

#include <memory> 
#include <string>


#include "ValidationHandler.hpp"
#include "LoggerHandler.hpp"
#include "PersistanceHandler.hpp"
#include "AuthenticatorHandler.hpp"


namespace Domain::AccountManagement
{
	class FiledValidation : public Domain::AccountManagement::ValidationHandler
	{
	public:
		using ValidationHandler::ValidationHandler;  // inherit constructors
		FiledValidation();

		// Operations
		bool isValid(const UserCredentials & credentials) override;


		// Destructor
		~FiledValidation() noexcept override;


	private:

		std::unique_ptr<TechnicalServices::Persistance::PersistanceHandler>    _persistentData;
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;
		std::unique_ptr<Domain::AccountManagement::AuthenticatorHandler>       _authenticator;

		TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
	};
}



#endif // Domain_AccountManagement_FiledValidation_hpp
