#include "KeyController.h"

KEY KeyController()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Sleep(60);
		return KEY::SPACE;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		Sleep(50);
		return KEY::ESC;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Sleep(60);
		return KEY::W;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Sleep(60);
		return KEY::A;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Sleep(60);
		return KEY::S;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		Sleep(60);
		return KEY::D;
	}

	if (GetAsyncKeyState('C') & 0x8000)
	{
		Sleep(60);
		return KEY::C;
	}

	if (GetAsyncKeyState('B') & 0x8000)
	{
		Sleep(60);
		return KEY::B;
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		Sleep(60);
		return KEY::R;
	}

	return KEY::Fail;
}
