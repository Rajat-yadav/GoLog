#ifndef _IOSTREAM_H
#define _IOSTREAM_H

#ifndef _IOSTREAM_
	#include <iostream>
#endif 

#ifdef UNICODE
	#define tcout wcout
#else
	#define tcout cout
#endif 


#endif // _IOSTREAM_H
