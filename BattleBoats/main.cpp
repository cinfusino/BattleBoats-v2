#include <iostream>
#include <memory>




#include "UIHandler.hpp"
#include "ConsoleUI.hpp"
#include "ConfigManager.hpp"

std::unique_ptr<TechnicalServices::ConfigManager> configManager(new TechnicalServices::ConfigManager);;


int main()
{

	std::unique_ptr<UI::UIHandler> userInterface(configManager->getUI());
	
	userInterface->launch();


	std::cin.ignore(256, '\n');
	std::cin.get();
	return 0;
}