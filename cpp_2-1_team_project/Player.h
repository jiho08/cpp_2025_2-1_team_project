#pragma once
#include <string>
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

using std::string;

class Player : public Object, public IMovable
{
	string _playerSymbol = "¢Ã";

public:
	Player(Position startPos = { 0, 0 });

	Position GetPos() const;
	string GetSymbol() const;
	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;
	void SetPosition(Position newPos);
};