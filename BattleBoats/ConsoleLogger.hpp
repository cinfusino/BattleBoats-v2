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
		ConsoleLogger(std::ostream & loggingStream = std::clog);

		ConsoleLogger & operator<< (const std::string & message) override;

		~ConsoleLogger() override;



	};

	inline ConsoleLogger::ConsoleLogger(std::ostream & loggingStream)
		:LoggerHandler(loggingStream)
	{
		loggingStream << std::unitbuf;

		*this << "Console Logger initialized";
	}

	inline ConsoleLogger & ConsoleLogger::operator<< (const std::string & message)
	{
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		#pragma warning(suppress : 4996)  // Turns off MSVC warning
		_loggingStream << '\n' << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << " | ";

		_loggingStream << message ;

		return *this;
	}

	inline ConsoleLogger::~ConsoleLogger() 
	{
		*this << "Console Logger shutdown.";
	}



}



#endif // !TechnicalServices_Logging_Logger_hpp
