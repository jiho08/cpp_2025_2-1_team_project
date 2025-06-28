#include "Core.h"
#include "Console.h"
#include "defines.h"
#include "InputHandler.h"
#include "Player.h"
#include "SceneManager.h"
#include "SoundManager.h"
#pragma comment(lib, "winmm.lib")


Core::Core()
	: _isRunning(true)
	, _inputHandler(nullptr)
	, _resolution{}
{
	_resolution = GetConsoleResolution();
	_inputHandler = new InputHandler;
}

Core::~Core()
{
	SAFE_DELETE(_inputHandler)
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
	SetConsoleSettings(800, 600, false, TEXT("2-1 Team Project"));
	SetCursorVisual(false, 50);
	SetConsoleFont(L"Consolas", { 18, 18 }, FW_NORMAL);
	
	SceneManager::GetInstance()->Init();
	SoundManager::GetInstance()->Init();
	SoundManager::GetInstance()->Play(SOUNDID::BGM, true);
}

void Core::Update()
{
	//ICommand* cmd = _inputHandler->HandleInput();

	//if (cmd)
	//{
	//	cmd->Execute(_player);
	//	delete cmd; // 호출한 core가 delete를 해야 누수가 안남
	//}

	SceneManager::GetInstance()->Update();

	/*Scene* newScene = _currentScene->GetScene();

	if (newScene)
	{
		_currentScene = newScene;
	}*/
}

void Core::Render()
{
	SceneManager::GetInstance()->Render();
}

