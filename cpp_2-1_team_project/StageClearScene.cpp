#include "StageClearScene.h"
#include <corecrt_io.h>
#include <fcntl.h>
#include <iostream>
#include "Console.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "TitleScene.h"

using std::cout;

StageClearScene::StageClearScene(const int clearStage) : _clearStage(clearStage)
{
}

StageClearScene::~StageClearScene()
{
}

void StageClearScene::Init()
{
	system("cls");

	_consoleSize = GetConsoleResolution();
	_resX = _consoleSize.x / 2 - 4;
	_resY = _consoleSize.y / 2;
}

void StageClearScene::Update()
{
	KEY input = KeyController();

	switch (input)
	{
	case KEY::W:
		if (_currentMenu != CLEARMENU::NEXT)
		{
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
			_currentMenu = static_cast<CLEARMENU>(static_cast<int>(_currentMenu) + 1);

			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu) - 1);
			cout << " ";
			Gotoxy(_resX - 2, _resY + static_cast<int>(_currentMenu));
			cout << ">";
		}
		break;

	case KEY::SPACE:
		SceneManager::GetInstance()->ChangeScene(new TitleScene());
		//StartCurrentMenu();
		break;
	}
}

void StageClearScene::Render()
{
	const int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);

	//for (int i = 1; i < 15; ++i)
	//{
	//	SetColor(static_cast<COLOR>(i));
	//	Gotoxy(_resX - 15, _resY - 10);
	//	wcout << L" ██████╗██╗     ███████╗ █████╗ ██████╗     ██╗██╗\n";
	//	//Sleep(10);
	//	Gotoxy(_resX - 15, _resY - 9);
	//	wcout << L"██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗    ██║██║\n";
	//	//Sleep(10);
	//	Gotoxy(_resX - 15, _resY - 8);
	//	wcout << L"██║     ██║     █████╗  ███████║██████╔╝    ██║██║\n";
	//	//Sleep(10);
	//	Gotoxy(_resX - 15, _resY - 7);
	//	wcout << L"██║     ██║     ██╔══╝  ██╔══██║██╔══██╗    ╚═╝╚═╝\n";
	//	//Sleep(10);
	//	Gotoxy(_resX - 15, _resY - 6);
	//	wcout << L"╚██████╗███████╗███████╗██║  ██║██║  ██║    ██╗██╗\n";
	//	//Sleep(10);
	//	Gotoxy(_resX - 15, _resY - 5);
	//	wcout << L" ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝╚═╝\n";
	//	//Sleep(10);
	//}

	SetColor();
	const int wcoutMode = _setmode(_fileno(stdout), coutMode);

	Gotoxy(_resX, _resY);
	cout << "다음 스테이지";
	Gotoxy(_resX, _resY + 1);
	cout << "로비로";
}