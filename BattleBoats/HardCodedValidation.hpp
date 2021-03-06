#ifndef Domain_AccountManagement_HardCodedValidation_hpp
#define Domain_AccountManagement_HardCodedValidation_hpp

#include <memory> 
#include <string>


#include "ValidationHandler.hpp"
#include "LoggerHandler.hpp"
#include "PersistanceHandler.hpp"
#include "AuthenticatorHandler.hpp"




namespace Domain::AccountManagement
{
	class HardCodedValidation : public Domain::AccountManagement::ValidationHandler
	{
	public:
		using ValidationHandler::ValidationHandler;  // inherit constructors
		HardCodedValidation();

		// Operations
		bool isValid(const UserCredentials & credentials) override;


		// Destructor
		~HardCodedValidation() override;


	private:
		
		std::unique_ptr<TechnicalServices::Persistance::PersistanceHandler>    _persistentData;
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler>             _loggerPtr;
		std::unique_ptr<Domain::AccountManagement::AuthenticatorHandler> _authenticator;


		TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;
	};
} 



#endif // Domain_AccountManagement_HardCodedValidation_hpp
