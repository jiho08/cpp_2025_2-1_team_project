#pragma once
#include "IScene.h"

class SceneManager
{
	IScene* pCurrentScene;
	// player �� ������

public:
	void Init();
	void Run();
	void ChangeScene(IScene* newScene);
	void Quit();

	// getter ��e����⤿
};