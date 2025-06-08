#pragma once
#include "IScene.h"

class SceneManager
{
	IScene* pCurrentScene;
	// player 등 가지기

public:
	void Init();
	void Run();
	void ChangeScene(IScene* newScene);
	void Quit();

	// getter 만eㄷ들기ㅏ
};