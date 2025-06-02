#pragma once
#include "Enums.h"

class Core
{
public:
	void Run();

private:
	void Update();

	void Render();

public:
	Scene currentScene = Scene::Title;
};