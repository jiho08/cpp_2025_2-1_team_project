#include "SceneManager.h"
#include "TitleScene.h"

void SceneManager::Init()
{
	pCurrentScene = new TitleScene();
	pCurrentScene->Init();
}

void SceneManager::Update()
{
	pCurrentScene->Update();
}

void SceneManager::Render()
{
	pCurrentScene->Render();
}

void SceneManager::ChangeScene(IScene* newScene)
{
	pCurrentScene = newScene;
	pCurrentScene->Init();
}