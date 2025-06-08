#pragma once
#include "IScene.h"

class TitleScene : public IScene
{
public:
	void Update(SceneManager& sceneManager) override;
};