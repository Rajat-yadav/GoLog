#ifndef _DLL_H
#define _DLL_H

#ifdef _BUILD_
	#define CALL __declspec(dllexport)
#else
	#define CALL __declspec(dllimport)
#endif 

#endif // _DLL_H
