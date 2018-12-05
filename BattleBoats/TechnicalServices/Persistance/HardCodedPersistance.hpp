#ifndef TechnicalServices_Persistance_HardCodedPersistance_hpp
#define TechnicalServices_Persistance_HardCodedPersistance_hpp

#include <memory>

#include "PersistanceHandler.hpp"

namespace TechnicalServices::Persistance
{
	class HardCodedPersistance : public TechnicalServices::Persistance::PersistanceHandler
	{
		public:
			using PersistanceHandler::PersistanceHandler;

			HardCodedPersistance();

			std::vector<std::string> findRoles() override;

			void createNewUser(const UserCredentials credentials);

			UserCredentials findCredentialsByName(const std::string & name) override;

			~HardCodedPersistance() override;

	};


}



#endif