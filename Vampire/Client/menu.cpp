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
		menuImg = ResourceManager::Load<myImage>(L"Menu", L"..\\Resources\\menu.bmp");

		MyGameObject::Initialize();
	}
	void Menu::Update()
	{
		MyGameObject::Update();
	}
	void Menu::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		BitBlt(hdc, pos.x, pos.y, menuImg->GetWidth(), menuImg->GetHeight(), menuImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Menu::Release()
	{
		MyGameObject::Release();
	}
}