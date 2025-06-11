#pragma once
#include "IScene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "InfoScene.h"
#include<iostream>
#include<fstream>
#include<io.h>
#include <fcntl.h>


class TitleScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	int menuBtnX = 35;
	int menuBtnY = 10;
	Menu _currentMenu;
	void SelectMenu();
	void StartCurrentMenu();

};