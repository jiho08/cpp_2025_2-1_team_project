#include "GameScene.h"
#include "KeyController.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include <filesystem>
#include "Console.h"
#include "defines.h"
#include <string>
#include <fstream>

GameScene::GameScene(int _selectStage) : _startPos({ 0,0 }), _player(nullptr), _stage(_selectStage)
{
	_map = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
	_completeMap = vector(MAP_HEIGHT, vector<char>(MAP_WIDTH));
}

GameScene::~GameScene()
{
	SAFE_DELETE(_player)
}

void GameScene::Init()
{
	system("cls");

	
	SetMap();
	Render();
	RenderCompleteMap();
	_player = new Player(_startPos);
	_player->SetMap(&_map);
	_player->SetColor(COLOR::LIGHT_YELLOW);
}

void GameScene::Update()
{
	_player->Update();

	_input = KeyController();

	if (_input == KEY::ESC) 
	{
		Exit();
		SceneManager::GetInstance()->ChangeScene(new TitleScene());
	}
	if(_input == KEY::R)
	{
		Restart();
	}
		
}

void GameScene::Render()
{
	Gotoxy(42, 8);
	cout << "Stage: " << _stage << '\n';

	Gotoxy(40, 15);

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			Position currentPos = { j, i };

			if (_player != nullptr && _player->GetPos() == currentPos)
			{
				_map[i][j] = '2';
				cout << _player->GetSymbol();
			}
			else
				if (_map[i][j] == static_cast<char>(TILE::Wall))
				{
					SetColor(COLOR::WHITE, COLOR::WHITE);
					cout << "■";
					SetColor();
				}
				else if (_map[i][j] == static_cast<char>(TILE::Road))
					cout << "□";
				else if (_map[i][j] == static_cast<char>(TILE::Start))
				{
					_startPos = { j, i };
					_map[i][j] = '0';
					cout << "□";
				}
				else if (_map[i][j] == static_cast<char>(TILE::Imprint))
				{
					SetColor(_player->GetColor());
					cout << "▣";
					SetColor();
					switch (_player->GetColor())
					{
						case COLOR::RED:
							_map[i][j] = '4';
							break;
						case COLOR::GREEN:
							_map[i][j] = '5';
							break;
						case COLOR::BLUE:
							_map[i][j] = '6';
							break;

					}

				}
		}

		cout << '\n';
		Gotoxy(40, 15 + i + 1);
	}
}

vector<vector<char>> GameScene::GetMap()
{
	return _map;
}

void GameScene::RenderCompleteMap()
{
	Gotoxy(60, 15);

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
				if (_completeMap[i][j] == static_cast<char>(TILE::Wall))
				{
					SetColor(COLOR::WHITE, COLOR::WHITE);
					cout << "■";
					SetColor();
				}
				else if (_completeMap[i][j] == static_cast<char>(TILE::Road))
					cout << "□";
				else if (_completeMap[i][j] == static_cast<char>(TILE::Start))
				{
					_completeMap[i][j] = '0';
					cout << "□";
				}
				else if (_completeMap[i][j] == static_cast<char>(TILE::Red))
				{
					SetColor(COLOR::RED);
					cout << "▣";
					SetColor();
				}
				else if (_completeMap[i][j] == static_cast<char>(TILE::Green))
				{
					SetColor(COLOR::GREEN);
					cout << "▣";
					SetColor();
				}
				else if (_completeMap[i][j] == static_cast<char>(TILE::Blue))
				{
					SetColor(COLOR::BLUE);
					cout << "▣";
					SetColor();
				}
		}

		cout << '\n';
		Gotoxy(60, 15 + i + 1);
	}
}

void GameScene::SetMap()
{
	std::ifstream mapFile("Stage" + std::to_string(_stage) + ".txt");

	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
			mapFile.getline(_map[i].data(), MAP_WIDTH + 1);

		mapFile.close();
	}
	
	std::ifstream completeMapFile("CompleteStage" + std::to_string(_stage) + ".txt");

	if (completeMapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
			completeMapFile.getline(_completeMap[i].data(), MAP_WIDTH + 1);

		completeMapFile.close();
	}
}

void GameScene::Restart()
{
	delete _player;
	_player = nullptr;
	Init();
}

void GameScene::Exit()
{
	/*std::ofstream outFile("highStage.txt");

	if (outFile.is_open())
	{
		outFile << _stage;
		outFile.close();
		return;
	}

	cout << "파일을 열 수 없습니다.\n";*/
}