#pragma once
#include<iostream>

#include "Structs.h"
using std::cout;
using std::wcout;
using std::endl;
#include<string>
using std::string;
using std::wstring;
#include<vector>
using std::vector;
#include<Windows.h>
#include"Enums.h"

void SetConsoleSettings(int _width, int _height, bool _isFullScreen, const std::wstring& _title);

void SetLockResize();

Position GetConsoleResolution();

void Gotoxy(int _x, int _y);

BOOL IsGotoxy(int _x, int _y);

COORD CurSorPos();

void SetCursorVisual(bool _isVis, DWORD _size);

void SetColor(COLOR _textcolor = COLOR::WHITE, COLOR _bgcolor = COLOR::BLACK);

void FrameSync(unsigned int _frame);

void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight);