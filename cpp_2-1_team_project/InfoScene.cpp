#include "InfoScene.h"

void InfoScene::Init()
{
	system("cls");
}

void InfoScene::Update()
{
	_input = KeyController();

	if (_input == KEY::ESC)
	{
		Exit();
	}
}

void InfoScene::Render()
{
	Gotoxy(42, 5);
	cout << "WASD : 이동";
	Gotoxy(42, 6);
	cout << "C : 색깔 변경";
	Gotoxy(42, 7);
	cout << "R : 재시작";
	Gotoxy(42, 8);
	cout << "ESC : 나가기";
	Gotoxy(13, 11);
	cout << "게임 규칙 : 블럭을 이동하여 맵에 모든 빈칸을 옆에 있는 맵과 일치하게 모두 채우세요.";
	Gotoxy(25, 13);
	cout << "맵에 있는 빈칸은 '□'로 표시되어 있습니다.";
	Gotoxy(25, 14);
	cout << "플레이어가 지나간 칸은 색칠 됩니다.";
	Gotoxy(25, 15);
	cout << "빈칸을 채우면 현재 선택된 색깔의'";
	cout << "▣";
	cout << "'으로 표시됩니다.";
	Gotoxy(25, 16);
	cout << "빈칸을 옆에 있는 맵과 일치하게 모두 채우면 게임이 클리어됩니다.";
	Gotoxy(25, 18);
	cout << "벽은 통과 할 수 없으며'■'로 표시되어 있습니다.";
	Gotoxy(25, 19);
	cout << "이미 색칠된 곳도 통과 할 수 없습니다.";
}

void InfoScene::Exit()
{

	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}

