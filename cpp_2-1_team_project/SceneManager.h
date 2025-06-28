#pragma once
#include "defines.h"
#include "Scene.h"
#include "Singleton.h"
#pragma comment(lib, "winmm.lib")

class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton;

	SceneManager() : _pCurrentScene(nullptr) {}
	~SceneManager() { SAFE_DELETE(_pCurrentScene); }

	Scene* _pCurrentScene;

public:
	void Init();
	void Update() const;
	void Render() const;
	void ChangeScene(Scene* newScene);
};