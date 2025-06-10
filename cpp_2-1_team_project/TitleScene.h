#pragma once
#include "IScene.h"
#include "KeyController.h"
#include<iostream>
#include<fstream>
#include<io.h>
#include <fcntl.h>


class TitleScene : public IScene
{
public:
	void Init();
	void Update() override;
	void Render();
private:
	int menuBtnX = 35;
	int menuBtnY = 10;
	Menu _currentMenu;
	void SelectMenu();

};