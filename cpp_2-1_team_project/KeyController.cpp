#include "KeyController.h"

Key KeyController()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Sleep(60);
		return Key::SPACE;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Sleep(60);
		return Key::W;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Sleep(60);
		return Key::A;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Sleep(60);
		return Key::S;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		Sleep(60);
		return Key::D;
	}


	return Key::Fail;
}
