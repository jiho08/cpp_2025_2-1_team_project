#include "Console.h"
#include<Windows.h>

void Console::SetConsoleSettings(int _width, int _height, bool _isFullScreen, const std::wstring& _title)
{
	HWND hwnd = GetConsoleWindow();

	SetConsoleTitle(_title.c_str());

	if (_isFullScreen)
	{
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		ShowWindow(hwnd, SW_MAXIMIZE);
	}
	else
	{
		LONG style = GetWindowLong(hwnd, GWL_STYLE);
		style &= ~WS_CAPTION;
		SetWindowLong(hwnd, GWL_STYLE, style);

		MoveWindow(hwnd, 0, 0, _width, _height, true);
	}
}

void Console::SetLockResize()
{
	HWND hwnd = GetConsoleWindow();
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
}

COORD Console::GetConsoleResolution()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(handle, &buf);
	short width = buf.srWindow.Right - buf.srWindow.Left + 1;
	short height = buf.srWindow.Bottom - buf.srWindow.Top + 1;

	return { width, height };
}

void Console::Gotoxy(int _x, int _y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };

	SetConsoleCursorPosition(handle, Cur);
}

BOOL Console::IsGotoxy(int _x, int _y)
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { _x, _y };

	return SetConsoleCursorPosition(handle, Cur);
}

COORD Console::CurSorPos()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO buf;
	// 3 : 포인터 로드 + 역참조연산자
	// & : 참조연산자 + 주소연산자
	GetConsoleScreenBufferInfo(handle, &buf);
	return buf.dwCursorPosition;
}

void Console::SetCursorVisual(bool _isVis, DWORD _size)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = _size;
	curInfo.bVisible = _isVis;
	SetConsoleCursorInfo(handle, &curInfo);
}

void Console::SetColor(COLOR _textcolor, COLOR _bgcolor)
{
	int textcolor = (int)_textcolor;
	int bgcolor = (int)_bgcolor;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (bgcolor << 4 | textcolor));
}

void Console::FrameSync(unsigned int _frame)
{
	clock_t oldtime, curtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _frame)
		{
			oldtime = curtime;
			break;
		}
	}
}

void Console::SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight)
{
	// 콘솔 핸들
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 구조체 초기화
	CONSOLE_FONT_INFOEX cf = {};
	cf.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// 현재 폰트 정보 Get
	GetCurrentConsoleFontEx(handle, false, &cf);
	cf.dwFontSize = _size; // 폭, 높이
	cf.FontWeight = _weight; // FW~
	wcscpy_s(cf.FaceName, _fontname); // 폰트이름 복사
	// 폰트 정보 Set
	SetCurrentConsoleFontEx(handle, false, &cf);
}

