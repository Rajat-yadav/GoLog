#ifndef _STRINGSTREAM_H
#define _STRINGSTREAM_H

#ifndef _SSTREAM_
	#include <sstream>
#endif 

#ifdef UNICODE
	#define tsstream wstringstream
#else
	#define tsstream stringstream
#endif 

#endif // _STRINGSTREAM_H
