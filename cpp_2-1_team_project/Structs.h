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
	std::wstring path; // ���� ���
	int volume;  // ���� (0~100)  
	UINT deviceId; // MCI ��ġ ID (�ʱⰪ 0)
};