#include <iostream>
#include <memory>

#include "UIHandler.hpp"
#include "ConsoleUI.hpp"


int main()
{	
	std::cout << "\nStarting Main...";

	std::unique_ptr<UI::UIHandler> userInterface(new UI::ConsoleUI);
	
	userInterface->launch();


	std::cout << "\nShutting down...";
	std::cin.ignore(256, '\n');
	std::cin.get();
	return 0;
}