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

	}
	Krochi::~Krochi()
	{

	}
	void Krochi::Initialize()
	{
		playerImg = ResourceManager::Load<Image>(L"Player", L"..\\Resources\\Idle.bmp");

		GameObject::Initialize();
	}
	void Krochi::Update()
	{
		GameObject::Update();

		Transform* trans = GetComponent<Transform>(); 
		Krochi::Playerpos = trans->getPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			Krochi::Playerpos.x -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			Krochi::Playerpos.x += 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			Krochi::Playerpos.y -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{ 
			Krochi::Playerpos.y += 200.0f * Time::getDeltaTime();
		}
		trans->setPos(Krochi::Playerpos.x, Krochi::Playerpos.y);
	}
	void Krochi::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Krochi::Playerpos = trans->getPos();
		TransparentBlt(hdc, Krochi::Playerpos.x, Krochi::Playerpos.y, playerImg->GetWidth(), playerImg->GetHeight(), playerImg->GetHdc(), 0, 0,56,67, RGB(254,0, 255));
		//그려줄 HDC, 그림 시작 위치, 그림 그릴 크기, 백버퍼의 HDC, 복사할 그림의 시작 위치, 복사할 그림의 크기, 투명처리할 색깔
	}
	void Krochi::Release()
	{
		GameObject::Release();
	}
}