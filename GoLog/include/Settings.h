#ifndef _SETTINGS_H
#define _SETTINGS_H

#ifndef _DLL_H
	#include "defines/dll.h"
#endif 
#ifndef _STRING_H
	#include "defines/string.h"
#endif 
#ifndef _INIREADER_H
	#include "ini_reader/ini_reader.h"
#endif

class Settings
{
public:
	CALL Settings();
	CALL ~Settings();

	CALL bool Initialize(const std::tstring & log_class_name);
	CALL bool ShutDown();

	CALL int GetCriticalLogColour() const;
	CALL int GetErrorLogColour() const ;
	CALL int GetInfoLogColour() const;
	CALL int GetTodoLogColour() const;
	CALL int GetInvalidLogColour() const;
	CALL int GetWarningLogColour() const;

	CALL std::tstring GetRootPath();

	CALL std::tstring GetErrorTypeTrigger() const;
	CALL std::tstring GetCriticalTypeTrigger() const;
	CALL std::tstring GetTodoTypeTrigger() const;
	CALL std::tstring GetInvalidTypeTrigger() const;
	CALL std::tstring GetWarningTypeTrigger() const;
	CALL std::tstring GetInfoTypeTrigger() const;

	CALL std::tstring GetSperatorSymbol() const;
private:
	CALL bool PraseSettingsFile(const std::tstring & log_class_name);

	int critical_log_colour;
	int error_log_colour;
	int info_log_colour;
	int todo_log_colour;
	int invalid_log_colour;
	int warning_log_colour;

	IniReader settings_ini;

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
