#pragma once
#include "Enums.h"
#include "Scene.h"
#include "Structs.h"

class Object;
class InputHandler;

class Core
{
public:
	Core();
	~Core();

public:
	void Run();
	void SetCurrentScene(Scene* scene) { _currentScene = scene; };

private:
	void Init();
	void Update();
	void Render();

private:
	bool _isRunning;
	Object* _player;
	InputHandler* _inputHandler;
	Position _resolution;
	Scene* _currentScene;
};