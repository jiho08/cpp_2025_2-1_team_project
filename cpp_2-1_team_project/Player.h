#pragma once
#include "Structs.h"

class Player
{
	Position _position;
	wchar_t _playerSymbol = L'¢Ã';

public:
	Player();
	Player(Position startPos);

	~Player() = default;

	Position GetPos() const;
	wchar_t GetSymbol() const;

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void SetPosition(Position newPos);
};