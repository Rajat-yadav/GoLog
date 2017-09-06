#include <string>
#include <iostream>

#include "IniReader.h"

int main()
{
	IniReader ini;
	ini.loadFile(_T("GoLog.ini"));
	return 0;
}
