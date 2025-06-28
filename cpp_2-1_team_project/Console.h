#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include"Structs.h"
#include"Enums.h"

using std::cout;
using std::wcout;
using std::endl;
using std::string;
using std::wstring;
using std::vector;

void SetConsoleSettings(int width, int height, bool isFullScreen, const std::wstring& title);

void SetLockResize();

Position GetConsoleResolution();

void Gotoxy(int _x, int _y);

BOOL IsGotoxy(int _x, int _y);

COORD CurSorPos();

void SetCursorVisual(bool isVis, DWORD size);

void SetColor(COLOR textColor = COLOR::WHITE, COLOR bgColor = COLOR::BLACK);

void FrameSync(unsigned int frame);

void SetConsoleFont(LPCWSTR fontName, COORD size, UINT weight);