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
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Red_Button.bmp"); // 이미지의 키와 경로 정보를 받음
		money = ResourceManager::Load<Image>(L"money", L"..\\Resources\\Money.bmp"); // 이미지의 키와 경로 정보를 받음
		Exit = ResourceManager::Load<Image>(L"Exit", L"..\\Resources\\Red_Button_s.bmp");
		Option = ResourceManager::Load<Image>(L"Option", L"..\\Resources\\Blue_Button.bmp");
		SelectUI = ResourceManager::Load<Image>(L"SelectUI", L"..\\Resources\\SelectUI.bmp");
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

		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 970, 470, start->GetWidth() * 2.0f, start->GetHeight() * 2.0f, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 659, 8, money->GetWidth() * 1.3f, money->GetHeight() * 1.3f, money->GetHdc(), 0, 0, money->GetWidth(), money->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 501, 6, Exit->GetWidth()* 2.0f, Exit->GetHeight() * 2.0f, Exit->GetHdc(), 0, 0, Exit->GetWidth(), Exit->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 899, 6, Option->GetWidth() * 2.0f, Option->GetHeight() * 2.0f, Option->GetHdc(), 0, 0, Option->GetWidth(), Option->GetHeight(), RGB(255, 0, 255));
	}
	void Title::Release()
	{
		GameObject::Release();
	}
}