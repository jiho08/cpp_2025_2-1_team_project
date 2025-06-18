#include "Player.h"
#include <algorithm>
#include "Console.h"
#include "defines.h"
#include "KeyController.h"

Player::Player(Position pos) : Object(pos)
{
}

string Player::GetSymbol() const
{
	return _playerSymbol;
}

COLOR Player::GetColor() const
{
	return _currentColor;
}

void Player::SetColor(COLOR newColor)
{
	_currentColor = newColor;
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
	cout << GetSymbol();
}

void Player::Move(DIR dir)
{
	Position newPos = _pos;

	switch (dir)
	{
	case DIR::UP:
		--newPos.y;
		break;

	case DIR::DOWN:
		++newPos.y;
		break;

	case DIR::LEFT:
		--newPos.x;
		break;

	case DIR::RIGHT:
		++newPos.x;
		break;
	}

	_pos.x = std::clamp(newPos.x, 0, MAP_WIDTH - 1);
	_pos.y = std::clamp(newPos.y, 0, MAP_HEIGHT - 1);
}

void Player::SetPosition(Position newPos)
{
}