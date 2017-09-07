#define _BUILD_

#include "logger\elog\elog.h"

//Include Files
#include "defines\iostream.h"
#include "defines\stringstream.h"
#include "defines\fstream.h"

#ifndef _WINDOWS_
	#include <Windows.h>
#endif


ELog::ELog()
{

}


ELog::~ELog()
{

}

bool ELog::Initialize()
{
	if (!this->log_settings.Initialize("ELog"))
		return false;
	return true;
}

bool ELog::ShutDown()
{
	this->log_messages.clear();
	return true;
}

void ELog::Log(const std::tstring & log_code, const std::tstring & log_error_compenent, const std::tstring & log_scope_name, const std::tstring & log_message, LogType log_type, const std::tstring & log_file_name, int line_num)
{
	std::tsstream buffer;
	std::tsstream message_buffer;

	switch (log_type)
	{
	case LogType::INVALID_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetInvalidLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetInvalidTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetInvalidTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::INVALID_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::ERROR_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetErrorLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetErrorTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetErrorTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::ERROR_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::CRITICAL_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetCriticalLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetCriticalTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetCriticalTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::CRITICAL_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::TODO_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetTodoLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetTodoTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetTodoTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::TODO_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::INFO_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetInfoLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetInfoTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetInfoTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::INFO_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::WARNING_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.GetWarningLogColour());
		message_buffer << _T("[  ") << log_code.c_str() << _T("] ") << log_error_compenent.c_str();
		message_buffer << SPACE << this->log_settings.GetWarningTypeTrigger().c_str() << SPACE;
		message_buffer << log_file_name.c_str() << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << log_scope_name.c_str() << this->log_settings.GetSperatorSymbol().c_str() << line_num << this->log_settings.GetSperatorSymbol().c_str();
		message_buffer << SPACE << log_message.c_str() << std::endl;

		buffer << _T("[  ") << log_code.c_str() << _T("] ");
		buffer << this->log_settings.GetWarningTypeTrigger().c_str();
		buffer << _T("\n") << log_message.c_str();
		buffer << _T("\nFound in Scope: ") << log_scope_name.c_str();
		buffer << _T("\nFound in File: ") << log_file_name.c_str();
		buffer << _T("\nFound at Line: ") << line_num;

		this->log_messages.push_back(LogData(LogType::WARNING_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	default:
		break;
	}
	message_buffer.clear();
	buffer.clear();
	message_buffer.str("");
	buffer.str("");
}

bool ELog::WriteLogsToFile(const std::tstring & file_name)
{
	std::tsstream buffer;
	std::tofstream file;

	buffer << this->log_settings.GetRootPath() << file_name << _T("\0");
	file.open(buffer.str().c_str(), std::ios::out | std::ios::in | std::ios::trunc);
	if (!file.is_open())
		return false;

	for (LogData& logdata : this->log_messages)
	{
		file << logdata.log_message << _T("\n");
	}

	return true;
}
