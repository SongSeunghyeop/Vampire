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
			if (GetAsyncKeyState(ASCII[i]) && 0x8000) // i��° Ű�� �ԷµǾ��� ��
			{
				if (mKeys[i].bePressed) //�� Ű�� ������ �ԷµǾ��ִ� ���¶�� 
					mKeys[i].Kstate = eKeyState::Pressed;
				else
					mKeys[i].Kstate = eKeyState::Down;

				mKeys[i].bePressed = true;
			}
			else  // i��° Ű�� �ԷµǾ����� �ʾҴٸ�
			{
				if (mKeys[i].bePressed) //�� Ű�� ������ �ԷµǾ��ִ� ���¶�� 
					mKeys[i].Kstate = eKeyState::Up; // ������ �ԷµǾ��� �־��ٸ� Ű�� �� ���̹Ƿ�
				else // �װ� �ƴ϶��
					mKeys[i].Kstate = eKeyState::None;

				mKeys[i].bePressed = false;
			}

		}
	}
	void Input::Render(HDC hdc)
	{

	}
}