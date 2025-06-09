#pragma once

class SceneManager; // 전방 선언

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Update(SceneManager& sceneManager) abstract;
};