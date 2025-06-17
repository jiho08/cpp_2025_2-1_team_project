#include "Player.h"
#include "Console.h"

Player::Player(Position pos) : Object(pos)
{

}

Position Player::GetPos() const
{
	return _pos;
}

wchar_t Player::GetSymbol() const
{
	return _playerSymbol;
}

void Player::Update()
{

}

void Player::Render() const
{
	Gotoxy(_pos.x, _pos.y);
	wcout << GetSymbol();
}

void Player::Move(DIR dir)
{
	switch (dir)
	{
	case DIR::UP:
		--_pos.y;
		break;

	case DIR::DOWN:
		++_pos.y;
		break;

	case DIR::LEFT:
		--_pos.x;
		break;

	case DIR::RIGHT:
		++_pos.x;
		break;
	}
}

void Player::SetPosition(Position newPos)
{
}