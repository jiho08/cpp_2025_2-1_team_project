#pragma once
#include "IScene.h"
#include <iostream>
#include <fstream>
#include<io.h>
#include<fcntl.h>

class TitleScene : public IScene
{
public:
	void Init();
	void Update() override;
	void Render();


};