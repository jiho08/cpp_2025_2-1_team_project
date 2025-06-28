#include "SoundManager.h"
#include <Digitalv.h>

bool SoundManager::Init()
{
	for (auto& sound : _soundTable)
	{
		if (sound.path.empty())
			continue;

		const bool isMpeg = sound.path.ends_with(L".mp3");
		const LPCWSTR devType = isMpeg ? TEXT("mpegvideo") : TEXT("waveaudio");

		if (!OpenMciDevice(devType, sound.path.c_str(), sound.deviceId))
			return false;

		if (isMpeg)
		{
			std::wstring cmd = L"setaudio " + sound.path + L" volume to " + std::to_wstring(sound.volume);
			mciSendString(cmd.c_str(), nullptr, 0, nullptr);
		}
	}

	return true;
}

void SoundManager::Play(SOUNDID id, const bool repeat)
{
	if (static_cast<int>(id) < 0 || static_cast<int>(id) >= _soundTable.size())
		return;

	const UINT devId = _soundTable[static_cast<int>(id)].deviceId;

	if (devId == 0)
		return;

	PlayMciDevice(devId, repeat);
}

void SoundManager::Release()
{
	for (auto& sound : _soundTable)
		CloseMciDevice(sound.deviceId);
}

bool SoundManager::OpenMciDevice(const LPCWSTR deviceType, const LPCWSTR elementName, UINT& deviceId)
{
	MCI_OPEN_PARMS openParams = {};
	openParams.lpstrDeviceType = deviceType;
	openParams.lpstrElementName = elementName;

	if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
		reinterpret_cast<DWORD_PTR>(&openParams)) != 0)
		return false;

	deviceId = openParams.wDeviceID;
	return true;
}

void SoundManager::CloseMciDevice(UINT& deviceId)
{
	if (deviceId == 0)
		return;

	mciSendCommand(deviceId, MCI_CLOSE, 0, 0);
	deviceId = 0;
}

void SoundManager::PlayMciDevice(const UINT deviceId, const bool repeat)
{
	MCI_PLAY_PARMS playParams = {};
	const DWORD_PTR playFlags = repeat ? MCI_DGV_PLAY_REPEAT : MCI_NOTIFY;

	if (repeat == false && deviceId != 0)
		mciSendCommand(deviceId, MCI_SEEK, MCI_SEEK_TO_START, reinterpret_cast<DWORD_PTR>(&playParams));

	// reinterpret : 비트 단위 변환. MCI_PLAY_PARAMS*의 메모리 주소를 DWORD_PTR(정수형)으로 바꿔서 넘길라고 씀 (UB 조심)
	mciSendCommand(deviceId, MCI_PLAY, playFlags, reinterpret_cast<DWORD_PTR>(&playParams));
}