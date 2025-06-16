#include "Core.h"
#include "Enums.h"
#include "Console.h"
#include "defines.h"
#include "ICommand.h"
#include "InputHandler.h"
#include "Player.h"

Core::Core()
	: _isRunning(true)
	, _player(nullptr)
	, _inputHandler(nullptr)
	, _resolution{}
{
	_resolution = GetConsoleResolution();
	_inputHandler = new InputHandler;
	_player = new Player({ _resolution.x / 2, _resolution.y / 2 });
}

Core::~Core()
{
	SAFE_DELETE(_player)
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
}

void Core::Update()
{
	ICommand* cmd = _inputHandler->HandleInput();

	if (cmd)
	{
		cmd->Execute(_player);
		delete cmd; // 호출한 core가 delete를 해야 누수가 안남
	}

	_player->Update();

	//switch (currentScene)
	//{
	//case Title:

	//	break;
	//case Game:
	//	break;
	//case Setting:
	//	break;
	//case Exit:
	//	break;
	//}
}

void Core::Render()
{
	_player->Render();
}

