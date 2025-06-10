#pragma once

class SceneManager; // 전방 선언

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};