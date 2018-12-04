#ifndef TechnicalServices_Logging_LoggerHandler_hpp
#define TechnicalServices_Logging_LoggerHandler_hpp


#include <iostream>
#include <string>

namespace TechnicalServices::Logging
{
	class LoggerHandler
	{
		public:

			LoggerHandler(std::ostream & loggingStream = std::clog);

			virtual LoggerHandler & operator<< (const std::string & message) = 0;
		
			virtual ~LoggerHandler() = 0;
		
		protected:

			std::ostream & _loggingStream;
	};

	inline LoggerHandler::LoggerHandler(std::ostream & loggingStream)
		: _loggingStream(loggingStream)
	{}

	inline LoggerHandler::~LoggerHandler(){}



}



#endif // !TechnicalServices_Logging_Logger_hpp
