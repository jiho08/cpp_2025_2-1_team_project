#include "StageSelectScene.h"


void StageSelectScene::Init()
{
	system("cls");
	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
	std::ifstream mapFile("highStage.txt");
	if (mapFile.good())
	{
		if (mapFile.is_open())
		{
			int temp = _highStage;
			mapFile >> _highStage;
			if (_highStage < temp)
			{
				_highStage = temp;
			}
			mapFile.close();

		}
		else
		{
			_highStage = 29;
		}

	}
	else
	{
		_highStage = 29; 
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
		{
			_currentStage--;
			SetMap();
		}
		break;
	case KEY::D:
		if (_currentStage < _highStage)
		{
			_currentStage++;
			SetMap();
		}
		break;

	case KEY::SPACE:
		SceneManager::GetInstance()->ChangeScene(new GameScene(_currentStage));
		break;
	
	case KEY::ESC:
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
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		Gotoxy(42, 15 + i + 1);

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

void StageSelectScene::Exit()
{
	SceneManager::GetInstance()->ChangeScene(new TitleScene());
}
