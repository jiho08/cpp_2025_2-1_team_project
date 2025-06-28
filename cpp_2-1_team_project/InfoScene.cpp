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
	cout << "WASD : �̵�";

	Gotoxy(42, 6);
	cout << "C : �� ����";

	Gotoxy(42, 7);
	cout << "R : �����";

	Gotoxy(42, 8);
	cout << "Z : �ǵ�����";

	Gotoxy(42, 9);
	cout << "ESC : ������";

	Gotoxy(10, 12);
	cout << "���� ��Ģ : �÷��̾ �̵����� �ʿ� ��� ��ĭ�� ���õ� �ʰ� ��ġ�ϰ� ��� ä�켼��.";

	Gotoxy(22, 14);
	cout << "�ʿ� �ִ� ��ĭ�� '��'�� ǥ�õǾ� �ֽ��ϴ�.";

	Gotoxy(22, 15);
	cout << "�÷��̾ ������ ĭ�� ���� �÷��̾��� ������ ��ĥ�˴ϴ�.";

	Gotoxy(22, 16);
	cout << "��ĥ�� ĭ�� '�� ' ���� ǥ�õ˴ϴ�.";

	Gotoxy(22, 17);
	cout << "��ĭ�� ���� �ִ� �ʰ� ��ġ�ϰ� ��� ä��� ���������� Ŭ����˴ϴ�.";

	Gotoxy(22, 19);
	cout << "���� ��� �� �� ������ '��' �� ǥ�õǾ� �ֽ��ϴ�.";

	Gotoxy(22, 20);
	cout << "����, �̹� ��ĥ�� ���� ����� �� �����ϴ�.";
}

void InfoScene::Exit()
{
	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}