#pragma once
#include "Scene.h"
class InfoScene : public Scene
{
public:
	InfoScene() {};
	void Init() override;
	void Update() override;
	void Render() override;

};
