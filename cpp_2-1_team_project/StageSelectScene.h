#pragma once
#include "Scene.h"
#include<iostream>
#include<fstream>
using std::cout;
using std::endl;

class StageSelectScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	int highStage = 1;
	void SetMap();

};

