#ifndef _LOGDATA_H
#define _LOGDATA_H

#ifndef _STRING_H
	#include "defines/string.h"
#endif 
#ifndef _LOGTYPE_H
	#include "log_type.h"
#endif 

struct LogData
{
    LogData(LogType log_type,const std::tstring& message) :current_log_type(log_type),log_message(message) {}

	LogType current_log_type;
	std::tstring log_message;
};

enum Colour
{
	BLACK,
	BLUE,
	GREEN, 
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGREY,
	DARKGREY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,
};


#endif // _LOGDATA_H
