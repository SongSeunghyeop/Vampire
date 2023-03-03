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
		menuImg = ResourceManager::Load<Image>(L"Menu", L"..\\Resources\\menu.bmp");

		GameObject::Initialize();
	}
	void InGameMenu::Update()
	{
		GameObject::Update();
	}
	void InGameMenu::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		StretchBlt(hdc, 200, 100, 1100, 550, menuImg->GetHdc(), 0, 0, menuImg->GetWidth(), menuImg->GetHeight(), SRCCOPY);
	}
	void InGameMenu::Release()
	{
		GameObject::Release();
	}
}