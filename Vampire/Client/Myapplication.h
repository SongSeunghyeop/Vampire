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
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	public:
		Vector2 getWindowPos() { return WindowPos; }

	private:
		RECT rect;
		Vector2 WindowPos;
		Vector2 mPos;
		HWND mhwnd;
		HDC mhdc; // ����(������)
		HBITMAP backBuffer; 
		HDC backHdc; // �޸𸮻��� ����� (������ ����)

		int mWidth;
		int mHeight;
	};
}