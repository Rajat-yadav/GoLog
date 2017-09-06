// Test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger\ELog\ELog.h"
#include <iostream>

int main()
{
	ELog ks;
	Logger* dk = new ELog;
	std::cout << dk->initialize();
	dk->log("0.000001","dks", "skd", "sda", LogType::WARNING_LOG, __FILE__, __LINE__);
	dk->writeLogsToFile("hello.txt");
	system("PAUSE");
    return 0;
}

