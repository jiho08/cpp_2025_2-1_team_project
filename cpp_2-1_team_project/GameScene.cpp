#include "GameScene.h"

GameScene::GameScene()
{
	system("cls");
	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));

	SetMap();

	_player = new Player(startPos);
}

GameScene::~GameScene()
{
	SAFE_DELETE(_player);
}

void GameScene::Init()
{
	
	
}

void GameScene::Update()
{
	_player->Update();
}

void GameScene::Render()
{
	Gotoxy(42, 8);
	cout << "Stage: " << stage << endl;

	Gotoxy(40, 15);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			
			Position currentPos = { j, i };
			if (_player->GetPos() == currentPos)
			{
				_map[i][j] = '2';
				cout << _player->GetSymbol();
			}
			else 
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
					startPos = { i, j };
					_map[i][j] = '0';
					cout << "□";
				}
				else if (_map[i][j] == (char)TILE::Imprint)
				{
					SetColor(COLOR::LIGHT_YELLOW);
					cout << "▣";
					SetColor();
				}
			}
		}
		cout << endl;
		Gotoxy(40, 15 + i + 1);
	}
	
	
}


vector<vector<char>> GameScene::GetMap()
{
	return _map;
}

void GameScene::SetMap() 
{
	std::ifstream mapFile("Stage" + std::to_string(stage) + ".txt");
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

void GameScene::Restart()
{
	delete _player;
	_player = nullptr;
	Init();
}


