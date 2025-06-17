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

void Player::Move(Dir dir)
{
	switch (dir)
	{
	case Dir::UP:
		--_pos.y;
		break;

	case Dir::DOWN:
		++_pos.y;
		break;

	case Dir::LEFT:
		--_pos.x;
		break;

	case Dir::RIGHT:
		++_pos.x;
		break;
	}
}

void Player::SetPosition(Position newPos)
{
}