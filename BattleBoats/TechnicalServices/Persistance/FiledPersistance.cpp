#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "FiledPersistance.hpp"


namespace TechnicalServices::Persistance
{
	FiledPersistance::FiledPersistance()
	{}

	FiledPersistance::~FiledPersistance()
	{}

	std::vector<std::string> FiledPersistance::findRoles()
	{
		return { "Admin", "Player" };
	}

	UserCredentials FiledPersistance::findCredentialsByName(const std::string & name)
	{

		
		UserCredentials currentUser;

		//read from file
		std::ifstream file("FiledUsers.txt");
		std::string line;

		while (std::getline(file, line))
		{
			if (line == name)
			{
				currentUser.userName = line;
				break;
			}
		}

		
		file >> currentUser.userPassword;

		std::size_t roleCount;

		if (file >> roleCount)
		{
			currentUser.roles.resize(roleCount);
			for (std::string& r : currentUser.roles) file >> r;

		}

		file.close();

		return currentUser;




	}

	void FiledPersistance::createNewUser(const UserCredentials credentials) 
	{
		//write to file

		std::ofstream file("FiledUsers.txt", std::ios::app);

		file << credentials.userName << '\n' << credentials.userPassword << '\n';

		file << credentials.roles.size() << '\n';
		
		for (std::string r : credentials.roles)
		{
			file << r << ' ';
		}
		file << "\n\n";

		file.close();




	}



}