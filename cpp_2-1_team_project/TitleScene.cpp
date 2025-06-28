#include<iostream>
#include<fstream>
#include<io.h>
#include <fcntl.h>
#include "TitleScene.h"
#include "Console.h"
#include "InfoScene.h"
#include "StageSelectScene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include <Windows.h> 
#include <mmsystem.h>

#include "SoundManager.h"
#pragma comment(lib, "winmm.lib")

using std::wcout;
using std::cout;

void TitleScene::Init()
{
	system("cls");
	SoundManager::GetInstance()->Play(SOUNDID::BGM, true);

	_consoleSize = GetConsoleResolution();
	_resX = _consoleSize.x / 2;
	_resY = _consoleSize.y / 2;
}

void TitleScene::Update()
{
	SelectMenu();
}

void TitleScene::Render()
{
	const int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);

	Gotoxy(_resX - 48, 5);
	wcout << L"██████╗  █████╗ ██╗███╗   ██╗████████╗   █████╗ ███╗   ██╗██████╗    ███████╗██╗██╗     ██╗\n";
	Gotoxy(_resX - 48, 6);
	wcout << L"██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝  ██╔══██╗████╗  ██║██╔══██╗   ██╔════╝██║██║     ██║\n";
	Gotoxy(_resX - 48, 7);
	wcout << L"██████╔╝███████║██║██╔██╗ ██║   ██║     ███████║██╔██╗ ██║██║  ██║   █████╗  ██║██║     ██║\n";
	Gotoxy(_resX - 48, 8);
	wcout << L"██╔═══╝ ██╔══██║██║██║╚██╗██║   ██║     ██╔══██║██║╚██╗██║██║  ██║   ██╔══╝  ██║██║     ██║\n";
	Gotoxy(_resX - 48, 9);
	wcout << L"██║     ██║  ██║██║██║ ╚████║   ██║     ██║  ██║██║ ╚████║██████╔╝   ██║     ██║███████╗███████╗\n";
	Gotoxy(_resX - 48, 10);
	wcout << L"╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝    ╚═╝     ╚═╝╚══════╝╚══════╝\n";

	const int wcoutMode = _setmode(_fileno(stdout), coutMode);

	Gotoxy(_resX - _menuBtnX, _menuBtnY);
	cout << "시작";
	Gotoxy(_resX - _menuBtnX, _menuBtnY + 1);
	cout << "정보";
	Gotoxy(_resX - _menuBtnX, _menuBtnY + 2);
	cout << "종료";
}

void TitleScene::SelectMenu()
{
	const KEY input = KeyController();

	switch (input)
	{
	case KEY::W:
		if (_currentMenu != MENU::Start)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			_currentMenu = static_cast<MENU>(static_cast<int>(_currentMenu) - 1);

			Gotoxy(_resX - _menuBtnX - 2, _menuBtnY + static_cast<int>(_currentMenu) + 1);
			cout << " ";
			Gotoxy(_resX - _menuBtnX - 2, _menuBtnY + static_cast<int>(_currentMenu));
			cout << ">";
		}
		break;

	case KEY::S:
		if (_currentMenu != MENU::Quit)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			_currentMenu = static_cast<MENU>(static_cast<int>(_currentMenu) + 1);

			Gotoxy(_resX - _menuBtnX - 2, _menuBtnY + static_cast<int>(_currentMenu) - 1);
			cout << " ";
			Gotoxy(_resX - _menuBtnX - 2, _menuBtnY + static_cast<int>(_currentMenu));
			cout << ">";
		}
		break;

	case KEY::SPACE:
		SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
		StartCurrentMenu();
		break;
	}
}

void TitleScene::StartCurrentMenu() const
{
	Scene* newScene = nullptr;

	switch (_currentMenu)
	{
	case MENU::Start:
		newScene = new StageSelectScene();
		SceneManager::GetInstance()->ChangeScene(newScene);
		delete this;
		break;

	case MENU::Info:
		newScene = new InfoScene();
		SceneManager::GetInstance()->ChangeScene(newScene);
		delete this;
		break;

	case MENU::Quit:
		system("cls");
		_exit(0);
		break;
	}
}