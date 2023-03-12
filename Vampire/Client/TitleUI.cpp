#include "myResourceManager.h"
#include "TitleUI.h"
#include "mySceneManager.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	bool TitleUI::PlayButton;

	TitleUI::TitleUI()
	{
		titleImg = ResourceManager::Load<Image>(L"Intro", L"..\\Resources\\Title3.bmp"); // 이미지의 키와 경로 정보를 받음
		SelectUI = ResourceManager::Load<Image>(L"Select", L"..\\Resources\\Select.bmp");
		info = ResourceManager::Load<Image>(L"info", L"..\\Resources\\Info.bmp");
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Start_Button.bmp"); // 이미지의 키와 경로 정보를 받음
		start_M = ResourceManager::Load<Image>(L"start_M", L"..\\Resources\\Start_M.bmp"); // 이미지의 키와 경로 정보를 받음
	}
	TitleUI::~TitleUI()
	{

	}
	void TitleUI::Initialize()
	{
		GameObject::Initialize();
	}

	void TitleUI::Update()
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			POINT mousePos;
			GetCursorPos(&mousePos);

			if (mousePos.x > 1120 && mousePos.x < 1145 + start->GetWidth() * 1.4
				&& mousePos.y > 620 && mousePos.y < 660 + start->GetHeight() * 1.4)
				TitleUI::PlayButton = true;
		}
		GameObject::Update();
	}
	void TitleUI::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		StretchBlt(hdc, 110, 0, 1280, 720, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 450, 30, SelectUI->GetWidth(), SelectUI->GetHeight(), SelectUI->GetHdc(), 0, 0, SelectUI->GetWidth(), SelectUI->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 162, 120, info->GetWidth() / 1.3, info->GetHeight() / 1.3, info->GetHdc(), 0, 0, info->GetWidth(), info->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1107, 550, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1183, 561, start_M->GetWidth() * 1.1, start_M->GetHeight(), start_M->GetHdc(), 0, 0, start_M->GetWidth(), start_M->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1107, 628, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
	}
	void TitleUI::Release()
	{
		GameObject::Release();
	}
}