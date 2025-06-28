#include "KeyController.h"

KEY KeyController()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		Sleep(40);
		return KEY::SPACE;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		Sleep(40);
		return KEY::ESC;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		Sleep(40);
		return KEY::W;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		Sleep(40);
		return KEY::A;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		Sleep(40);
		return KEY::S;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		Sleep(40);
		return KEY::D;
	}

	if (GetAsyncKeyState('C') & 0x8000)
	{
		Sleep(40);
		return KEY::C;
	}

	if (GetAsyncKeyState('Z') & 0x8000)
	{
		Sleep(40);
		return KEY::Z;
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		Sleep(40);
		return KEY::R;
	}

	return KEY::Fail;
}