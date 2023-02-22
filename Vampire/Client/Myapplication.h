#pragma once
#include "VampireEngine.h"
//������ ��ü�� �Ѱ�

namespace my
{
	class myApplication
	{
	public:
		myApplication();
		virtual ~myApplication();

		void Initialize(HWND mhwnd); // �ʱ�ȭ
		void Run(); // while, update, render
		void Update(); // ���� ����
		void Render(); // ȭ�� ����
		//void Release(); // ���� ����, �޸� ����

		HWND GetHwnd() { return mhwnd; }
		HDC		GetHdc() { return mhdc; }

	public:
		Vector2 mPos;
	private:
		HWND mhwnd;
		HDC mhdc; // ���� ��ȭ��(������)
		HBITMAP backBuffer; 
		HDC backHdc; // �޸𸮻��� ����� ��ȭ��(������ ����)
	};
}