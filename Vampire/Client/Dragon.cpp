#include "Dragon.h"
#include "Time.h"
#include "myInput.h"
#include "myResourceManager.h"
#include "myImage.h"

namespace my
{
	Dragon::Dragon()
	{

	}
	Dragon::~Dragon()
	{

	}
	void Dragon::Initialize()
	{
		playerImg = ResourceManager::Load<myImage>(L"Player", L"..\\Resources\\Idle.bmp");

		MyGameObject::Initialize();
	}
	void Dragon::Update()
	{
		MyGameObject::Update();

		if (Input::GetKeyState(KeyCode::A) == KeyState::Pressed)
		{
			mPos.x -= 200.0f * Time::getDeltaTime();	
		}
		if (Input::GetKeyState(KeyCode::D) == KeyState::Pressed)
		{
			mPos.x += 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(KeyCode::W) == KeyState::Pressed)
		{
			mPos.y -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(KeyCode::S) == KeyState::Pressed)
		{
			mPos.y += 200.0f * Time::getDeltaTime();
		}
	}
	void Dragon::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);

		BitBlt(hdc, mPos.x, mPos.y, playerImg->GetWidth(), playerImg->GetHeight(), playerImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Dragon::Release()
	{
		MyGameObject::Release();
	}
}