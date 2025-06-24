#pragma once
#include <string>
#include <vector>
#include <array>
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

using std::string;
using std::vector;
using std::array;

class Player final : public Object, public IMovable
{
	string _playerSymbol = "¢Æ ";
	int _currentColorIndex;
	const vector<vector<char>>* _map;
	array<COLOR, 3> _colorList;

public:
	Player(Position pos = { 0, 0 });

	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;

	void ChangeColor();
	
	string GetSymbol() const;
	COLOR GetColor() const;

	void SetPosition(Position newPos);
	void SetColor(COLOR newColor);
	void SetMap(const vector<vector<char>>* map);
};