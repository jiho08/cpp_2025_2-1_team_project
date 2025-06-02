#include "Core.h"
#include "Enums.h"
void Core::Run()
{
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

