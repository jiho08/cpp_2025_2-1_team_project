#pragma once
#include "Scene.h"
#include "Enums.h"
#include<iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class StageSelectScene final : public Scene
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