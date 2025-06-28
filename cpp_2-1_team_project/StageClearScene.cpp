#include "StageClearScene.h"
#include <algorithm>
#include <corecrt_io.h>
#include <fcntl.h>
#include <iostream>
#include <Windows.h> 
#include <mmsystem.h>
#include "Console.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TitleScene.h"

using std::cout;

StageClearScene::StageClearScene(const int clearStage) : _clearStage(clearStage), _currentColor(0)
{
}

StageClearScene::~StageClearScene()
{

}

void StageClearScene::Init()
{
	system("cls");
	SoundManager::GetInstance()->Play(SOUNDID::CLEAR);

	_consoleSize = GetConsoleResolution();
	_resX = _consoleSize.x / 2 - 4;
	_resY = _consoleSize.y / 2;

	if (_clearStage == 30)
		SceneManager::GetInstance()->ChangeScene(new TitleScene());
}

void StageClearScene::Update()
{
	KEY input = KeyController();

	Gotoxy(_resX - 2, _resY + 1);
	switch (input)
	{
	case KEY::W:
		if (_currentMenu != CLEARMENU::NEXT)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			_currentMenu = static_cast<CLEARMENU>(static_cast<int>(_currentMenu) - 1);

			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu) + 1);
			cout << " ";
			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu));
			cout << ">";
		}
		break;

	case KEY::S:
		if (_currentMenu != CLEARMENU::LOBBY)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			_currentMenu = static_cast<CLEARMENU>(static_cast<int>(_currentMenu) + 1);

			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu) - 1);
			cout << " ";
			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu));
			cout << ">";
		}
		break;

	case KEY::SPACE:
		SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
		if (_currentMenu == CLEARMENU::NEXT)
			SceneManager::GetInstance()->ChangeScene(new GameScene(_clearStage + 1));
		else
			SceneManager::GetInstance()->ChangeScene(new TitleScene());
		break;
	}
}

void StageClearScene::Render()
{
	const int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);

	SetColor(static_cast<COLOR>(_currentColor / 3 + 1));
	Gotoxy(_resX - 15, _resY - 10);
	wcout << L" ██████╗██╗     ███████╗ █████╗ ██████╗     ██╗██╗";
	Gotoxy(_resX - 15, _resY - 9);
	wcout << L"██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗    ██║██║";
	Gotoxy(_resX - 15, _resY - 8);
	wcout << L"██║     ██║     █████╗  ███████║██████╔╝    ██║██║";
	Gotoxy(_resX - 15, _resY - 7);
	wcout << L"██║     ██║     ██╔══╝  ██╔══██║██╔══██╗    ╚═╝╚═╝";
	Gotoxy(_resX - 15, _resY - 6);
	wcout << L"╚██████╗███████╗███████╗██║  ██║██║  ██║    ██╗██╗";
	Gotoxy(_resX - 15, _resY - 5);
	wcout << L" ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝╚═╝";

	++_currentColor;

	if (_currentColor > 42)
		_currentColor = 0;

	SetColor();
	const int wcoutMode = _setmode(_fileno(stdout), coutMode);

	Gotoxy(_resX, _resY);
	cout << "다음 스테이지";
	Gotoxy(_resX, _resY + 1);
	cout << "로비로";
}