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
	const Position& GetPos() const { return _pos; }

protected:
	Position _pos;
};