#pragma once
#include "defines.h"

class Single
{
	Single();

public:
	static Single* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new Single;

		return m_instance;
	}

	static void DestroyInstance()
	{
		SAFE_DELETE(m_instance)
	}

private:
	static Single* m_instance;
};