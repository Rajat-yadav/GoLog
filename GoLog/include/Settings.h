#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifndef _DLL_H
	#include "defines/Dll.h"
#endif 
#ifndef _STRING_H
	#include "defines/string.h"
#endif 
#ifndef _INIREADER_H
	#include "IniReader/IniReader.h"
#endif

class Settings
{
public:
	CALL Settings();
	CALL ~Settings();

	CALL bool initialize(const std::tstring& logClassName);
	CALL bool shutDown();

	CALL int getCriticalLogColour() const;
	CALL int getErrorLogColour() const ;
	CALL int getInfoLogColour() const;
	CALL int getTodoLogColour() const;
	CALL int getInvalidLogColour() const;
	CALL int getWarningLogColour() const;

	CALL int setIniPath(const std::tstring& iniPath);

	CALL std::tstring getRootPath();

	CALL std::tstring getErrorTypeTrigger() const;
	CALL std::tstring getCriticalTypeTrigger() const;
	CALL std::tstring getTodoTypeTrigger() const;
	CALL std::tstring getInvalidTypeTrigger() const;
	CALL std::tstring getWarningTypeTrigger() const;
	CALL std::tstring getInfoTypeTrigger() const;

	CALL std::tstring getSperatorSymbol() const;
private:
	CALL bool praseSettingsFile(const std::tstring& logClassName);

	int critical_log_colour;
	int error_log_colour;
	int info_log_colour;
	int todo_log_colour;
	int invalid_log_colour;
	int warning_log_colour;

	IniReader ini;

	std::tstring error_type_trigger;
	std::tstring critical_type_trigger;
	std::tstring info_type_trigger;
	std::tstring todo_type_trigger;
	std::tstring invalid_type_trigger;
	std::tstring warning_type_trigger;

	std::tstring sperator_symbol;

	std::tstring root_path;

};

#endif // _SETTINGS_H
