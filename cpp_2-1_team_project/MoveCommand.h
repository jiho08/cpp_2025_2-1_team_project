#pragma once
#include "Enums.h"
#include "ICommand.h"

class MoveCommand : public ICommand
{
public:
	MoveCommand(Dir dir);
	void Execute(Object* actor) override;

private:
	Dir _dir;
};