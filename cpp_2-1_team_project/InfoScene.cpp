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
	cout << "R : 재시작";
	Gotoxy(42, 7);
	cout << "ESC : 나가기";
	Gotoxy(23, 10);
	cout << "게임 규칙 : 블럭을 이동하여 맵에 모든 빈칸을 다 채우세요.";
	Gotoxy(35, 11);
	cout << "맵에 있는 빈칸은 '□'로 표시되어 있습니다.";
	Gotoxy(35, 12);
	cout << "빈칸을 채우면'";
	SetColor(COLOR::LIGHT_YELLOW);
	cout << "▣";
	SetColor();
	cout << "'로 표시됩니다.";
	Gotoxy(35, 13);
	cout << "빈칸을 모두 채우면 게임이 클리어됩니다.";
	Gotoxy(35, 14);
	cout << "벽은 통과 할 수 없으며'■'로 표시되어 있습니다.";
	Gotoxy(42, 16);
	cout << "한번 잘 해보세요ㅋ";
}

void InfoScene::Exit()
{

	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}

