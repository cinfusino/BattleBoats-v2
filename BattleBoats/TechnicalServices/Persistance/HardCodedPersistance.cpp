#include <string>
#include <vector>
#include <iostream>


#include "HardCodedPersistance.hpp"


namespace TechnicalServices::Persistance 
{
	HardCodedPersistance::HardCodedPersistance()
	{}

	HardCodedPersistance::~HardCodedPersistance()
	{}

	std::vector<std::string> HardCodedPersistance::findRoles()
	{
		return { "Admin", "Player" };
	}

	void HardCodedPersistance::createNewUser(const UserCredentials credentials)
	{
		std::cout << "\nThis Configuration cannot support any new users.";
	}

	UserCredentials HardCodedPersistance::findCredentialsByName(const std::string & name)
	{
		struct Users
		{
			std::string name;
			std::string password;
			std::vector<std::string> roles;
		};

		static std::vector<Users> storedUsers =
		{
			//name		password	roles
			{"Carmine", "123",	{"Player", "Admin"	}},
			{"Justin",	"456",{"Player"			}},
			{"Jason",	"789",{"Admin"			}},
		};

		for (const auto & user : storedUsers)
		{
			if (user.name == name)
			{
				return { user.name, user.password, user.roles };
			}
		}


		//Else invalid
		return { "","", {""}};




	}
}