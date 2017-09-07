#ifndef _ELOG_H
#define _ELOG_H

#include "logger\logger.h"

#ifndef _DLL_H
	#include "defines\dll.h"
#endif
#ifndef _STRING_H
	#include "defines\string.h"
#endif 
#ifndef _SETTINGS_H
	#include "settings.h"
#endif
#ifndef _LOGTYPE_H
	#include "log_type.h"
#endif 
#ifndef _LOGDATA_H
	#include "log_data.h"
#endif 
#ifndef _VECTOR_
	#include <vector>
#endif 


class ELog : public Logger
{
public:
    CALL ELog();
	CALL ~ELog();
	CALL bool Initialize();
	CALL bool ShutDown();

	CALL void Log(const std::tstring & log_code, const std::tstring & log_error_compenent, const std::tstring & log_scope_name, const std::tstring & log_message, LogType log_type, const std::tstring & log_file_name, int line_num);
	CALL bool WriteLogsToFile(const std::tstring & file_name);
private:
	std::vector<LogData> log_messages;
	Settings log_settings;
};

#endif
