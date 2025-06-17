#pragma once

class Scene
{
public:
	virtual ~Scene() {}
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual Scene* GetScene() const abstract;

protected:
	Scene* _nextScene;
};