#pragma once

class SceneManager; // ���� ����

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};