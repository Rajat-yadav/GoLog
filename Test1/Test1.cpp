// Test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "logger\elog\elog.h"
#include <iostream>

int main()
{
	ELog ks;
	Logger* dk = new ELog;
	std::cout << dk->Initialize();
	dk->Log("0.000001","dks", "skd", "sda", LogType::WARNING_LOG,__FILE__,__LINE__);
	dk->WriteLogsToFile("hello.txt");
	system("PAUSE");
    return 0;
}

