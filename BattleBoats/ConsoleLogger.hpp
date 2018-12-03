#ifndef TechnicalServices_Logging_ConsoleLogger_hpp
#define TechnicalServices_Logging_ConsoleLogger_hpp

#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>

#include "LoggerHandler.hpp"

namespace TechnicalServices::Logging
{
	class ConsoleLogger : public TechnicalServices::Logging::LoggerHandler
	{
	public:
		using LoggerHandler::LoggerHandler;
		ConsoleLogger() = default;

		ConsoleLogger & operator<< (const std::string & message);

		~ConsoleLogger();

	protected:

		std::vector<std::string> LoggerBuffer;




	};

	inline ConsoleLogger & ConsoleLogger::operator<< (const std::string & message)
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		std::stringstream ss;

		#pragma warning(suppress : 4996)
		ss << std::put_time(std::localtime(&now), "%Y-%m-%d %X");

		std::string logMessage = "";

		logMessage = ss.str() + "-------------" + message;


		LoggerBuffer.push_back(logMessage);

		return *this;
	}

	inline ConsoleLogger::~ConsoleLogger() {}



}



#endif // !TechnicalServices_Logging_Logger_hpp
