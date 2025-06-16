#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Console.h"
#include "defines.h"
#include "Enums.h"
#include "IScene.h"
#include "Player.h"
using std::cout;
using std::endl;
using std::vector;


class GameScene : public IScene
{
public:
	GameScene();
	int stage = 1;
	void Init() override;
	void Update() override;
	void Render() override;
	vector<vector<char>> GetMap();

	vector<vector<char>> _map;
	Position startPos;
	Player* _player;
	void SetMap();
	//void GameClear();
	void Restart();
};

