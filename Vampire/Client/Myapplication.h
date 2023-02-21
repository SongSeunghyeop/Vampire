#pragma once
#include "VampireEngine.h"
//������ ��ü�� �Ѱ�

namespace ya
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

	public:
		Vector2 mPos;
	private:
		HWND mhwnd;
		HDC mhdc; // ���� ��ȭ��(������)

		HBITMAP backBuffer; 
		HDC backHdc; // �޸𸮻��� ����� ��ȭ��(������ ����)
	};
}