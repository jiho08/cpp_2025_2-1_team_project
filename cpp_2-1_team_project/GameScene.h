#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Console.h"
#include "defines.h"
#include "Enums.h"
#include "Scene.h"
#include "Player.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "TitleScene.h"
using std::cout;
using std::endl;
using std::vector;


class GameScene : public Scene
{
public:
	GameScene();

	~GameScene();
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

