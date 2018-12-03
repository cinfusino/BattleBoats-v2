#ifndef TechnicalServices_Persistance_FiledPersistance_hpp
#define TechnicalServices_Persistance_FiledPersistance_hpp

#include <memory>

#include "PersistanceHandler.hpp"

namespace TechnicalServices::Persistance
{
	class FiledPersistance : public TechnicalServices::Persistance::PersistanceHandler
	{
	public:
		using PersistanceHandler::PersistanceHandler;

		FiledPersistance();

		std::vector<std::string> findRoles() override;

		UserCredentials findCredentialsByName(const std::string & name) override;

		void createNewUser(const UserCredentials credentials) override;

		~FiledPersistance() override;

	};


}



#endif