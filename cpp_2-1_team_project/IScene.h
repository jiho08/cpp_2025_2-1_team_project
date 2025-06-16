#pragma once

class IScene
{
public:
	virtual ~IScene() {}
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render() abstract;
};