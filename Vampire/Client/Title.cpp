#include "Title.h"
#include "myResourceManager.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	bool Title::TitleUIButton;

	Title::Title()
	{

	}
	Title::~Title()
	{

	}
	void Title::Initialize()
	{
		titleImg = ResourceManager::Load<Image>(L"Title", L"..\\Resources\\Title.bmp"); // 이미지의 키와 경로 정보를 받음
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Start_Button.bmp"); // 이미지의 키와 경로 정보를 받음
		start_M = ResourceManager::Load<Image>(L"start_M", L"..\\Resources\\Start_M.bmp"); // 이미지의 키와 경로 정보를 받음
	}

	void Title::Update()
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			POINT mousePos;
			GetCursorPos(&mousePos);
				
			if (mousePos.x > 1035 && mousePos.x < 1020 + start->GetWidth() * 1.4
				&& mousePos.y > 525 && mousePos.y < 505 + start->GetHeight() * 1.4)
				TitleUIButton = true;
		}

		GameObject::Update();
	}
	void Title::Render(HDC hdc)
	{
		StretchBlt(hdc, 110, 0, 1280, 720, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 1000, 430, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1078, 440, start_M->GetWidth() * 1.1, start_M->GetHeight(), start_M->GetHdc(), 0, 0, start_M->GetWidth(), start_M->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1000, 510, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1000, 590, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		 
		GameObject::Render(hdc);
	}
	void Title::Release()
	{
		GameObject::Release();
	}
}