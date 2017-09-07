#define _BUILD_

#include "settings.h"
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

bool Settings::Initialize(const std::tstring & log_class_name)
{
	if (!PraseSettingsFile(log_class_name))
	{
		OutputDebugString(_T("Initialization of Settings Failed! Check GoLog.ini no specified key Found.\n"));
		return false;
	}
	return true;
}

bool Settings::ShutDown()
{
	return true;
}

bool Settings::PraseSettingsFile(const std::tstring & log_class_name)
{
	this->invalid_log_colour = 0;
	this->error_log_colour = 0;
	this->todo_log_colour = 0;
	this->info_log_colour = 0;
	this->critical_log_colour = 0;
	this->warning_log_colour = 0;

	this->settings_ini.LoadFile(_T("GoLog.ini"));

	this->critical_type_trigger = this->settings_ini.GetString(log_class_name, _T("critical_trigger"));
	if (this->critical_type_trigger == NULLSTR)
		return false;

	this->error_type_trigger = this->settings_ini.GetString(log_class_name, _T("error_trigger"));
	if (this->error_type_trigger == NULLSTR)
		return false;

	this->info_type_trigger = this->settings_ini.GetString(log_class_name, _T("info_trigger"));
	if (this->info_type_trigger == NULLSTR)
		return false;

	this->todo_type_trigger = this->settings_ini.GetString(log_class_name, _T("todo_trigger"));
	if (this->todo_type_trigger == NULLSTR)
		return false;

	this->invalid_type_trigger = this->settings_ini.GetString(log_class_name, _T("invalid_trigger"));
	if (this->invalid_type_trigger == NULLSTR)
		return false;

	this->warning_type_trigger = this->settings_ini.GetString(log_class_name, _T("warning_trigger"));
	if (this->warning_type_trigger == NULLSTR)
		return false;

	this->critical_log_colour = this->settings_ini.GetInt(log_class_name, _T("critical_colour"));
	if (!this->critical_log_colour)
		return false;

	this->error_log_colour = this->settings_ini.GetInt(log_class_name, _T("error_colour"));
	if (!this->error_log_colour)
		return false;

	this->info_log_colour = this->settings_ini.GetInt(log_class_name, _T("info_colour"));
	if (!this->info_log_colour)
		return false;

	this->invalid_log_colour = this->settings_ini.GetInt(log_class_name, _T("invalid_colour"));
	if (!this->invalid_log_colour)
		return false;

	this->todo_log_colour = this->settings_ini.GetInt(log_class_name, _T("todo_colour"));
	if (!this->todo_log_colour)
		return false;

	this->warning_log_colour = this->settings_ini.GetInt(log_class_name, _T("warning_colour"));
	if (!this->warning_log_colour)
		return false;

	this->sperator_symbol = this->settings_ini.GetString(log_class_name, _T("component_seperator"));
	if (this->sperator_symbol == NULLSTR)
		return false;

#ifdef _DEBUG
	this->settings_ini.WriteAllReadInformation(_T("txt"));
#endif 

	return true;
}

int Settings::GetCriticalLogColour() const
{
	return this->critical_log_colour;
}

int Settings::GetErrorLogColour() const
{
	return this->error_log_colour;
}


int Settings::GetInfoLogColour() const
{
	return this->info_log_colour;
}

int Settings::GetTodoLogColour() const
{
	return this->todo_log_colour;
}


int Settings::GetInvalidLogColour() const
{
	return this->invalid_log_colour;
}


int Settings::GetWarningLogColour() const
{
	return this->warning_log_colour;
}

std::tstring Settings::GetRootPath()
{
	this->root_path = this->settings_ini.GetString("config", "RootPath");
	this->settings_ini.DeleteLastReadData();
	if (root_path == NULLSTR)
		return NULLSTR;
	return root_path;
}

std::tstring Settings::GetErrorTypeTrigger() const
{
	return this->error_type_trigger;
}


std::tstring Settings::GetCriticalTypeTrigger() const
{
	return this->critical_type_trigger;
}


std::tstring Settings::GetTodoTypeTrigger() const
{
	return this->todo_type_trigger;
}


std::tstring Settings::GetInvalidTypeTrigger() const
{
	return this->invalid_type_trigger;
}


std::tstring Settings::GetWarningTypeTrigger() const
{
	return this->warning_type_trigger;
}

std::tstring Settings::GetInfoTypeTrigger() const
{
	return this->info_type_trigger;
}


std::tstring Settings::GetSperatorSymbol() const
{
	return this->sperator_symbol;
}

