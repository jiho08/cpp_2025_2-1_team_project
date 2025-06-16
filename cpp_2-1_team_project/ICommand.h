#pragma once

class Object;

class ICommand
{
public:
	virtual ~ICommand() = default;
	virtual void Execute(Object* actor) abstract;
};