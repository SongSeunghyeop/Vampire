#include "Title.h"
#include "myResourceManager.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	Title::Title()
	{

	}
	Title::~Title()
	{

	}
	void Title::Initialize()
	{
		titleImg = ResourceManager::Load<Image>(L"Title", L"..\\Resources\\Title.bmp"); // 이미지의 키와 경로 정보를 받음
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Start.bmp"); // 이미지의 키와 경로 정보를 받음
		start2 = ResourceManager::Load<Image>(L"start2", L"..\\Resources\\Start2.bmp"); // 이미지의 키와 경로 정보를 받음
		button1 = ResourceManager::Load<Image>(L"button1", L"..\\Resources\\button1.bmp"); // 이미지의 키와 경로 정보를 받음
		money = ResourceManager::Load<Image>(L"money", L"..\\Resources\\Money.bmp"); // 이미지의 키와 경로 정보를 받음
		Exit = ResourceManager::Load<Image>(L"Exit", L"..\\Resources\\Exit.bmp");
		Option = ResourceManager::Load<Image>(L"Option", L"..\\Resources\\Option.bmp");

		GameObject::Initialize();
	}
	void Title::Update()
	{
		GameObject::Update();
	}
	void Title::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();	
		Vector2 pos = trans->getPos();

		HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(hdc, -1, -1, 3000, 1500);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, black);
		DeleteObject(oldbrush);
		StretchBlt(hdc, 120, 0, 1260, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 1000, 350, 200, 80, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(182, 185, 184));
		TransparentBlt(hdc, 1060, 350, 80, 80, start2->GetHdc(), 0, 0, start2->GetWidth(), start2->GetHeight(), RGB(0, 0, 0));
		TransparentBlt(hdc, 650, 5, 200, 65, money->GetHdc(), 0, 0, money->GetWidth(), money->GetHeight(), RGB(32, 32, 32));
		TransparentBlt(hdc, 1020, 480, 160, 80, button1->GetHdc(), 0, 0, button1->GetWidth(), button1->GetHeight(), RGB(0, 0, 0));
		TransparentBlt(hdc, 500, 5, 100, 65, Exit->GetHdc(), 0, 0, Exit->GetWidth(), Exit->GetHeight(), RGB(182, 185, 184));
		TransparentBlt(hdc, 900, 5, 100, 65, Option->GetHdc(), 0, 0, Option->GetWidth(), Option->GetHeight(), RGB(32, 32, 32));

	}
	void Title::Release()
	{
		GameObject::Release();
	}
}