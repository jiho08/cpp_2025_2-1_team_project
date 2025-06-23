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
	R,
	SPACE,
	ESC,
	Fail,
	End
};

enum class TILE
{
	// �⺻
	Road = '0', // "��"
	Start = '1', // �������� ���� �� �÷��̾� ������
	Imprint, // �÷��̾ ������ �� ǥ��

	// �� & ����
	Wall, // �÷��̾ ��� �� �� ���� ��
	Red = '4',
	Green,
	Blue,
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