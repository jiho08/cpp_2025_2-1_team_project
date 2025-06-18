#pragma once
#include <string>
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

using std::string;

class Player : public Object, public IMovable
{
	string _playerSymbol = "¢Ã";
	COLOR _currentColor;

public:
	Player(Position startPos = { 0, 0 });

	string GetSymbol() const;
	COLOR GetColor() const;
	void SetColor(COLOR newColor);
	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;
	void SetPosition(Position newPos);
};