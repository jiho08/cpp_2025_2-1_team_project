#pragma once
#include "Scene.h"
#include "defines.h"
#include "Enums.h"
#include "Console.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"

#include<iostream>
#include<fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class StageSelectScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	int _highStage = 1;
	int _currentStage = 1;
	KEY _input;
	vector<vector<char>> _map;

	void SetMap();
	void Exit();
};

