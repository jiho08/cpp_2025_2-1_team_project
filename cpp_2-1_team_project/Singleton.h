#pragma once
#include "defines.h"

template<typename T>
class Singleton
{
protected:
	Singleton() {}
	~Singleton() {}

public:
	static T* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new T;

		return m_instance;
	}

	static void DestroyInstance()
	{
		SAFE_DELETE(m_instance)
	}

private:
	static T* m_instance;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;