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

	void Init() override;
	void Update() override;
	void Render() override;

	void SetMap();
	//void GameClear();
	void Restart();
	void Exit();

	vector<vector<char>> GetMap();

private:
	vector<vector<char>> _map;
	vector<vector<char>> _completeMap;
	Position _startPos;
	Player* _player;
	KEY _input;
	int _stage;
	void RenderCompleteMap();
};