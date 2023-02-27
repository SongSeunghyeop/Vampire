#include "myInput.h"

namespace my
{
	int ASCII[(UINT)eKeyCode::END]
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_ESCAPE ,VK_RETURN , VK_SPACE ,
	};

	std::vector<Input::Key> Input::mKeys = { };

	void Input::Initialize()
	{
		for (int i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key keyInfo;
			keyInfo.Kcode = (eKeyCode)i;
			keyInfo.Kstate = eKeyState::None;
			keyInfo.bePressed = false;

			mKeys.push_back(keyInfo);
		}
	}
	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) && 0x8000) // i번째 키가 입력되었을 때
			{
				if (mKeys[i].bePressed) //그 키가 이전에 입력되어있는 상태라면 
					mKeys[i].Kstate = eKeyState::Pressed;
				else
					mKeys[i].Kstate = eKeyState::Down;

				mKeys[i].bePressed = true;
			}
			else  // i번째 키가 입력되어지지 않았다면
			{
				if (mKeys[i].bePressed) //그 키가 이전에 입력되어있는 상태라면 
					mKeys[i].Kstate = eKeyState::Up; // 이전에 입력되어져 있었다면 키를 뗀 것이므로
				else // 그게 아니라면
					mKeys[i].Kstate = eKeyState::None;

				mKeys[i].bePressed = false;
			}

		}
	}
	void Input::Render(HDC hdc)
	{

	}
}