#pragma once
#include "Enums.h"
#include "ICommand.h"

class MoveCommand : public ICommand
{
public:
	MoveCommand(DIR dir);
	void Execute(Object* actor) override;

private:
	DIR _dir;
};