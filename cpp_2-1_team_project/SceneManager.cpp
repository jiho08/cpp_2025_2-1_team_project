#include "SceneManager.h"
#include "TitleScene.h"

void SceneManager::Init()
{
	pCurrentScene = new TitleScene();
	pCurrentScene->Init();
}

void SceneManager::Run()
{
	pCurrentScene->Update();
}

void SceneManager::ChangeScene(IScene* newScene)
{
}

void SceneManager::Quit()
{
}
