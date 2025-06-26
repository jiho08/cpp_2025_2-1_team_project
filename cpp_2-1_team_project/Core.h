#pragma once
#include <Windows.h> 
#include <mmsystem.h>
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

private:
	void Init();
	void Update();
	void Render();

private:
	bool _isRunning;
	InputHandler* _inputHandler;
	Position _resolution;
};