#include "InputHandler.h"
#include <Windows.h>
#include "MoveCommand.h"

InputHandler::InputHandler()
{
	_keys.push_back({ 'W', Dir::UP });
	_keys.push_back({ 'S', Dir::DOWN });
	_keys.push_back({ 'A', Dir::LEFT });
	_keys.push_back({ 'D', Dir::RIGHT });
}

ICommand* InputHandler::HandleInput()
{
	// 입력처리 -> command를 반환

	for (const auto& key : _keys)
	{
		const bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;

		if (isDown)
			return new MoveCommand(key.dir);
	}

	Sleep(30);
	return nullptr;
}