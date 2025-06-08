#include "SceneManager.h"
#include "TitleScene.h"

void SceneManager::Init()
{
	pCurrentScene = new TitleScene();
}
