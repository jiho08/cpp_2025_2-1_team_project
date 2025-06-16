#include "GameScene.h"
#include "KeyController.h"

GameScene::GameScene()
{
	_player = nullptr;
	startPos = { 0, 0 };
	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
}

GameScene::~GameScene()
{
	delete _player;
	_player = nullptr;
}

void GameScene::Init()
{
	system("cls");
	SetMap();
	Render();
	_player = new Player(startPos);
}

void GameScene::Update()
{
	Render();
	MovePlayer();
}

void GameScene::Render()
{
	Gotoxy(0, 0);
	cout << "Stage: " << stage << endl;
	Gotoxy(0, 2);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			Position currentPos = Position(i, j);
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

			if (_player->GetPos() == currentPos)
			{
				_map[i][j] = '2';
				Gotoxy(i, j);
				cout << "▣";
				
			}
		}
		cout << endl;
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

void GameScene::MovePlayer()
{
	input = KeyController();
	switch (input)
	{
	case Key::W:
		_player->MoveUp();
		break;
	case Key::A:
		_player->MoveLeft();
		break;
	case Key::S:
		_player->MoveDown();
		break;
	case Key::D:
		_player->MoveRight();
		break;
	default:
		break;
	}
}


