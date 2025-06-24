#pragma once
#include "Scene.h"
#include "GameScene.h"

class TitleScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	void SelectMenu();
	void StartCurrentMenu() const;

	int _resX, _resY;
	int _menuBtnX = 2;
	int _menuBtnY = 20;
	Position _consoleSize;
	MENU _currentMenu;
};