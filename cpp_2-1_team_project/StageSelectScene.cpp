#include "StageSelectScene.h"
#include <fstream>
#include "Console.h"
#include "GameScene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TitleScene.h"

void StageSelectScene::Init()
{
	system("cls");

	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
	std::ifstream mapFile("highStage.txt");

	if (mapFile.good())
	{
		if (mapFile.is_open())
		{
			const int temp = _highStage;
			mapFile >> _highStage;

			if (_highStage < temp)
				_highStage = temp;

			mapFile.close();
		}
		else
			_highStage = 1;
	}
	else
		_highStage = 1;
	
	SetMap();
}

void StageSelectScene::Update()
{
	_input = KeyController();

	switch (_input)
	{
	case KEY::A:
		if (_currentStage > 1)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			--_currentStage;
			SetMap();
		}
		break;

	case KEY::D:
		if (_currentStage < _highStage)
		{
			SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
			++_currentStage;
			SetMap();
		}
		break;

	case KEY::SPACE:
		SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
		SceneManager::GetInstance()->ChangeScene(new GameScene(_currentStage));
		break;
	
	case KEY::ESC:
		SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
		Exit();
		break;
	}
}

void StageSelectScene::Render()
{
	Gotoxy(42, 4);
	SetColor(COLOR::LIGHT_RED);
	cout << "Sel";

	Gotoxy(45, 4);
	SetColor(COLOR::LIGHT_GREEN);
	cout << "ect";

	Gotoxy(48, 4);
	SetColor(COLOR::LIGHT_BLUE);
	cout << " Sta";

	Gotoxy(52, 4);
	SetColor(COLOR::LIGHT_YELLOW);
	cout << "ge";

	SetColor();
	Gotoxy(44, 10);

	if(_currentStage < 10)
		cout << "Stage: 0" << _currentStage << endl;
	else
		cout << "Stage: " << _currentStage << endl;

	Gotoxy(42, 17);

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		Gotoxy(42, 15 + i + 1);

		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			auto currentPos = Position(i, j);

			if (_map[i][j] == static_cast<char>(TILE::Wall))
			{
				SetColor(COLOR::WHITE, COLOR::WHITE);
				cout << "■";
				SetColor();
			}
			else if (_map[i][j] == static_cast<char>(TILE::Road))
				cout << "□";
			else if (_map[i][j] == static_cast<char>(TILE::Start))
				cout << "▣";
		}

		cout << '\n';
	}

	if (_currentStage == 1) 
	{
		Gotoxy(62, 10);
		cout << ">>";

		Gotoxy(32, 10);
		cout << "  ";
	}
	else if (_currentStage == _highStage)
	{
		Gotoxy(62, 10);
		cout << "  ";

		Gotoxy(32, 10);
		cout << "<<";
	}
	else
	{
		Gotoxy(62, 10);
		cout << ">>";

		Gotoxy(32, 10);
		cout << "<<";
	}
}

void StageSelectScene::SetMap()
{
	std::ifstream mapFile("Stage" + std::to_string(_currentStage) + ".txt");

	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
			mapFile.getline(_map[i].data(), MAP_WIDTH + 1);

		mapFile.close();
	}
	else
		cout << "맵 파일을 열 수 없습니다.";
}

void StageSelectScene::Exit()
{
	SceneManager::GetInstance()->ChangeScene(new TitleScene());
}