#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <assert.h>

template <class T>
class Singleton
{
public:
	static bool createInstance()
	{
		if (Singleton::instance != nullptr)
			return false;

		Singleton::instance = new T;
		return true;
	}
	static void destroyInstance()
	{
		if (Singleton::instance)
		{
			delete Singleton::instance;
			Singleton::instance = nullptr;
		}
	}

	static T& getInstance()
	{
		assert(Singleton::instance != nullptr);
		return *(Singleton::instance);
	}

	static bool hasInstance()
	{
		return instance != nullptr;
	}

protected:
	Singleton() {}
	virtual ~Singleton() {}

private:
	Singleton(Singleton const&) {}
	Singleton& operator=(Singleton const&) {}

	static T* instance;
};

template <class T>
T* Singleton<T>::instance = nullptr;

#endif // _SINGLETON_H
