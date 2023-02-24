#include "myResourceManager.h"
#include "menu.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	Menu::Menu()
	{

	}
	Menu::~Menu()
	{

	}
	void Menu::Initialize()
	{
		menuImg = ResourceManager::Load<Image>(L"Menu", L"..\\Resources\\menu.bmp");

		GameObject::Initialize();
	}
	void Menu::Update()
	{
		GameObject::Update();
	}
	void Menu::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		StretchBlt(hdc, 200, 100, 1100, 550, menuImg->GetHdc(), 0, 0, menuImg->GetWidth(), menuImg->GetHeight(), SRCCOPY);
	}
	void Menu::Release()
	{
		GameObject::Release();
	}
}