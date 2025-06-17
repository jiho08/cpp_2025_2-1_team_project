#include "TitleScene.h"
#include "Console.h"

using std::wcout;
using std::cout;



void TitleScene::Init()
{
}

void TitleScene::Update()
{
	Render();
	
	SelectMenu();

}

void TitleScene::Render()
{
	

	Gotoxy(0, 0);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"██████╗ ██╗      ██████╗  ██████╗██╗  ██╗        ███████╗██╗██╗     ██╗" << endl;
	wcout << L"██╔══██╗██║     ██╔═══██╗██╔════╝██║ ██╔╝        ██╔════╝██║██║     ██║" << endl;
	wcout << L"██████╔╝██║     ██║   ██║██║     █████╔╝         █████╗  ██║██║     ██║" << endl;
	wcout << L"██╔══██╗██║     ██║   ██║██║     ██╔═██╗         ██╔══╝  ██║██║     ██║" << endl;
	wcout << L"██████╔╝███████╗╚██████╔╝╚██████╗██║  ██╗        ██║     ██║███████╗███████╗" << endl;
	wcout << L"╚═════╝ ╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝        ╚═╝     ╚═╝╚══════╝╚══════╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);

	Gotoxy(menuBtnX, menuBtnY);
	cout << "Game";
	Gotoxy(menuBtnX, menuBtnY+1);
	cout << "Info";
	Gotoxy(menuBtnX, menuBtnY+2);
	cout << "Exit";
	
}

void TitleScene::SelectMenu()
{
	KEY input = KeyController();


	switch (input)
	{
	case KEY::W:
		if (_currentMenu != MENU::Start) 
		{
			_currentMenu = (MENU)((int)_currentMenu - 1);

			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu + 1);
			cout << " ";
			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case KEY::S:
		if (_currentMenu != MENU::Quit)
		{
			_currentMenu = (MENU)((int)_currentMenu + 1);

			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu - 1);
			cout << " ";
			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case KEY::SPACE:

		StartCurrentMenu();
		break;

	default:
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


