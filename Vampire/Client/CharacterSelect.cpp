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
		titleImg = ResourceManager::Load<Image>(L"Title", L"..\\Resources\\Title.bmp"); // 이미지의 키와 경로 정보를 받음
		money = ResourceManager::Load<Image>(L"money", L"..\\Resources\\Money.bmp"); // 이미지의 키와 경로 정보를 받음
		Exit = ResourceManager::Load<Image>(L"Exit", L"..\\Resources\\Exit.bmp");
		Option = ResourceManager::Load<Image>(L"Option", L"..\\Resources\\Option.bmp");
		SelectUI = ResourceManager::Load<Image>(L"Select", L"..\\Resources\\Select.bmp");
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

		HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(hdc, -1, -1, 3000, 1500);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, black);
		DeleteObject(oldbrush);
		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 450, 80, 600, 680, SelectUI->GetHdc(), 0, 0, SelectUI->GetWidth(), SelectUI->GetHeight(), RGB(182, 185, 184));
		TransparentBlt(hdc, 650, 5, 200, 65, money->GetHdc(), 0, 0,  money->GetWidth(), money->GetHeight(), RGB(32, 32, 32));
		TransparentBlt(hdc, 500, 5, 100, 65, Exit->GetHdc(), 0, 0, Exit->GetWidth(), Exit->GetHeight(), RGB(182, 185, 184));
		TransparentBlt(hdc, 900, 5, 100, 65, Option->GetHdc(), 0, 0, Option->GetWidth(), Option->GetHeight(), RGB(32, 32, 32));
	}
	void CharacterSelect::Release()
	{
		GameObject::Release();
	}
}