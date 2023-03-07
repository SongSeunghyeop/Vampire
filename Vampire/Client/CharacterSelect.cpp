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

		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 659, 8, money->GetWidth() * 1.3f, money->GetHeight() * 1.3f, money->GetHdc(), 0, 0, money->GetWidth(), money->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 501, 6, Exit->GetWidth() * 2.0f, Exit->GetHeight() * 2.0f, Exit->GetHdc(), 0, 0, Exit->GetWidth(), Exit->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 899, 6, Option->GetWidth() * 2.0f, Option->GetHeight() * 2.0f, Option->GetHdc(), 0, 0, Option->GetWidth(), Option->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 450, 80, SelectUI->GetWidth(), SelectUI->GetHeight(), SelectUI->GetHdc(), 0, 0, SelectUI->GetWidth(), SelectUI->GetHeight(), RGB(255, 0, 255));
	}
	void CharacterSelect::Release()
	{
		GameObject::Release();
	}
}