#pragma once
#include "Enums.h"
#include "Scene.h"
#include "Structs.h"

class StageClearScene : public Scene
{
	// n �������� Ŭ����
	// ���� ����������
	// �κ��
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
