#include "Player.h"

Player::Player(Position startPos)
{
	_position = startPos;
}

Position Player::GetPos() const
{
	return _position;
}

wchar_t Player::GetSymbol() const
{
	return _playerSymbol;
}

void Player::MoveUp()
{
	--_position.y;
}

void Player::MoveDown()
{
	++_position.y;
}

void Player::MoveLeft()
{
	--_position.x;
}

void Player::MoveRight()
{
	++_position.x;
}

void Player::SetPosition(Position newPos)
{
	_position = newPos;
}