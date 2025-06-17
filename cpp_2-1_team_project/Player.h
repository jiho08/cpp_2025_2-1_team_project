#pragma once
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"
#include<string>
using std::string;

class Player : public Object, public IMovable
{
	Position _position;
	string _playerSymbol = "¡Ü";

public:
	Player(Position startPos = {0, 0});

	Position GetPos() const;
	string GetSymbol() const;

public:
	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;
	void SetPosition(Position newPos);
};