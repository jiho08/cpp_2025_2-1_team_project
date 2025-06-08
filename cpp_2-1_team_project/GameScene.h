#pragma once
#include <string>
#include <fstream>
#include <iostream>
using std::cout;
#define MAX_WIDTH 6
#define MAX_HEIGHT 6

class GameScene
{
public:
	void Init();
	void Update();
	void Render();
private:
	char _map[MAX_HEIGHT][MAX_WIDTH];
	void SetMap();

};

