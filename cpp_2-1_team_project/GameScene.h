#pragma once
#include <vector>
#include <iostream>
#include "Enums.h"
#include "Scene.h"
#include "Player.h"

using std::cout;
using std::endl;
using std::vector;

class GameScene : public Scene
{
public:
	GameScene(int _selectStage);
	~GameScene() override;

	int stage = 1;
	void Init() override;
	void Update() override;
	void Render() override;
	vector<vector<char>> GetMap();

	vector<vector<char>> _map;
	Position startPos;
	Player* _player;
	KEY input;
	void SetMap();
	//void GameClear();
	void Restart();
	void Exit();
};

