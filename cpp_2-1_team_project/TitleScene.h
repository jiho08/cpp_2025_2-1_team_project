#pragma once
#include "Scene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "InfoScene.h"
#include<iostream>
#include<fstream>
#include<io.h>
#include <fcntl.h>


class TitleScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
	Scene* GetScene() const override;
private:
	int menuBtnX = 35;
	int menuBtnY = 10;
	MENU _currentMenu;
	void SelectMenu();
	void StartCurrentMenu();

};