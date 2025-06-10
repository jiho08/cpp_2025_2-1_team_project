#include "TitleScene.h"
#include "Console.h"
#include <iostream>
#include <fstream>
#include<io.h>
#include<fcntl.h>

using std::wcout;
using std::cout;

void TitleScene::Init()
{
}

void TitleScene::Update()
{

}

void TitleScene::Render()
{

	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"██████╗ ██╗      ██████╗  ██████╗██╗  ██╗        ███████╗██╗██╗     ██╗" << endl;
	wcout << L"██╔══██╗██║     ██╔═══██╗██╔════╝██║ ██╔╝        ██╔════╝██║██║     ██║" << endl;
	wcout << L"██████╔╝██║     ██║   ██║██║     █████╔╝         █████╗  ██║██║     ██║" << endl;
	wcout << L"██╔══██╗██║     ██║   ██║██║     ██╔═██╗         ██╔══╝  ██║██║     ██║" << endl;
	wcout << L"██████╔╝███████╗╚██████╔╝╚██████╗██║  ██╗        ██║     ██║███████╗███████╗" << endl;
	wcout << L"╚═════╝ ╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝        ╚═╝     ╚═╝╚══════╝╚══════╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
}