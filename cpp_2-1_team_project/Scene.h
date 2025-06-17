#pragma once

class Scene
{
public:
	virtual ~Scene() {}
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;

};