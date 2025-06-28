#pragma once
#include <string>
#include <vector>
#include <array>
#include <stack>
#include "Object.h"
#include "Structs.h"
#include "IMovable.h"

using std::string;
using std::vector;
using std::array;
using std::stack;

class Player final : public Object, public IMovable
{
	string _playerSymbol = "¢Ã";
	int _currentColorIndex;
	const vector<vector<char>>* _map;
	array<COLOR, 3> _colorList;
	stack<Position> _moveHistory;

public:
	Player(Position pos = { 0, 0 });

	void Update() override;
	void Render() const override;
	void Move(DIR dir) override;

	void ChangeColor();
	void UndoMove();

	string GetSymbol() const;
	COLOR GetColor() const;

	void SetPosition(Position newPos);
	void SetColor(COLOR newColor);
	void SetMap(const vector<vector<char>>* map);
};