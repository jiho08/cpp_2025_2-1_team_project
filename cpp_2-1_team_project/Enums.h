#pragma once

enum Scene 
{
	Title,
	Game,
	Setting,
	Exit,
	End
};

enum class Menu
{
	Start,
	Info,
	Quit,
	Fail,
	End
};

enum class Key
{
	W,
	A,
	S,
	D,
	End
};

enum class Tile
{
	Wall = '0',
	Road,
	Start,
	Goal,
	End
};