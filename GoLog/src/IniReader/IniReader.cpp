#define _BUILD_

#include "IniReader/IniReader.h"
#include <Windows.h>
#include "defines/stringstream.h"
#include <assert.h>

#define data this->ini_data
#define SELFOBJECT this

IniReader::IniReader()
{
	
}

IniReader::IniReader(const tchar* fileName)
{
	this->ini_data.file_name = fileName;
	this->ini_file.open(data.file_name, std::ios::out | std::ios::in);
}


IniReader::~IniReader()
{
	this->ini_file.close();
}

bool IniReader::initialize()
{
	return true;
}

bool IniReader::shutDown()
{
	this->ini_data_holder.clear();
	return true;
}

bool IniReader::loadFile(const std::tstring& fileName)
{
	if (this->ini_file.is_open())
	{
		this->ini_file.close(), this->ini_file.clear();
	}
	this->ini_file.open(fileName.c_str(), std::ios::in | std::ios::out);
	if (!this->ini_file.is_open())
	{
		OutputDebugString(_T("Couldn't open the input File\n"));
		return false;
	}
	this->ini_data.file_name = fileName;

	return true;
}

std::tstring IniReader::getString(const std::tstring& sectionName, const std::tstring& keyName)
{
	if (!this->ini_file.is_open()) { OutputDebugString(_T("Couldn't Able to Open IniReader file")); return NULLSTR; }

	std::tsstream buffer;

	std::tstring section;
	std::tstring key_value;
	std::tstring key;
	std::tstring value;

	buffer << OPENBRACE << sectionName.c_str() << CLOSEBRACE;

	while (std::getline(this->ini_file, section))
	{
		if (section == buffer.str().c_str())
		{
			while (std::getline(this->ini_file, key_value))
			{
				key = key_value.substr(0, key_value.find_first_of(OPERATOR));
				value = key_value.substr(key_value.find_first_of(OPERATOR) + 1);
				if (key == keyName) 
				{ 
					std::tsstream bufferd; bufferd << value.c_str();
					this->ini_data_holder.push_back(IniData(buffer.str().c_str(),key.c_str(),bufferd.str(),ReaderDataType::STR_DATA_TYPE, this->ini_data.file_name.c_str()));
					SELFOBJECT->ini_file.seekg(0); bufferd.clear(); buffer.clear(); return value;
				}
				if (key.c_str() == NULLSTR || value.c_str() == NULLSTR) { SELFOBJECT->ini_file.seekg(0); buffer.clear();  return NULLSTR; }
			}
		}
	}
	return value;
}

signed long long int IniReader::getInt64(const std::tstring& sectionName, const std::tstring& keyName)
{
	if (!this->ini_file.is_open()) { OutputDebugString(_T("Couldn't Able to Open IniReader file")); return 0; }

	std::tsstream buffer;

	std::tstring section;
	std::tstring key_value;
	std::tstring key;
	std::tstring value;

	buffer << OPENBRACE << sectionName.c_str() << CLOSEBRACE;

	while (std::getline(this->ini_file, section))
	{
		if (section == buffer.str().c_str())
		{
			while (std::getline(this->ini_file, key_value))
			{
				key = key_value.substr(0, key_value.find_first_of(OPERATOR));
				value = key_value.substr(key_value.find_first_of(OPERATOR) + 1);
				if (key == keyName)
				{
					this->ini_data_holder.push_back(IniData(buffer.str().c_str(), key.c_str(), _tstoi64(value.c_str()), ReaderDataType::INT64_DATA_TYPE, this->ini_data.file_name.c_str()));
					SELFOBJECT->ini_file.seekg(0); buffer.clear(); return _tstoi64(value.c_str());
				}
				if (key.c_str() == NULLSTR || value.c_str() == NULLSTR) { SELFOBJECT->ini_file.seekg(0); buffer.clear();  return 0; }
			}
		}
	}
	return _tstoi64(value.c_str());
}

