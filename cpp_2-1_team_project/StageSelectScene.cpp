#include "StageSelectScene.h"


void StageSelectScene::Init()
{
	std::ifstream mapFile("highStage.txt");
	if (mapFile.good())
	{
		if (mapFile.is_open())
		{
			mapFile >> _highStage;
			mapFile.close();

		}
		else
		{
			_highStage = 1;
		}

	}
	
	SetMap();
}

void StageSelectScene::Update()
{
	_input = KeyController();
	switch (_input)
	{
	case KEY::A:
		if (_currentStage > 1)
			_currentStage--;
		break;
	case KEY::D:
		if (_currentStage < _highStage)
			_currentStage++;
		break;
	case KEY::SPACE:
	{
		SceneManager::GetInstance()->ChangeScene(new GameScene());
		break;
	}
	}
}



void StageSelectScene::Render()
{
	Gotoxy(42, 8);
	cout << "Stage: " << _currentStage << endl;

	Gotoxy(40, 15);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			Position currentPos = Position(i, j);
			if (_map[i][j] == (char)TILE::Wall)
			{
				SetColor(COLOR::WHITE, COLOR::WHITE);
				cout << "■";
				SetColor();
			}
			else if (_map[i][j] == (char)TILE::Road)
				cout << "□";
			else if (_map[i][j] == (char)TILE::Start)
			{
				cout << "▣";
			}

		}
		cout << endl;
		Gotoxy(40, 15 + i + 1);
	}
	Gotoxy(10, 20);
	cout << "<<";
	Gotoxy(100, 20);
	cout << ">>";
}

void StageSelectScene::SetMap()
{
	std::ifstream mapFile("Stage" + std::to_string(_highStage) + ".txt");
	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{

			mapFile.getline(_map[i].data(), MAP_WIDTH + 1);
		}
		mapFile.close();
		return;
	}
	else
	{
		cout << "맵 파일을 열 수 없습니다.";
	}
}
