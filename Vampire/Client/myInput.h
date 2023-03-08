#pragma once
#include "VampireEngine.h"

namespace my
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		ESC, ENTER, SPACE, LBUTTON, END,
	};

	enum class eKeyState
	{
		Down,
		Up,
		Pressed,
		None,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode Kcode;
			eKeyState Kstate;
			bool bePressed; // ������ ��
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);	

		inline static eKeyState GetKeyState(eKeyCode kcode)
		{
			return mKeys[(UINT)kcode].Kstate;
		}
		inline static void SetKeyState(eKeyCode kcode, eKeyState k)
		{
			mKeys[(UINT)kcode].Kstate = k;
		}

		static __forceinline bool GetKey(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].Kstate == eKeyState::Pressed;
		}

		static __forceinline bool GetKeyDown(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].Kstate == eKeyState::Down;
		}

		static __forceinline bool GetKeyUp(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].Kstate == eKeyState::Up;
		}

	private:
		static std::vector<Key> mKeys;
	};

}
