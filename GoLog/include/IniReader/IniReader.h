#ifndef _INIREADER_H
#define _INIREADER_H

// Include Files
#ifndef _DLL_H
	#include "defines/Dll.h"
#endif
#ifndef _VECTOR_
	#include <vector>
#endif 
#ifndef _STRING_H
	#include "defines/string.h"
#endif 
#ifndef _FSTREAM_H
	#include "defines/fstream.h"
#endif

#ifdef UNICODE
#define OPERATOR _T('=')
#define OPENBRACE _T("[")
#define CLOSEBRACE _T("]")
#else
#define OPERATOR '='
#define OPENBRACE "["
#define CLOSEBRACE "]"
#endif

enum class ReaderDataType
{
	STR_DATA_TYPE,
	INT_DATA_TYPE,
	INT64_DATA_TYPE,
	DOUBLE_DATA_TYPE,
	BOOL_DATA_TYPE
};


struct IniData
{
	IniData() {}
	IniData(const std::tstring& section_name, const std::tstring& key_name, const std::tstring& value, ReaderDataType type, const std::tstring& file) :str_value(value), section_name(section_name), key_name(key_name), current_data_type(type), file_name(file) {}
	IniData(const std::tstring& section_name, const std::tstring& key_name, signed long long int value, ReaderDataType type, const std::tstring& file) :i_value(value), section_name(section_name), key_name(key_name), current_data_type(type), file_name(file) {}
	IniData(const std::tstring& section_name, const std::tstring& key_name, int value, ReaderDataType type, const std::tstring& file) :int_value(value), section_name(section_name), key_name(key_name), current_data_type(type), file_name(file) {}
	IniData(const std::tstring& section_name, const std::tstring& key_name, double value, ReaderDataType type, const std::tstring& file) :f_value(value), section_name(section_name), key_name(key_name), current_data_type(type), file_name(file) {}
	IniData(const std::tstring& section_name, const std::tstring& key_name, bool value, ReaderDataType type, const std::tstring& file) :b_value(value), section_name(section_name), key_name(key_name), current_data_type(type), file_name(file) {}

	ReaderDataType current_data_type;

	std::tstring file_name;
	std::tstring section_name;
	std::tstring key_name;

	std::tstring str_value;
	signed long long int i_value;
	int int_value;
	double f_value;
	bool b_value;

	std::tstring toString();
};

class IniReader
{
public:
	CALL IniReader();
	CALL IniReader(const tchar* fileName);
	CALL ~IniReader();

	CALL bool initialize();
	CALL bool shutDown();

	CALL bool loadFile(const std::tstring& fileName);

	CALL std::tstring getString(const std::tstring& sectionName, const std::tstring& keyName);
	CALL signed long long int getInt64(const std::tstring& sectionName, const std::tstring& keyName);
	CALL int getInt(const std::tstring& sectionName, const std::tstring& keyName);
	CALL double getDouble(const std::tstring& sectionName, const std::tstring& keyName);
	CALL bool getBool(const std::tstring& sectionName, const std::tstring& keyName);

	CALL bool deleteLastReadedData();

	CALL void writeAllInformation(const std::tstring& fileExtension);

	CALL IniReader& operator =(tchar* value);
private:
	CALL std::tstring getRootPath();

	CALL IniReader(const IniReader&);
	IniReader& operator=(IniReader const&);
	IniData ini_data;
	std::vector<IniData> ini_data_holder;
	std::tfstream ini_file;

	std::tstring root_path;

	friend bool CALL operator==(IniReader& left, const tchar* _Right);
};

#endif //_INIREADER_H
