#pragma once
#include <string>
#include <vector>
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

using std::string;
using std::vector;

class Player final : public Object, public IMovable
{
	string _playerSymbol = "¢Ã";
	COLOR _currentColor;
	const vector<vector<char>>* _map;

public:
	Player(Position pos = { 0, 0 });

	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;

	void SetPosition(Position newPos);

	string GetSymbol() const;
	COLOR GetColor() const;

	void SetColor(COLOR newColor);
	void SetMap(const vector<vector<char>>* map);
};