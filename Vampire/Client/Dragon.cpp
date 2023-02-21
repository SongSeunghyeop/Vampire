#include "Dragon.h"
#include "Time.h"
#include "myInput.h"

namespace ya
{
	Dragon::Dragon()
	{

	}
	Dragon::~Dragon()
	{

	}

	void Dragon::Initialize()
	{
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

		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HGDIOBJ oldBrush = SelectObject(hdc, brush);

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HGDIOBJ oldPen = SelectObject(hdc, pen);

		Rectangle(hdc, mPos.x, mPos.y, mPos.x + 100, mPos.y + 100);

		SelectObject(hdc, oldPen);
		DeleteObject(pen);
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
	void Dragon::Release()
	{
		MyGameObject::Release();
	}
}