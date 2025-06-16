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
	SPACE,
	Fail,
	End
};

enum class Tile
{
	// �⺻
	Road = '0', // "��"
	Start = '1', // �������� ���� �� �÷��̾� ������
	Imprint, // �÷��̾ ������ �� ǥ��

	// ���
	Wall, // �÷��̾ ��� �� �� ���� ��
	End
};

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};

enum class Dir
{
	UP, DOWN, LEFT, RIGHT
};