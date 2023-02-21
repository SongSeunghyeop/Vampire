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
		this->mhdc = GetDC(hwnd); // HDC : 비트맵에 그려주는 역할 // getDC : 현재 윈도우가 갖고있는 비트맵을 할당받는 DC가 목적지로 삼는 것

		RECT rect = { 0,0,1600,900 }; // 윈도우 전체 크기의 사각형
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // 해상도를 입력하면, 그에 맞게 수정
		SetWindowPos(mhwnd, NULL, 20, 20, (rect.right -  rect.left) - 200, (rect.bottom -  rect.top) - 200, 0); // 윈도우 크기 및 위치 조정
		ShowWindow(hwnd, true); // 윈도우 해상도 조절을 위한 함수(타이틀바, 테두리,메뉴바 등을 포함한 해상도이므로, 조절이 필요)
		//윈도우 전체 덮을 흰색 사각형

		backBuffer = CreateCompatibleBitmap(mhdc, 1600, 900); // 현재의 hdc에 호환되는 백버퍼 비트맵을 만듦(비트맵 = 도화지)
		backHdc = CreateCompatibleDC(mhdc); // 현재 hdc에 호환되며 보이지 않는 메모리상의 HDC를 만듦
		HBITMAP defaultBmp = (HBITMAP)SelectObject(backHdc, backBuffer); // 백버퍼용 비트맵 선택, 백 버퍼용 hdc의 기존 비트맵과 교체
		DeleteObject(defaultBmp); // 기존의 비트맵 삭제 // 준비 끝

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
		Rectangle(backHdc, -1, -1, 1601, 901); // 흰색 배경
		Time::Render(backHdc);
		Input::Render(backHdc);
		mySceneManager::Render(backHdc); // 전부다 백버퍼에 랜더

		//백버퍼의 그림 원본(구현용)에 복사 ( 흰색의 화면까지 전체가 계속 포함되어서 복사가 되는 것이므로 깜빡이지 않는다 
		BitBlt(mhdc, 0, 0, 1600, 900, backHdc, 0, 0, SRCCOPY); // 구현용 hdc에 그대로 복사
	}
}