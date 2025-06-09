#include "Core.h"
#include "Enums.h"
#include "Console.h"

void Core::Run()
{
	Console console = Console();
	console.SetConsoleSettings(800, 600, true, TEXT("2-1 Team Project"));
	while (true)
	{
		Update();
		Render();
		// FrameSync
	}
}

void Core::Update()
{
	switch (currentScene)
	{
	case Title:

		break;
	case Game:
		break;
	case Setting:
		break;
	case Exit:
		break;
	}
}

void Core::Render()
{

}

