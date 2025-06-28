#include "Console.h"

void SetConsoleSettings(const int width, const int height, const bool isFullScreen, const std::wstring& title)
{
	const HWND hwnd = GetConsoleWindow();

	SetConsoleTitle(title.c_str());

	if (isFullScreen)
	{
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		ShowWindow(hwnd, SW_MAXIMIZE);
	}
	else
	{
		LONG style = GetWindowLong(hwnd, GWL_STYLE);
		style &= ~WS_CAPTION;
		SetWindowLong(hwnd, GWL_STYLE, style);

		MoveWindow(hwnd, 260, 60, width, height, true);
	}
}

void SetLockResize()
{
	const HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

Position GetConsoleResolution()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(handle, &buf);
	const short width = buf.srWindow.Right - buf.srWindow.Left + 1;
	const short height = buf.srWindow.Bottom - buf.srWindow.Top + 1;

	return { width, height };
}

void Gotoxy(int _x, int _y)
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD Cur = { _x, _y };

	SetConsoleCursorPosition(handle, Cur);
}

BOOL IsGotoxy(int _x, int _y)
{

	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	const COORD Cur = { _x, _y };

	return SetConsoleCursorPosition(handle, Cur);
}

COORD CurSorPos()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(handle, &buf);
	return buf.dwCursorPosition;
}

void SetCursorVisual(const bool isVis, const DWORD size)
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = size;
	curInfo.bVisible = isVis;
	SetConsoleCursorInfo(handle, &curInfo);
}

void SetColor(COLOR textColor, COLOR bgColor)
{
	const int tColor = static_cast<int>(textColor);
	const int bColor = static_cast<int>(bgColor);
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (bColor << 4 | tColor));
}

void FrameSync(const unsigned int frame)
{
	clock_t oldTime = clock();

	while (true)
	{
		const clock_t curTime = clock();

		if (curTime - oldTime > 1000 / frame)
		{
			oldTime = curTime;
			break;
		}
	}
}

void SetConsoleFont(const LPCWSTR fontName, const COORD size, const UINT weight)
{
	// 콘솔 핸들
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 구조체 초기화
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// 현재 폰트 정보 Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = size; // 폭, 높이
	cf.FontWeight = weight; // FW~
	wcscpy_s(cf.FaceName, fontName); // 폰트이름 복사
	// 폰트 정보 Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}