#include "myInput.h"

namespace ya
{
	int ASCII[(UINT)KeyCode::END]
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	std::vector<Input::Key> Input::mKeys = { };

	void Input::Initialize()
	{
		for (int i = 0; i < (UINT)KeyCode::END; i++)
		{
			Key keyInfo;
			keyInfo.Kcode = (KeyCode)i;
			keyInfo.Kstate = KeyState::None;
			keyInfo.bePressed = false;

			mKeys.push_back(keyInfo);
		}
	}
	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)KeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) && 0x8000) // i��° Ű�� �ԷµǾ��� ��
			{
				if (mKeys[i].bePressed) //�� Ű�� ������ �ԷµǾ��ִ� ���¶�� 
					mKeys[i].Kstate = KeyState::Pressed;
				else
					mKeys[i].Kstate = KeyState::Down;

				mKeys[i].bePressed = true;
			}
			else  // i��° Ű�� �ԷµǾ����� �ʾҴٸ�
			{
				if (mKeys[i].bePressed) //�� Ű�� ������ �ԷµǾ��ִ� ���¶�� 
					mKeys[i].Kstate = KeyState::Up; // ������ �ԷµǾ��� �־��ٸ� Ű�� �� ���̹Ƿ�
				else // �װ� �ƴ϶��
					mKeys[i].Kstate = KeyState::None;

				mKeys[i].bePressed = false;
			}

		}
	}
	void Input::Render(HDC hdc)
	{

	}
}