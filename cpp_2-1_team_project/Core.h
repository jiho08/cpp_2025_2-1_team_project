#pragma once
#include "Structs.h"

class Object;
class InputHandler;

class Core
{
public:
	Core();
	~Core() = default;

	void Run();

private:
	void Init();
	void Update();
	void Render();

	bool _isRunning;
	Position _resolution;
};