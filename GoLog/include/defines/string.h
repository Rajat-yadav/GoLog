#ifndef _STRING_H
#define _STRING_H

#ifndef _INC_TCHAR
	#include <tchar.h>
#endif 
#ifndef _STRING_
	#include <string>
#endif

#ifdef UNICODE
	#define tstring wstring
	#define tchar wchar_t
	#define TORSTRING(value) to_wstring(value)
	#define NULLSTR _T("")
	#define NULLCHAR _T('')
	#define SPACE _T(" ")
#else
	#define tstring string
	#define tchar char
	#define TORSTRING(value) to_string(value)
	#define NULLSTR ""
	#define NULLCHAR ''
	#define SPACE " "
#endif 

#endif // _STRING_H
