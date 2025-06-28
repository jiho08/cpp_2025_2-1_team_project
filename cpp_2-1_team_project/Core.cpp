#include "Core.h"
#include "Console.h"
#include "SceneManager.h"
#include "SoundManager.h"
#pragma comment(lib, "winmm.lib")

Core::Core() : _isRunning(true), _resolution{}
{
	_resolution = GetConsoleResolution();
}

void Core::Run()
{
	Init();

	while (_isRunning)
	{
		Update();
		Render();
		FrameSync(60);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 600, false, TEXT("Paint And Fill"));
	SetCursorVisual(false, 50);
	SetConsoleFont(L"Consolas", { 18, 18 }, FW_NORMAL);
	
	SceneManager::GetInstance()->Init();
	SoundManager::GetInstance()->Init();
	SoundManager::GetInstance()->Play(SOUNDID::BGM, true);
}

void Core::Update()
{
	SceneManager::GetInstance()->Update();
}

void Core::Render()
{
	SceneManager::GetInstance()->Render();
}