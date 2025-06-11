#include "SceneManager.h"
#include "TitleScene.h"

void SceneManager::Init()
{
	_pCurrentScene = new TitleScene();
	_pCurrentScene->Init();
}

void SceneManager::Update()
{
	_pCurrentScene->Update();
}

void SceneManager::Render()
{
	_pCurrentScene->Render();
}

void SceneManager::ChangeScene(IScene* newScene)
{
	_pCurrentScene = newScene;
	_pCurrentScene->Init();
}