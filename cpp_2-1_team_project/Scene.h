#pragma once

class Scene
{
public:
	virtual ~Scene() = default;
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
};