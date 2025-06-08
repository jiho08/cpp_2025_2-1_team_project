#include "GameScene.h"

void GameScene::Init()
{
}

void GameScene::Update()
{
}

void GameScene::Render()
{
}

void GameScene::SetMap() 
{
	std::ifstream mapFile("Stage.txt");
	if (mapFile.is_open())
	{
		for (int i = 0; i < MAX_HEIGHT; ++i)
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
