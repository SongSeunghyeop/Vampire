#pragma once
#include "VampireEngine.h"
#include "Krochi.h"
//������ ��ü�� �Ѱ�

namespace my
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Initialize(HWND mhwnd); // �ʱ�ȭ
		void Run(); // update, render
		void Update(); // ���� ����
		void Render(); // ȭ�� ����
		//void Release(); // ���� ����, �޸� ����

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
		HDC mhdc; // ����(������)
		HBITMAP backBuffer; 
		HDC backHdc; // �޸𸮻��� ����� (������ ����)
		Vector2 mPos;
	};
}