#include "MoveCommand.h"
#include "Imovable.h"
#include "Object.h"

MoveCommand::MoveCommand(DIR dir) : _dir(dir)
{
}

void MoveCommand::Execute(Object* actor)
{
	IMovable* mover = dynamic_cast<IMovable*>(actor);

	if (mover)
		mover->Move(_dir);
}