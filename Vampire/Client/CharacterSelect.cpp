#include "CharacterSelect.h"
#include "myResourceManager.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	CharacterSelect::CharacterSelect()
	{

	}
	CharacterSelect::~CharacterSelect()
	{

	}
	void CharacterSelect::Initialize()
	{
	    titleImg = ResourceManager::Load<Image>(L"Intro", L"..\\Resources\\Intro.bmp"); // 이미지의 키와 경로 정보를 받음
		SelectUI = ResourceManager::Load<Image>(L"Select", L"..\\Resources\\Select.bmp");
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Start_Button.bmp"); // 이미지의 키와 경로 정보를 받음
		start_M = ResourceManager::Load<Image>(L"start_M", L"..\\Resources\\Start_M.bmp"); // 이미지의 키와 경로 정보를 받음
		GameObject::Initialize();
	}

	void CharacterSelect::Update()
	{
		GameObject::Update();
	}
	void CharacterSelect::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 450, 30, SelectUI->GetWidth(), SelectUI->GetHeight(), SelectUI->GetHdc(), 0, 0, SelectUI->GetWidth(), SelectUI->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1088, 540, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1164, 551, start_M->GetWidth() * 1.1, start_M->GetHeight(), start_M->GetHdc(), 0, 0, start_M->GetWidth(), start_M->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1088, 628, start->GetWidth() * 1.4, start->GetHeight() * 1.4, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
	}
	void CharacterSelect::Release()
	{
		GameObject::Release();
	}
}