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
	cout << "R : �����";
	Gotoxy(42, 7);
	cout << "ESC : ������";
	Gotoxy(23, 10);
	cout << "���� ��Ģ : ���� �̵��Ͽ� �ʿ� ��� ��ĭ�� �� ä�켼��.";
	Gotoxy(35, 11);
	cout << "�ʿ� �ִ� ��ĭ�� '��'�� ǥ�õǾ� �ֽ��ϴ�.";
	Gotoxy(35, 12);
	cout << "��ĭ�� ä���'";
	SetColor(COLOR::LIGHT_YELLOW);
	cout << "��";
	SetColor();
	cout << "'�� ǥ�õ˴ϴ�.";
	Gotoxy(35, 13);
	cout << "��ĭ�� ��� ä��� ������ Ŭ����˴ϴ�.";
	Gotoxy(35, 14);
	cout << "���� ��� �� �� ������'��'�� ǥ�õǾ� �ֽ��ϴ�.";
	Gotoxy(42, 16);
	cout << "�ѹ� �� �غ����䤻";
}

void InfoScene::Exit()
{

	SceneManager::GetInstance()->ChangeScene(new TitleScene());
	delete this;
}

