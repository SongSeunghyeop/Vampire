#include "myResourceManager.h"
#include "Krochi.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")

namespace my
{
	Vector2 Krochi::Playerpos;

	Krochi::Krochi()
	{
		motionTime = 0;
		motion = 0;
	}
	Krochi::~Krochi()
	{

	}
	void Krochi::Initialize()
	{
		playerImg = ResourceManager::Load<Image>(L"Player", L"..\\Resources\\Player_1_.bmp");

		GameObject::Initialize();
		Transform* trans = GetComponent<Transform>();
		trans->setPos((winRect.right - winRect.left) / 2 - 68, (winRect.bottom - winRect.top) / 2 - 70);
		Krochi::Playerpos = trans->getPos();
	}
	void Krochi::Update()
	{
		GameObject::Update();

		Transform* trans = GetComponent<Transform>(); 
		Krochi::Playerpos = trans->getPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			Krochi::Playerpos.x -= 190.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			Krochi::Playerpos.x += 190.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			Krochi::Playerpos.y -= 190.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{ 
			Krochi::Playerpos.y += 190.0f * Time::getDeltaTime();
		}
		trans->setPos(Krochi::Playerpos.x, Krochi::Playerpos.y);
	}
	void Krochi::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		motionTime += Time::getDeltaTime();

		if (motionTime > 0.2f)
		{
			++motion;
			motionTime = 0;
		}
		if (motion >= 3)
		{
			motion = 0;
		}
		Transform* trans = GetComponent<Transform>();
		Krochi::Playerpos = trans->getPos();

		TransparentBlt(hdc, Krochi::Playerpos.x, Krochi::Playerpos.y, 68, 70, playerImg->GetHdc(), 0 + (32 * motion), 0, playerImg->GetWidth() / 3, playerImg->GetHeight(), RGB(255, 0, 255));
		//그려줄 HDC, 그림 시작 위치, 그림 그릴 크기, 백버퍼의 HDC, 복사할 그림의 시작 위치, 복사할 그림의 크기, 투명처리할 색깔
	}
	void Krochi::Release()
	{
		GameObject::Release();
	}
}