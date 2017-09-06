#define _BUILD_

#include "Logger\ELog\ELog.h"

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

bool ELog::initialize()
{
	if (!this->log_settings.initialize("ELog"))
		return false;
	return true;
}

bool ELog::shutDown()
{
	this->log_messages.clear();
	return true;
}

void ELog::log(const std::tstring & logCode, const std::tstring & logErrorCompenent, const std::tstring & logScopeName, const std::tstring & logMessage, LogType logType, const std::tstring & logFileName, int lineNum)
{
	std::tsstream buffer;
	std::tsstream message_buffer;

	switch (logType)
	{
	case LogType::INVALID_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getInvalidLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getInvalidTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getInvalidTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

		this->log_messages.push_back(LogData(LogType::INVALID_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::ERROR_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getErrorLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getErrorTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getErrorTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

		this->log_messages.push_back(LogData(LogType::ERROR_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::CRITICAL_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getCriticalLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getCriticalTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getCriticalTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

		this->log_messages.push_back(LogData(LogType::CRITICAL_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::TODO_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getTodoLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getTodoTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getTodoTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

		this->log_messages.push_back(LogData(LogType::TODO_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::INFO_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getInfoLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getInfoTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getInfoTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

		this->log_messages.push_back(LogData(LogType::INFO_LOG, buffer.str()));

		std::tcout << message_buffer.str();
		OutputDebugString(buffer.str().c_str());

		break;
	case LogType::WARNING_LOG:

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->log_settings.getWarningLogColour());
		message_buffer << _T("[  ") << logCode.c_str() << _T("] ") << logErrorCompenent.c_str();
		message_buffer << SPACE << this->log_settings.getWarningTypeTrigger().c_str() << SPACE;
		message_buffer << logFileName.c_str() << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << logScopeName.c_str() << this->log_settings.getSperatorSymbol().c_str() << lineNum << this->log_settings.getSperatorSymbol().c_str();
		message_buffer << SPACE << logMessage.c_str() << std::endl;

		buffer << _T("[  ") << logCode.c_str() << _T("] ");
		buffer << this->log_settings.getWarningTypeTrigger().c_str();
		buffer << _T("\n") << logMessage.c_str();
		buffer << _T("\nFound in Scope: ") << logScopeName.c_str();
		buffer << _T("\nFound in File: ") << logFileName.c_str();
		buffer << _T("\nFound at Line: ") << lineNum;

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

void ELog::log(const std::tstring & logErrorCompenent, const std::tstring & logScopeName, const std::tstring & logMessage, LogType logType, const std::tstring & logFileName, int lineNum)
{
	return void();
}

bool ELog::writeLogsToFile(const std::tstring & fileName)
{
	std::tsstream buffer;
	std::tofstream file;

	buffer << this->log_settings.getRootPath() << fileName << _T("\0");
	file.open(buffer.str().c_str(), std::ios::out | std::ios::in | std::ios::trunc);
	if (!file.is_open())
		return false;

	for (LogData& logdata : this->log_messages)
	{
		file << logdata.log_message << _T("\n");
	}

	return true;
}
