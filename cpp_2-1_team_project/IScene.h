#pragma once

class SceneManager; // ���� ����

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Update(SceneManager& sceneManager) abstract;
};