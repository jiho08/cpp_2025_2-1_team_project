#include "GameScene.h"

GameScene::GameScene()
{
	_player = nullptr;
	startPos = { 0, 0 };
	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
}

void GameScene::Init()
{
	system("cls");
	SetMap();
	_player = new Player(startPos);
}

void GameScene::Update()
{
	Render();
}

void GameScene::Render()
{
	Gotoxy(0, 0);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			Position currentPos = Position(i, j);
			if (_player->GetPos() == currentPos)
			{
				_map[i][j] = '2';
				cout << "▣";
			}
			else 
			{
				if (_map[i][j] == (char)Tile::Wall)
				{
					SetColor(COLOR::BLACK, COLOR::BLACK);
					cout << "■";
					SetColor();
				}
				else if (_map[i][j] == (char)Tile::Road)
					cout << "□";
				else if (_map[i][j] == (char)Tile::Start)
				{
					startPos = { i, j };
					_map[i][j] = '0';
					cout << "□";
				}
				else if (_map[i][j] == (char)Tile::Imprint)
				{
					SetColor(COLOR::LIGHT_YELLOW, COLOR::LIGHT_YELLOW);
					cout << "▣";
					SetColor();
				}
			}

			
			
			
		}
		cout << endl;
	}
	Gotoxy(0, 7);
	cout << "Stage: " << stage << endl;
	
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


