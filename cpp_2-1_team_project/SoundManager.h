#pragma once
#include <vector>
#include <Windows.h>
#include "Singleton.h"
#include "Enums.h"
#include "Structs.h"

class SoundManager : public Singleton<SoundManager>
{
	friend class Singleton;

public:
	bool Init();
	void Play(SOUNDID id, bool repeat = false);
	void Release();

private:
	bool OpenMciDevice(LPCWSTR deviceType, LPCWSTR elementName, UINT& deviceId);
	void CloseMciDevice(UINT& deviceId);
	void PlayMciDevice(UINT deviceId, bool repeat = false);

	std::vector<SoundEntry> _soundTable =
	{
		{L"BGM.wav", 100, 0},
		{L"Win.wav", 100, 0},
		{L"PlayerMove.wav", 100, 0},
		{L"ButtonClick.wav", 100, 0},
		{L"Failed.wav", 100, 0}
	};
};