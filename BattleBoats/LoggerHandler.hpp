#ifndef TechnicalServices_Logging_LoggerHandler_hpp
#define TechnicalServices_Logging_LoggerHandler_hpp

#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>


namespace TechnicalServices::Logging
{
	class LoggerHandler
	{
		public:

			LoggerHandler() = default;

			virtual LoggerHandler & operator<< (const std::string & message) = 0;
		
			virtual ~LoggerHandler() = 0;
		
		protected:

			std::vector<std::string> LoggerBuffer;
	};

	

	inline LoggerHandler::~LoggerHandler(){}



}



#endif // !TechnicalServices_Logging_Logger_hpp
