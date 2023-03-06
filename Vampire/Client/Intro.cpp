#include "Intro.h"
#include "myResourceManager.h"
#include "myInput.h"
#include "Time.h"
#include "myImage.h"

namespace my
{
	double Intro::mSecond = 0.0f;

	Intro::Intro()
	{
	}
	Intro::~Intro()
	{

	}
	void Intro::Initialize()
	{
		titleImg = ResourceManager::Load<Image>(L"Intro", L"..\\Resources\\Intro.bmp"); // �̹����� Ű�� ��� ������ ����
		IntroM = ResourceManager::Load<Image>(L"IntroM", L"..\\Resources\\Intro2.bmp"); // �̹����� Ű�� ��� ������ ����
		GameObject::Initialize();
	}
	void Intro::Update()
	{
		GameObject::Update();
	}
	void Intro::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		Transform* trans = GetComponent<Transform>(); 
		Vector2 pos = trans->getPos();

		HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(hdc, -1, -1, 3000, 1500);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, black);
		DeleteObject(oldbrush);
		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, 1200, 750, SRCCOPY);
		TransparentBlt(hdc, 500, 600, 500, 60, IntroM->GetHdc(), 0, 0, IntroM->GetWidth(), IntroM->GetHeight(), RGB(0, 0, 0));
		
		mSecond += 0.15f * Time::getDeltaTime();

		if (mSecond > 0.1f)
		{
			StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, 1200, 750, SRCCOPY);
		}
		if (mSecond > 0.2f)
		{
			mSecond = 0.00f;
		}
	
	}
	void Intro::Release()
	{
		GameObject::Release();
	}
}