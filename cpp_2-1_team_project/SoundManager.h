#pragma once
#include <Windows.h>
#include "Enums.h"
#include "Singleton.h"

class SoundManager : Singleton<SoundManager>
{
public:
	bool OpenMciDevice(LPCWSTR deviceType, LPCWSTR elementName, UINT& deviceId);
	void CloseMciDevice(UINT& deviceId);
	void PlayMciDevice(UINT deviceId, bool repeat = false);
	bool InitAllSounds();
	void PlaySoundID(SOUNDID id, bool repeat = false);
	void ReleaseAllSounds();
};