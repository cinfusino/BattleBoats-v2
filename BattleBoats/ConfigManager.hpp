#ifndef TechnicalServices_ConfigManager_hpp
#define TechnicalServices_ConfigManager_hpp

#include <string>
#include <memory>

#include "UIHandler.hpp"
#include "PersistanceHandler.hpp"
#include "LoggerHandler.hpp"
#include "AuthenticatorHandler.hpp"
#include "ValidationHandler.hpp"


namespace TechnicalServices
{
	class ConfigManager
	{
		

	public:
		ConfigManager();
		std::unique_ptr<UI::UIHandler> getUI();
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler> getLogger();
		std::unique_ptr<TechnicalServices::Persistance::PersistanceHandler> getPersistance();
		std::unique_ptr<Domain::AccountManagement::AuthenticatorHandler> getAuthenticator();
		std::unique_ptr<Domain::AccountManagement::ValidationHandler> getValidator();

		std::string ui;
		std::string logger;
		std::string persistance;
		std::string authenticator;
		std::string validator;

		~ConfigManager();


	};

	inline ConfigManager::~ConfigManager()
	{}
}

extern std::unique_ptr<TechnicalServices::ConfigManager> configManager;

#endif // !TechnicalServices_ConfigManager_hpp
