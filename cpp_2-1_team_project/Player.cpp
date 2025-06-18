#include "Player.h"
#include <algorithm>
#include "Console.h"
#include "defines.h"
#include "KeyController.h"

Player::Player(const Position pos) : Object(pos), _currentColor(COLOR::WHITE),_map(nullptr)
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

void Player::SetColor(const COLOR newColor)
{
	_currentColor = newColor;
}

void Player::SetMap(const vector<vector<char>>* map)
{
	_map = map;
}

void Player::Update()
{
	switch (KEY input = KeyController())
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

void Player::Move(const DIR dir)
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

	if (newPos.x < 0 || newPos.x >= MAP_WIDTH || newPos.y < 0 || newPos.y >= MAP_HEIGHT)
		return;

	if ((*_map)[newPos.y][newPos.x] != static_cast<char>(TILE::Road))
		return;

	_pos = newPos;
}

void Player::SetPosition(const Position newPos)
{
	_pos = newPos;
}