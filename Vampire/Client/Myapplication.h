#pragma once
#include "VampireEngine.h"
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
		Vector2 mPos;

		static RECT getRect() 
		{
			return rect;
		}
	private:
		static RECT rect;
		int Rwidth, Rheight;

		HWND mhwnd;
		HDC mhdc; // ����(������)
		HBITMAP backBuffer; 
		HDC backHdc; // �޸𸮻��� ����� (������ ����)
	};
}