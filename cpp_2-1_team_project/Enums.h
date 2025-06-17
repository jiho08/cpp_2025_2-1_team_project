#pragma once

enum SCENE 
{
	Title,
	Game,
	Setting,
	Exit,
	End
};

enum class MENU
{
	Start,
	Info,
	Quit,
	Fail,
	End
};

enum class KEY
{
	W,
	A,
	S,
	D,
	SPACE,
	Fail,
	End
};

enum class TILE
{
	// 기본
	Road = '0', // "길"
	Start = '1', // 스테이지 시작 시 플레이어 시작점
	Imprint, // 플레이어가 지나간 길 표시

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

enum class DIR
{
	UP, DOWN, LEFT, RIGHT
};