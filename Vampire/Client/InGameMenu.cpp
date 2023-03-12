#include "myResourceManager.h"
#include "InGameMenu.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	InGameMenu::InGameMenu()
	{

	}
	InGameMenu::~InGameMenu()
	{

	}
	void InGameMenu::Initialize()
	{
		menuImg = ResourceManager::Load<Image>(L"Option", L"..\\Resources\\Option.bmp");

		GameObject::Initialize();
	}
	void InGameMenu::Update()
	{
		GameObject::Update();
	}
	void InGameMenu::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		TransparentBlt(hdc, 470, 50, menuImg->GetWidth(), menuImg->GetHeight(), 
			menuImg->GetHdc(), 0, 0, menuImg->GetWidth(), menuImg->GetHeight(), RGB(255,0,255));
	}
	void InGameMenu::Release()
	{
		GameObject::Release();
	}
}