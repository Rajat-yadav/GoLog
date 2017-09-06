#ifndef _ELOG_H
#define _ELOG_H

#include "Logger\Logger.h"

#ifndef _DLL_H
	#include "defines\Dll.h"
#endif
#ifndef _STRING_H
	#include "defines\string.h"
#endif 
#ifndef _SETTINGS_H
	#include "Settings.h"
#endif
#ifndef _LOGTYPE_H
	#include "Logtype.h"
#endif 
#ifndef _LOGDATA_H
	#include "LogData.h"
#endif 
#ifndef _VECTOR_
#include <vector>
#endif 


class ELog : public Logger
{
public:
    CALL ELog();
	CALL ~ELog();
	CALL bool initialize();
	CALL bool shutDown();

	CALL void log(const std::tstring& logCode, const std::tstring& logErrorCompenent, const std::tstring& logScopeName, const std::tstring& logMessage, LogType logType, const std::tstring& logFileName, int lineNum);
	CALL void log(const std::tstring& logErrorCompenent, const std::tstring& logScopeName, const std::tstring& logMessage, LogType logType, const std::tstring& logFileName, int lineNum);
	CALL bool writeLogsToFile(const std::tstring& fileName);
private:
	std::vector<LogData> log_messages;
	Settings log_settings;
};

#endif
