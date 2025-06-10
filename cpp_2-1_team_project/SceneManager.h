#pragma once
#include "defines.h"
#include "IScene.h"
#include "Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton;

protected:
	SceneManager() : pCurrentScene(nullptr) {}
	~SceneManager() { SAFE_DELETE(pCurrentScene); }

	IScene* pCurrentScene;

public:
	void Init();
	void Update();
	void Render();
	void ChangeScene(IScene* newScene);
};