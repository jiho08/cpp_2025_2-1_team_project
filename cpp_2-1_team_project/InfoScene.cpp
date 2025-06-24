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
	cout << "WASD : �̵�";
	Gotoxy(42, 6);
	cout << "C : ���� ����";
	Gotoxy(42, 7);
	cout << "R : �����";
	Gotoxy(42, 8);
	cout << "ESC : ������";
	Gotoxy(13, 11);
	cout << "���� ��Ģ : ���� �̵��Ͽ� �ʿ� ��� ��ĭ�� ���� �ִ� �ʰ� ��ġ�ϰ� ��� ä�켼��.";
	Gotoxy(25, 13);
	cout << "�ʿ� �ִ� ��ĭ�� '��'�� ǥ�õǾ� �ֽ��ϴ�.";
	Gotoxy(25, 14);
	cout << "�÷��̾ ������ ĭ�� ��ĥ �˴ϴ�.";
	Gotoxy(25, 15);
	cout << "��ĭ�� ä��� ���� ���õ� ������'";
	cout << "��";
	cout << "'���� ǥ�õ˴ϴ�.";
	Gotoxy(25, 16);
	cout << "��ĭ�� ���� �ִ� �ʰ� ��ġ�ϰ� ��� ä��� ������ Ŭ����˴ϴ�.";
	Gotoxy(25, 18);
	cout << "���� ��� �� �� ������'��'�� ǥ�õǾ� �ֽ��ϴ�.";
	Gotoxy(25, 19);
	cout << "�̹� ��ĥ�� ���� ��� �� �� �����ϴ�.";
}

void InfoScene::Exit()
{

	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}

