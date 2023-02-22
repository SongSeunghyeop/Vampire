#pragma once
#include "VampireEngine.h"

namespace my
{
	enum class KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		END,
	};

	enum class KeyState
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
			KeyCode Kcode;
			KeyState Kstate;
			bool bePressed; // ¥≠∑»¿ª ∂ß
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);	

		inline static KeyState GetKeyState(KeyCode kcode)
		{
			return mKeys[(UINT)kcode].Kstate;
		}

	private:
		static std::vector<Key> mKeys;
	};

}
