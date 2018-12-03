#ifndef Domain_AccountManagement_ValidationHandler_hpp
#define Domain_AccountManagement_ValidationHandler_hpp

#include <string>

#include "PersistanceHandler.hpp"

namespace Domain::AccountManagement
{
	using TechnicalServices::Persistance::UserCredentials;

	struct ValidationHandler
	{

		ValidationHandler() = default;

		virtual bool isValid(const UserCredentials & credentials) = 0;

		virtual ~ValidationHandler() = 0;
	};


	inline ValidationHandler::~ValidationHandler() noexcept
	{}


} 


#endif // Domain_AccountManagement_ValidationHandler_hpp
