#pragma once
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

class Player : public Object, public IMovable
{
	Position _position;
	wchar_t _playerSymbol = L'¢Ã';

public:
	Player(Position startPos = {0, 0});

	Position GetPos() const;
	wchar_t GetSymbol() const;

public:
	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;
	void SetPosition(Position newPos);
};