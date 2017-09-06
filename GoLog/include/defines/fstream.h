#ifndef _FSTREAM_H
#define _FSTREAM_H

#ifndef _FSTREAM_
	#include <fstream>
#endif

#ifdef UNICODE
	#define tofstream wofstream
	#define tifstream wifstream
	#define tfstream wfstream
#else
	#define tofstream ofstream
	#define tifstream ifstream
	#define tfstream fstream
#endif 

#endif // _FSTREAM_H
