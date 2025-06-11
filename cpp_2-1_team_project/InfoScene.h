#pragma once
#include "IScene.h"
class InfoScene : public IScene
{
public:
	InfoScene() {};
	void Init() override;
	void Update() override;
	void Render() override;
};

