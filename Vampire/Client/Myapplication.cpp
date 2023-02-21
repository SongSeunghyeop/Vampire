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
		this->mhwnd = hwnd; // 핸들
		this->mhdc = GetDC(hwnd); // HDC : 비트맵에 그려주는 역할

		RECT rect = { 0,0,1600,900 }; // 윈도우 전체 크기의 사각형
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // 해상도를 입력하면, 그에 맞게 수정
		SetWindowPos(mhwnd, NULL, 100, 50, rect.right -  rect.left, rect.bottom -  rect.top, 0); // 윈도우 크기 및 위치 조정
		ShowWindow(hwnd, true); // 윈도우 해상도 조절을 위한 함수(타이틀바, 테두리,메뉴바 등을 포함한 해상도이므로, 조절이 필요)
		//윈도우 전체 덮을 흰색 사각형

		backBuffer = CreateCompatibleBitmap(mhdc, 1600, 900); // 현재의 hdc에 호환되는 백버퍼 비트맵을 만듦(비트맵 = 도화지)
		backHdc = CreateCompatibleDC(mhdc); // 보이지 않는 메모리상의 HDC
		HBITMAP defaultBmp = (HBITMAP)SelectObject(backHdc, backBuffer); // 새로 만든 백 HDC와 백 버퍼 선택
		DeleteObject(defaultBmp); // 기존의 디폴트값 삭제 // 준비 끝

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
		mySceneManager::Render(backHdc); // 전부다 백버퍼에 렌더링

		//백버퍼의 그림 원본(구현용)에 복사
		BitBlt(mhdc, 0, 0, 1600, 900, backHdc, 0, 0, SRCCOPY); // 구현용 hdc에 그대로 복사
	}
}