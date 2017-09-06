#ifndef _LOGGER_H
#define _LOGGER_H

//Include Files
#ifndef _DLL_H
	#include "defines/Dll.h"
#endif
#ifndef _STRING_H
	#include "defines\string.h"
#endif 
#ifndef _LOGTYPE_H
	#include "Logtype.h"
#endif

class Logger
{
public:
	CALL Logger() {};
	CALL virtual ~Logger() {};
	CALL virtual bool initialize() = 0;
	CALL virtual bool shutDown() = 0;

	CALL virtual void log(const std::tstring& logCode, const std::tstring& logErrorCompenent, const std::tstring& logScopeName, const std::tstring& logMessage, LogType logType, const std::tstring& logFileName, int lineNum) = 0;
	CALL virtual void log(const std::tstring& logErrorCompenent, const std::tstring& logScopeName, const std::tstring& logMessage, LogType logType, const std::tstring& logFileName, int lineNum) = 0;
	CALL virtual bool writeLogsToFile(const std::tstring& fileName) = 0;
};

#endif // _LOGGER_H
