#pragma once
#include <vector>
#include "Enums.h"

class ICommand;

struct InputKey
{
	int vk;
	Dir dir;
};

class InputHandler
{
public:
	InputHandler();

public:
	ICommand* HandleInput();
	std::vector<InputKey> _keys;
};