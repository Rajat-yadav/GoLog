#ifndef _LOGGER_H
#define _LOGGER_H

//Include Files
#ifndef _DLL_H
	#include "defines/dll.h"
#endif
#ifndef _STRING_H
	#include "defines\string.h"
#endif 
#ifndef _LOGTYPE_H
	#include "log_type.h"
#endif



class Logger
{
public:
	CALL Logger() {};
	CALL virtual ~Logger() {};
	CALL virtual bool Initialize() = 0;
	CALL virtual bool ShutDown() = 0;

	CALL virtual void Log(const std::tstring & log_code, const std::tstring & log_error_compenent, const std::tstring & log_scope_name, const std::tstring & log_message, LogType log_type, const std::tstring & log_file_name, int line_num) = 0;
	CALL virtual bool WriteLogsToFile(const std::tstring & file_name) = 0;
};

#endif // _LOGGER_H
