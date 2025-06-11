#include "SceneManager.h"
#include "TitleScene.h"
#include "Console.h"

int main()
{
	SetConsoleSettings(800, 600, false, TEXT("2-1 Team Project"));
	SetCursorVisual(false, 50);

	SceneManager::GetInstance()->ChangeScene(new TitleScene());

	while (true)
	{
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Render();
	}

	SceneManager::DestroyInstance();
}