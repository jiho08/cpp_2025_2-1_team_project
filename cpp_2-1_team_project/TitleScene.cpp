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
	Key input = KeyController();


	switch (input)
	{
	case Key::W:
		if (_currentMenu != Menu::Start) 
		{
			_currentMenu = (Menu)((int)_currentMenu - 1);

			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu + 1);
			cout << " ";
			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case Key::S:
		if (_currentMenu != Menu::Quit)
		{
			_currentMenu = (Menu)((int)_currentMenu + 1);

			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu - 1);
			cout << " ";
			Gotoxy(menuBtnX - 2, menuBtnY + (int)_currentMenu);
			cout << ">";
		}
		break;

	case Key::SPACE:

		StartCurrentMenu();
		break;

	default:
		break;
	}

}

void TitleScene::StartCurrentMenu()
{

	switch (_currentMenu)
	{
	case Menu::Start:
		//SceneManager::ChangeScene(new GameSc);
		break;
	case Menu::Info:
		break;
	case Menu::Quit:
		break;
	}
}


