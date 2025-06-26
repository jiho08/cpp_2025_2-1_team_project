#pragma once
#include "defines.h"
#include "Scene.h"
#include "Singleton.h"
#include <Windows.h> 
#include <mmsystem.h>
#include<iostream>
#pragma comment(lib, "winmm.lib")
class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton;

	SceneManager() : _pCurrentScene(nullptr) {}
	~SceneManager() { SAFE_DELETE(_pCurrentScene); }

	Scene* _pCurrentScene;

public:
	void Init();
	void Update();
	void Render();
	void ChangeScene(Scene* newScene);
};