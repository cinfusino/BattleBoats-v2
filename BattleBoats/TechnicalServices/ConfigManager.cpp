#include "ConfigManager.hpp"
#include "UIHandler.hpp"
#include "ConsoleUI.hpp"
#include "ConsoleLogger.hpp"
#include "HardCodedPersistance.hpp"
#include "FiledPersistance.hpp"
#include "WordAuthenticator.hpp"
#include "NumberAuthenticator.hpp"
#include "FiledValidation.hpp"
#include "HardCodedValidation.hpp"
#include "ValidationHandler.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

namespace TechnicalServices
{

	ConfigManager::ConfigManager()
	{
		//open file
		std::vector<std::string> fileLines;
		std::ifstream configFile("ConfigFile.txt");

		for (std::string line; std::getline(configFile, line);)
			fileLines.push_back(line);
		
		configFile.close();


		ui = fileLines[0];
		logger = fileLines[1];
		persistance = fileLines[2];
		authenticator = fileLines[3];
		validator = fileLines[4];
	}

	std::unique_ptr<UI::UIHandler> ConfigManager::getUI()
	{
		if (ui == "ConsoleUI")
		{
			return std::make_unique<UI::ConsoleUI>();
		}
		return std::make_unique<UI::ConsoleUI>(); //default to ConsoleUI

	}


	std::unique_ptr<TechnicalServices::Logging::LoggerHandler> ConfigManager::getLogger()
	{
		if (logger == "ConsoleLogger")
		{
			return std::make_unique<TechnicalServices::Logging::ConsoleLogger>();
		}
		return std::make_unique<TechnicalServices::Logging::ConsoleLogger>(); //default to ConsoleLogger
	}


	std::unique_ptr<TechnicalServices::Persistance::PersistanceHandler> ConfigManager::getPersistance()
	{
		if (persistance == "FiledPersistance")
		{
			return std::make_unique<TechnicalServices::Persistance::FiledPersistance>();
		}
		else if (persistance == "HardCodedPersistance")
		{
			return std::make_unique<TechnicalServices::Persistance::HardCodedPersistance>();
		}
		return std::make_unique<TechnicalServices::Persistance::FiledPersistance>(); //default to FiledPersistance
	}


	std::unique_ptr<Domain::AccountManagement::AuthenticatorHandler> ConfigManager::getAuthenticator()
	{
		if (authenticator == "NumberAuthenticator")
		{
			return std::make_unique<Domain::AccountManagement::NumberAuthenticator>();
		}
		else if (authenticator == "WordAuthenticator")
		{
			return std::make_unique<Domain::AccountManagement::WordAuthenticator>();
		}
		return std::make_unique<Domain::AccountManagement::NumberAuthenticator>(); //default to NumberAuthenticator
	}


	std::unique_ptr<Domain::AccountManagement::ValidationHandler> ConfigManager::getValidator()
	{
		if (validator == "FiledValidaton")
		{
			return std::make_unique<Domain::AccountManagement::FiledValidation>();
		}
		else if (validator == "HardCodedValidation")
		{
			return std::make_unique<Domain::AccountManagement::HardCodedValidation>();
		}
		return std::make_unique<Domain::AccountManagement::FiledValidation>(); // default to FildValidation
	}

	

}