int IniReader::getInt(const std::tstring& sectionName, const std::tstring& keyName)
{
	if (!this->ini_file.is_open()) { OutputDebugString(_T("Couldn't Able to Open IniReader file")); return 0; }

	std::tsstream buffer;

	std::tstring section;
	std::tstring key_value;
	std::tstring key;
	std::tstring value;

	buffer << OPENBRACE << sectionName.c_str() << CLOSEBRACE;

	while (std::getline(this->ini_file, section))
	{
		if (section == buffer.str().c_str())
		{
			while (std::getline(this->ini_file, key_value))
			{
				key = key_value.substr(0, key_value.find_first_of(OPERATOR));
				value = key_value.substr(key_value.find_first_of(OPERATOR) + 1);
				if (key == keyName)
				{
					this->ini_data_holder.push_back(IniData(buffer.str().c_str(), key.c_str(), _tstoi(value.c_str()),ReaderDataType::INT_DATA_TYPE, this->ini_data.file_name.c_str()));
					SELFOBJECT->ini_file.seekg(0); buffer.clear(); return _tstoi(value.c_str());
				}
				if (key.c_str() == NULLSTR || value.c_str() == NULLSTR) { SELFOBJECT->ini_file.seekg(0); buffer.clear();  return 0; }
			}
		}
	}
	return _tstoi(value.c_str());
}

double IniReader::getDouble(const std::tstring& sectionName, const std::tstring& keyName)
{
	if (!this->ini_file.is_open()) { OutputDebugString(_T("Couldn't Able to Open IniReader file")); return 0; }

	std::tsstream buffer;

	std::tstring section;
	std::tstring key_value;
	std::tstring key;
	std::tstring value;

	buffer << OPENBRACE << sectionName.c_str() << CLOSEBRACE;

	while (std::getline(this->ini_file, section))
	{
		if (section == buffer.str().c_str())
		{
			while (std::getline(this->ini_file, key_value))
			{
				key = key_value.substr(0, key_value.find_first_of(OPERATOR));
				value = key_value.substr(key_value.find_first_of(OPERATOR) + 1);
				if (key == keyName)
				{
					this->ini_data_holder.push_back(IniData(buffer.str().c_str(), key.c_str(), _tstof(value.c_str()),ReaderDataType::DOUBLE_DATA_TYPE,this->ini_data.file_name.c_str()));
					SELFOBJECT->ini_file.seekg(0); buffer.clear(); return _tstof(value.c_str());
				}
				if (key.c_str() == NULLSTR || value.c_str() == NULLSTR) { SELFOBJECT->ini_file.seekg(0); buffer.clear();  return 0; }
			}
		}
	}
	return _tstof(value.c_str());
}


bool IniReader::getBool(const std::tstring& sectionName, const std::tstring& keyName)
{
	if (!this->ini_file.is_open()) { OutputDebugString(_T("Couldn't Able to Open IniReader file")); return 0; }

	std::tsstream buffer;

	std::tstring section;
	std::tstring key_value;
	std::tstring key;
	std::tstring value;

	buffer << OPENBRACE << sectionName.c_str() << CLOSEBRACE;

	while (std::getline(this->ini_file, section))
	{
		if (section == buffer.str().c_str())
		{
			while (std::getline(this->ini_file, key_value))
			{
				key = key_value.substr(0, key_value.find_first_of(OPERATOR));
				value = key_value.substr(key_value.find_first_of(OPERATOR) + 1);
				if (key == keyName)
				{
					if (value == _T("true"))
					{
						this->ini_data_holder.push_back(IniData(buffer.str().c_str(), key.c_str(), true, ReaderDataType::BOOL_DATA_TYPE, this->ini_data.file_name.c_str()));
						SELFOBJECT->ini_file.seekg(0); buffer.clear();
						return true;
					}
					if (value == _T("false"))
					{
						this->ini_data_holder.push_back(IniData(buffer.str().c_str(), key.c_str(), false, ReaderDataType::BOOL_DATA_TYPE, this->ini_data.file_name.c_str()));
						SELFOBJECT->ini_file.seekg(0); buffer.clear();
						return false;
					}
					else
					{
						OutputDebugString(_T("Boolean variables can only hold true or false")); throw "Boolean variables can only hold true or false";
					}
				}
				if (key.c_str() == NULLSTR || value.c_str() == NULLSTR) { SELFOBJECT->ini_file.seekg(0); buffer.clear();  return NULLSTR; }
			}
		}
	}
	return 0;
}

