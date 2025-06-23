#pragma once
#include "Scene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "Console.h"
#include "TitleScene.h"
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
class InfoScene : public Scene
{
public:
	InfoScene() {};
	void Init() override;
	void Update() override;
	void Render() override;
private:
	KEY _input;
	void Exit();
};
