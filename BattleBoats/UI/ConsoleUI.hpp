#ifndef UI_ConsoleUI_hpp
#define UI_ConsoleUI_hpp

#include <memory>

#include "UIHandler.hpp"
#include "PersistanceHandler.hpp"
#include "LoggerHandler.hpp"
#include "ValidationHandler.hpp"


namespace UI
{
	class ConsoleUI : public UI::UIHandler
	{
		public:
			using UIHandler::UIHandler;

			ConsoleUI();

			void launch() override;

			void createAccount();

			void createSession();

			~ConsoleUI();

		private:
			std::unique_ptr<TechnicalServices::Persistance::PersistanceHandler> _persistanceData;
			std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;
			std::unique_ptr<Domain::AccountManagement::ValidationHandler> _validator;
			

			TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;

	};
}




#endif // UI_ConsoleUI_hpp

