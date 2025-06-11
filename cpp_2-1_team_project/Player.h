#pragma once
#include "Structs.h"

class Player
{
private:
	Position _position;
	wchar_t _playerSymbol = L'��';

public:
	Player();
	Player(Position startPos);

	~Player();

	Position GetPos() const;
};