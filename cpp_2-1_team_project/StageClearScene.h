#pragma once
#include "Enums.h"
#include "Scene.h"
#include "Structs.h"

class StageClearScene : public Scene
{
	// n 스테이지 클리어
	// 다음 스테이지로
	// 로비로
public:
	StageClearScene(int clearStage);
	~StageClearScene() override;

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
