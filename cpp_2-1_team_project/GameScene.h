#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Console.h"
#include "defines.h"
#include "Enums.h"
#include "IScene.h"
#include "Player.h"
using std::cout;
using std::endl;


class GameScene : public IScene
{
public:
	int stage = 1;
	void Init() override;
	void Update() override;
	void Render() override;
private:
	char _map[MAP_HEIGHT+1][MAP_WIDTH+1];
	Position startPos;
	Player _player;
	void SetMap();
	//void GameClear();

};

