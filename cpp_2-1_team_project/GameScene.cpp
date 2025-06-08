#include "GameScene.h"

void GameScene::Init()
{
	SetMap();
}

void GameScene::Update()
{
	Render();
}

void GameScene::Render()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			/*if (_player->position.tPos.x == j &&
				_player->position.tPos.y == i)
				cout << "§";
			else
			{
				if (_map[i][j] == (char)Tile::Wall)
					cout << "■";
				else if (_map[i][j] == (char)Tile::Road)
					cout << "  ";
				else if (_map[i][j] == (char)Tile::Start)
					cout << "☆";
				else if (_map[i][j] == (char)Tile::Goal)
					cout << "♨";
				else if (_map[i][j] == (char)Tile:Imprint)
					cout << "▣";
			}*/

			if (_map[i][j] == (char)Tile::Wall)
				cout << "■";
			else if (_map[i][j] == (char)Tile::Road)
				cout << "  ";
			else if (_map[i][j] == (char)Tile::Start)
				cout << "☆";
			else if (_map[i][j] == (char)Tile::Goal)
				cout << "♨";
			else if (_map[i][j] == (char)Tile::Imprint)
				cout << "▣";
		}
		cout << endl;
	}
	
	console.Gotoxy(50, 0);
	cout << "Stage: " << stage << endl;
}

void GameScene::SetMap() 
{
	std::ifstream mapFile("Stage" + std::to_string(stage) + ".txt");
	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile >> _map[i];
		}
		mapFile.close();
		return;
	}
	else
	{
		cout << "맵 파일을 열 수 없습니다.";

	}
}
