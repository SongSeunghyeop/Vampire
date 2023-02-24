#include "myResourceManager.h"
#include "Krochi.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")
namespace my
{
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
		Vector2 pos = trans->getPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 200.0f * Time::getDeltaTime();
		}
		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{ 
			pos.y += 200.0f * Time::getDeltaTime();
		}
		trans->setPos(pos.x, pos.y);
	}
	void Krochi::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();
		TransparentBlt(hdc, pos.x, pos.y, playerImg->GetWidth(), playerImg->GetHeight(), playerImg->GetHdc(), 0, 0,56,67, RGB(254,0, 255));
		//�׷��� HDC, �׸� ���� ��ġ, �׸� �׸� ũ��, ������� HDC, ������ �׸��� ���� ��ġ, ������ �׸��� ũ��, ����ó���� ����
	}
	void Krochi::Release()
	{
		GameObject::Release();
	}
}