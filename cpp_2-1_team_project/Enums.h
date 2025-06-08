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
	// 기본
	Road = '0', // "길"
	Start = '1', // 스테이지 시작 시 플레이어 시작점
	Imprint, // 플레이어가 지나간 길 표시
	Goal, // 스테이지 목표 지점 (사실 없는게 더 나을 것 같긴 함)

	// 기믹
	Wall, // 플레이어가 통과 할 수 없는 벽
	End
};

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};