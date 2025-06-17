#include "Player.h"
#include "Console.h"
#include "KeyController.h"

Player::Player(Position pos) : Object(pos)
{

}

Position Player::GetPos() const
{
	return _pos;
}

string Player::GetSymbol() const
{
	return _playerSymbol;
}

void Player::Update()
{
	KEY input = KeyController();
	switch (input)
	{
	case KEY::W:
		Move(DIR::UP);
		break;
	case KEY::A:
		Move(DIR::LEFT);
		break;
	case KEY::S:
		Move(DIR::DOWN);
		break;
	case KEY::D:
		Move(DIR::RIGHT);
		break;
	}
	
}

void Player::Render() const
{
	Gotoxy(_pos.x, _pos.y);
	/*wcout << GetSymbol();*/
	cout << "¢Ã";
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