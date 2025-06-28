#pragma once
#include "Scene.h"
#include "TitleScene.h"
#include <iostream>

using std::cout;
using std::endl;

class InfoScene final : public Scene
{
public:
	InfoScene() {}

	void Init() override;
	void Update() override;
	void Render() override;

private:
	void Exit();

	KEY _input;
};