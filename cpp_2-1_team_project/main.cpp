#include "SceneManager.h"
#include "TitleScene.h"

int main()
{
	SceneManager::GetInstance()->ChangeScene(new TitleScene());

	while (true)
	{
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Render();
	}

	SceneManager::DestroyInstance();
}