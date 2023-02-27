#pragma once
#include "VampireEngine.h"

namespace my
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		ESC, ENTER, SPACE, END,
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
			bool bePressed; // ¥≠∑»¿ª ∂ß
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);	

		inline static eKeyState GetKeyState(eKeyCode kcode)
		{
			return mKeys[(UINT)kcode].Kstate;
		}

	private:
		static std::vector<Key> mKeys;
	};

}
