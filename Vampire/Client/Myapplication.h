#pragma once
#include "VampireEngine.h"
//게임의 전체를 총괄

namespace ya
{
	class myApplication
	{
	public:
		myApplication();
		virtual ~myApplication();

		void Initialize(HWND mhwnd); // 초기화
		void Run(); // while, update, render
		void Update(); // 로직 실행
		void Render(); // 화면 구현
		//void Release(); // 게임 종료, 메모리 해제

		HWND GetHwnd() { return mhwnd; }

	public:
		Vector2 mPos;
	private:
		HWND mhwnd;
		HDC mhdc;
	};
}