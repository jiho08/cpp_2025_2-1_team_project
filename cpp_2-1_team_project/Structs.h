#pragma once
#include <string>
#include <Windows.h>

struct Position
{
	int x, y;

	bool operator==(const Position& other) const
	{
		return (x == other.x && y == other.y);
	}
};

struct SoundEntry
{
	std::wstring path; // 파일 경로
	int volume;  // 볼륨 (0~100)  
	UINT deviceId; // MCI 장치 ID (초기값 0)
};