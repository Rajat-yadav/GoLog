#define _BUILD_

#include "Settings.h"
#include "defines\stringstream.h"

#ifndef _WINDOWS_
	#include <Windows.h>
#endif


Settings::Settings()
{
	
}


Settings::~Settings()
{
	
}

bool Settings::initialize(const std::tstring& logClassName)
{
	if (!praseSettingsFile(logClassName))
	{
		OutputDebugString(_T("Initialization of Settings Failed! Check GoLog.ini no specified key Found.\n"));
		return false;
	}
	return true;
}

bool Settings::shutDown()
{
	return true;
}

bool Settings::praseSettingsFile(const std::tstring& logClassName)
{
	this->invalid_log_colour = 0;
	this->error_log_colour = 0;
	this->todo_log_colour = 0;
	this->info_log_colour = 0;
	this->critical_log_colour = 0;
	this->warning_log_colour = 0;

	this->ini.loadFile(_T("GoLog.ini"));

	this->critical_type_trigger = this->ini.getString(logClassName, _T("critical_trigger"));
	if (this->critical_type_trigger == NULLSTR)
		return false;

	this->error_type_trigger = this->ini.getString(logClassName, _T("error_trigger"));
	if (this->error_type_trigger == NULLSTR)
		return false;

	this->info_type_trigger = this->ini.getString(logClassName, _T("info_trigger"));
	if (this->info_type_trigger == NULLSTR)
		return false;

	this->todo_type_trigger = this->ini.getString(logClassName, _T("todo_trigger"));
	if (this->todo_type_trigger == NULLSTR)
		return false;

	this->invalid_type_trigger = this->ini.getString(logClassName, _T("invalid_trigger"));
	if (this->invalid_type_trigger == NULLSTR)
		return false;

	this->warning_type_trigger = this->ini.getString(logClassName, _T("warning_trigger"));
	if (this->warning_type_trigger == NULLSTR)
		return false;

	this->critical_log_colour = this->ini.getInt(logClassName, _T("critical_colour"));
	if (!this->critical_log_colour)
		return false;

	this->error_log_colour = this->ini.getInt(logClassName, _T("error_colour"));
	if (!this->error_log_colour)
		return false;

	this->info_log_colour = this->ini.getInt(logClassName, _T("info_colour"));
	if (!this->info_log_colour)
		return false;

	this->invalid_log_colour = this->ini.getInt(logClassName, _T("invalid_colour"));
	if (!this->invalid_log_colour)
		return false;

	this->todo_log_colour = this->ini.getInt(logClassName, _T("todo_colour"));
	if (!this->todo_log_colour)
		return false;

	this->warning_log_colour = this->ini.getInt(logClassName, _T("warning_colour"));
	if (!this->warning_log_colour)
		return false;

	this->sperator_symbol = this->ini.getString(logClassName, _T("component_seperator"));
	if (this->sperator_symbol == NULLSTR)
		return false;

#ifdef _DEBUG
	this->ini.writeAllInformation(_T("txt"));
#endif 

	return true;
}

int Settings::getCriticalLogColour() const
{
	return this->critical_log_colour;
}

int Settings::getErrorLogColour() const
{
	return this->error_log_colour;
}


int Settings::getInfoLogColour() const
{
	return this->info_log_colour;
}

int Settings::getTodoLogColour() const
{
	return this->todo_log_colour;
}


int Settings::getInvalidLogColour() const
{
	return this->invalid_log_colour;
}


int Settings::getWarningLogColour() const
{
	return this->warning_log_colour;
}

std::tstring Settings::getRootPath()
{
	this->root_path = this->ini.getString("config", "RootPath");
	this->ini.deleteLastReadedData();
	if (root_path == NULLSTR)
		return NULLSTR;
	return root_path;
}

std::tstring Settings::getErrorTypeTrigger() const
{
	return this->error_type_trigger;
}


std::tstring Settings::getCriticalTypeTrigger() const
{
	return this->critical_type_trigger;
}


std::tstring Settings::getTodoTypeTrigger() const
{
	return this->todo_type_trigger;
}


std::tstring Settings::getInvalidTypeTrigger() const
{
	return this->invalid_type_trigger;
}


std::tstring Settings::getWarningTypeTrigger() const
{
	return this->warning_type_trigger;
}

std::tstring Settings::getInfoTypeTrigger() const
{
	return this->info_type_trigger;
}


std::tstring Settings::getSperatorSymbol() const
{
	return this->sperator_symbol;
}

