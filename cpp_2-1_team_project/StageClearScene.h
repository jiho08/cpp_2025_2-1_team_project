#pragma once
#include "Enums.h"
#include "Scene.h"
#include "Structs.h"

class StageClearScene final : public Scene
{
public:
	StageClearScene(int clearStage);

	void Init() override;
	void Update() override;
	void Render() override;

private:
	int _clearStage;
	int _resX, _resY;
	int _menuBtnX = 2;
	int _menuBtnY = 20;
	int _currentColor;
	Position _consoleSize;
	CLEARMENU _currentMenu = CLEARMENU::LOBBY;
};
