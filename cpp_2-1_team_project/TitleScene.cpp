#include "TitleScene.h"
#include "Console.h"

using std::wcout;
using std::cout;

void TitleScene::Init()
{
	system("cls");
}

void TitleScene::Update()
{
	SelectMenu();
}

void TitleScene::Render()
{
	Position consoleSize = GetConsoleResolution();
	int resX = consoleSize.x / 2;
	int resY = consoleSize.y / 2;
	Gotoxy(resX - 38, 5);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"██████╗ ██╗      ██████╗  ██████╗██╗  ██╗        ███████╗██╗██╗     ██╗" << endl;
	Gotoxy(resX - 38, 6);
	wcout << L"██╔══██╗██║     ██╔═══██╗██╔════╝██║ ██╔╝        ██╔════╝██║██║     ██║" << endl;
	Gotoxy(resX - 38, 7);
	wcout << L"██████╔╝██║     ██║   ██║██║     █████╔╝         █████╗  ██║██║     ██║" << endl;
	Gotoxy(resX - 38, 8);
	wcout << L"██╔══██╗██║     ██║   ██║██║     ██╔═██╗         ██╔══╝  ██║██║     ██║" << endl;
	Gotoxy(resX - 38, 9);
	wcout << L"██████╔╝███████╗╚██████╔╝╚██████╗██║  ██╗        ██║     ██║███████╗███████╗" << endl;
	Gotoxy(resX - 38, 10);
	wcout << L"╚═════╝ ╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝        ╚═╝     ╚═╝╚══════╝╚══════╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);

	Gotoxy(resX - menuBtnX, menuBtnY);
	cout << "Game";
	Gotoxy(resX - menuBtnX, menuBtnY + 1);
	cout << "Info";
	Gotoxy(resX - menuBtnX, menuBtnY + 2);
	cout << "Exit";

}

void TitleScene::SelectMenu()
{
	KEY input = KeyController();

	Position consoleSize = GetConsoleResolution();
	int resX = consoleSize.x / 2;
	int resY = consoleSize.y / 2;

	switch (input)
	{
	case KEY::W:
		if (_currentMenu != MENU::Start)
		{
			_currentMenu = (MENU)((int)_currentMenu - 1);

			Gotoxy(resX - menuBtnX - 2, menuBtnY + (int)_currentMenu + 1);
			cout << " ";
			Gotoxy(resX - menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case KEY::S:
		if (_currentMenu != MENU::Quit)
		{
			_currentMenu = (MENU)((int)_currentMenu + 1);

			Gotoxy(resX - menuBtnX - 2, menuBtnY + (int)_currentMenu - 1);
			cout << " ";
			Gotoxy(resX - menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case KEY::SPACE:
		StartCurrentMenu();
		break;
	}
}

void TitleScene::StartCurrentMenu()
{
	Scene* newScene = nullptr;

	switch (_currentMenu)
	{
	case MENU::Start:
		newScene = new GameScene();
		SceneManager::GetInstance()->ChangeScene(newScene);
		break;

	case MENU::Info:
		newScene = new InfoScene();
		SceneManager::GetInstance()->ChangeScene(newScene);
		break;

	case MENU::Quit:
		break;
	}
}