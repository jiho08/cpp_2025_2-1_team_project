#pragma once
#include "Structs.h"

class Object
{
public:
	Object(Position pos = { 0,0 });
	virtual ~Object() = default;

public:
	virtual void Update() abstract;
	virtual void Render() const abstract;

public:
	const Position& GetPos() const { return _pos; }

	//public:
	//	void Move(Dir dir);

protected:
	Position _pos;
};
