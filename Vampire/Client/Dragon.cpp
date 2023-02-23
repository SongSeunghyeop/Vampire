#include "myResourceManager.h"
#include "Dragon.h"
#include "Time.h"
#include "myInput.h"
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

		Transform* trans = GetComponent<Transform>(); 
		Vector2 pos = trans->getPos();

		if (Input::GetKeyState(KeyCode::A) == KeyState::Pressed)
		{
			pos.x -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(KeyCode::D) == KeyState::Pressed)
		{
			pos.x += 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(KeyCode::W) == KeyState::Pressed)
		{
			pos.y -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(KeyCode::S) == KeyState::Pressed)
		{ 
			pos.y += 200.0f * Time::getDeltaTime();
		}
		trans->setPos(pos.x, pos.y);
	}
	void Dragon::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		BitBlt(hdc, pos.x, pos.y, playerImg->GetWidth(), playerImg->GetHeight(), playerImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Dragon::Release()
	{
		MyGameObject::Release();
	}
}