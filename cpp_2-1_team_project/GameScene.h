#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Console.h"
#include "defines.h"
#include "Enums.h"
#include "IScene.h"
using std::cout;
using std::endl;


class GameScene : public IScene
{
public:
	int stage = 1;
	void Init();
	void Update() override;
	void Render();
private:
	char _map[MAP_HEIGHT][MAP_WIDTH];
	void SetMap();

	Console console = Console();
};

