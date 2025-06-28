#include "InfoScene.h"
#include "SoundManager.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "Console.h"

void InfoScene::Init()
{
	system("cls");
}

void InfoScene::Update()
{
	_input = KeyController();

	if (_input == KEY::ESC)
	{
		SoundManager::GetInstance()->Play(SOUNDID::BUTTON);
		Exit();
	}
}

void InfoScene::Render()
{
	Gotoxy(42, 5);
	cout << "WASD : 이동";

	Gotoxy(42, 6);
	cout << "C : 색 변경";

	Gotoxy(42, 7);
	cout << "R : 재시작";

	Gotoxy(42, 8);
	cout << "Z : 되돌리기";

	Gotoxy(42, 9);
	cout << "ESC : 나가기";

	Gotoxy(10, 12);
	cout << "게임 규칙 : 플레이어를 이동시켜 맵에 모든 빈칸을 제시된 맵과 일치하게 모두 채우세요.";

	Gotoxy(22, 14);
	cout << "맵에 있는 빈칸은 '□'로 표시되어 있습니다.";

	Gotoxy(22, 15);
	cout << "플레이어가 지나간 칸은 현재 플레이어의 색으로 색칠됩니다.";

	Gotoxy(22, 16);
	cout << "색칠된 칸은 '▒ ' 으로 표시됩니다.";

	Gotoxy(22, 17);
	cout << "빈칸을 옆에 있는 맵과 일치하게 모두 채우면 스테이지가 클리어됩니다.";

	Gotoxy(22, 19);
	cout << "벽은 통과 할 수 없으며 '■' 로 표시되어 있습니다.";

	Gotoxy(22, 20);
	cout << "또한, 이미 색칠된 곳도 통과할 수 없습니다.";
}

void InfoScene::Exit()
{
	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}