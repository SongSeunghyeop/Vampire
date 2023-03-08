#pragma once
#include "VampireEngine.h"
#include "Krochi.h"
//게임의 전체를 총괄

namespace my
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Initialize(HWND mhwnd); // 초기화
		void Run(); // update, render
		void Update(); // 로직 실행
		void Render(); // 화면 구현
		//void Release(); // 게임 종료, 메모리 해제

		HWND GetHwnd() { return mhwnd; }
		HDC		GetHdc() { return mhdc; }

	public:
		Vector2 getWindowPos() 
		{
			return WindowPos;
		}

	private:
		RECT rect;
		Vector2 WindowPos;
		HWND mhwnd;
		HDC mhdc; // 원본(구현용)
		HBITMAP backBuffer; 
		HDC backHdc; // 메모리상의 백버퍼 (보이지 않음)
		Vector2 mPos;
	};
}