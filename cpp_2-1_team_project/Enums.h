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

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};