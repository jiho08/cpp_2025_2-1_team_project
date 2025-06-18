#include "StageSelectScene.h"

void StageSelectScene::Init()
{
	std::ifstream mapFile("highStage.txt");
	if (mapFile.good())
	{
		if (mapFile.is_open())
		{
			mapFile >> highStage;
			mapFile.close();

		}
		else
		{
			highStage = 1;
		}

	}
	
}

void StageSelectScene::Update()
{

}

void StageSelectScene::Render()
{

}

void StageSelectScene::SetMap()
{
}
