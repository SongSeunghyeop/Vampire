#include "Myapplication.h"
#include "mySceneManager.h"
#include "Time.h"
#include "myInput.h"

namespace ya 
{
	myApplication::myApplication()
		: mhwnd(NULL), mhdc(NULL)
	{

	}
	myApplication::~myApplication()
	{
		mySceneManager::Release();
	}
	void myApplication::Initialize(HWND hwnd)
	{
		this->mhwnd = hwnd;
		this->mhdc = GetDC(hwnd);

		RECT rect = { 0,0,1600,900 };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mhwnd, NULL, 100, 50, rect.right -  rect.left, rect.bottom -  rect.top, 0);
		ShowWindow(hwnd, true);

		backBuffer = CreateCompatibleBitmap(mhdc, 1600, 900);
		backHdc = CreateCompatibleDC(mhdc);
		HGDIOBJ defaultBmp = SelectObject(backHdc, backBuffer);
		DeleteObject(defaultBmp);

		Time::Initialize();
		Input::Initialize();
		mySceneManager::Initialize();
	}
	void myApplication::Run()
	{
		Update(); 
		Render();
	}
	void myApplication::Update()
	{
		Time::Update();
		Input::Update();
		mySceneManager::Update();
	}
	void myApplication::Render()
	{
		Rectangle(backHdc, -1, -1, 1605, 905);

		Time::Render(backHdc);
		Input::Render(backHdc);

		mySceneManager::Render(backHdc);

		//백버퍼의 그림 원본(구현용)에 복사
		BitBlt(mhdc, 0, 0, 1600, 900, backHdc, 0, 0, SRCCOPY);
	}
}