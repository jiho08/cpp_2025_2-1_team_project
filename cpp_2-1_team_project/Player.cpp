#include "Player.h"
#include "Console.h"
#include "defines.h"
#include "KeyController.h"
#include "SoundManager.h"

Player::Player(const Position pos) : Object(pos), _currentColorIndex(0),
                                     _map(nullptr), _colorList({ COLOR::RED, COLOR::GREEN, COLOR::BLUE })
{
}

string Player::GetSymbol() const
{
	return _playerSymbol;
}

COLOR Player::GetColor() const
{
	return _colorList[_currentColorIndex];
}

void Player::SetColor(const COLOR newColor)
{
	switch (newColor)
	{
	case COLOR::RED:
		_currentColorIndex = 0;
		break;

	case COLOR::GREEN:
		_currentColorIndex = 1;
		break;

	case COLOR::BLUE:
		_currentColorIndex = 2;
		break;
	}
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

	case KEY::C:
		ChangeColor();
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

	SoundManager::GetInstance()->Play(SOUNDID::MOVE);
	_moveHistory.push(_pos);
	_pos = newPos;
}

void Player::ChangeColor()
{
	SetColor(_colorList[++_currentColorIndex % 3]);
}

void Player::UndoMove()
{
	if (_moveHistory.empty())
		return;

	Position backPos = _moveHistory.top();
	_moveHistory.pop();

	SetPosition(backPos);
}

void Player::SetPosition(const Position newPos)
{
	_pos = newPos;
}