bool IniReader::deleteLastReadedData()
{
	if (!this->ini_data_holder.size())
		return false;
	this->ini_data_holder.pop_back();
	return true;
}

void IniReader::writeAllInformation(const std::tstring& fileExtension)
{
	int current_write = 0;
	std::tsstream buffer;
	std::tsstream buffer2;

	std::tfstream file;

	buffer << getRootPath().c_str() << _T("IniReaderLogs") << _T('.') << fileExtension.c_str() << _T("\0");
	file.open(buffer.str().c_str(), std::ios::out | std::ios::in | std::ios::trunc);

	buffer2 << _T("(c)2017 The GoLog Project. \n");
	buffer2 << _T("The All in One Logging Solution For Programmers.\n\n");
	file << buffer2.str().c_str() << _T("IniReader class Object Data Logs:-\n") << std::endl;

	for (IniData& ini_data : this->ini_data_holder)
	{
		file << _T("Read Call Number: ") << current_write << std::endl;
		file << ini_data.toString() << std::endl << std::endl;
		++current_write;
	}
	buffer.clear();
	buffer2.clear();
}

IniReader& IniReader::operator=(tchar * value)
{
	(this->ini_file.is_open()) ? this->ini_file.close(),this->ini_file.clear() : 0;
	this->ini_data.file_name = value;
	this->ini_file.open(this->ini_data.file_name.c_str(),std::ios::in|std::ios::out);
	if (!this->ini_file.is_open()) OutputDebugString(_T("Couldn't open the Ini Reader's File"));
	return *(this);
}

std::tstring IniReader::getRootPath() 
{
	this->root_path = getString(_T("config"), _T("RootPath"));
	this->ini_data_holder.pop_back();
	if (root_path == NULLSTR)
		return NULLSTR;
	return root_path;
}

inline bool operator==(IniReader& left,const tchar* right)
{
	if (left.ini_data.file_name == right) return true;
	else return false;
}

std::tstring IniData::toString()
{
	std::tsstream buffer;

	switch (this->current_data_type)
	{
	case ReaderDataType::STR_DATA_TYPE:
#ifdef UNICODE
		buffer << _T("Readed Data Type->  std::wstring");
#else
		buffer << _T("Readed Data Type->  std::string");
#endif 
		break;
	case ReaderDataType::INT_DATA_TYPE:
		buffer << _T("Readed Data Type->  int");
		break;
	case ReaderDataType::INT64_DATA_TYPE:
		buffer << _T("Readed Data Type->  __int64");
		break;
	case ReaderDataType::DOUBLE_DATA_TYPE:
		buffer << _T("Readed Data Type->  Double"); 
		break;
	case ReaderDataType::BOOL_DATA_TYPE:
		buffer << _T("Readed Data Type->  Bool");
		break;
	default:
		buffer << _T("Readed Data Type->  Invalid");
		break;
	}
	buffer << _T("\nReaded From File->  ") << this->file_name.c_str();
	buffer << _T("\nReaded From Section->  ") << this->section_name.c_str();
	buffer << _T("\nReaded From Key->  ") << this->key_name.c_str();

	switch (this->current_data_type)
	{
	case ReaderDataType::STR_DATA_TYPE:
		buffer << _T("\nReaded Key's Value->  ") << this->str_value.c_str();
		break;
	case ReaderDataType::INT_DATA_TYPE:
		buffer << _T("\nReaded Key's Value->  ") << this->int_value;
		break;
	case ReaderDataType::INT64_DATA_TYPE:
		buffer << _T("\nReaded Key's Value->  ") << this->i_value;
		break;
	case ReaderDataType::DOUBLE_DATA_TYPE:
		buffer << _T("\nReaded Key's Value->  ") << this->f_value;
		break;
	case ReaderDataType::BOOL_DATA_TYPE:
		if (this->b_value == true)
			buffer << _T("\nReaded Key's Value->  ") << _T("true");
		if (this->b_value == false)
			buffer << _T("\nReaded Key's Value->  ") << _T("false");
		break;
	default:
		break;
	}

	return buffer.str();
}
