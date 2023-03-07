#include "Title.h"
#include "myResourceManager.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

namespace my
{
	Title::Title()
	{

	}
	Title::~Title()
	{

	}
	void Title::Initialize()
	{
		titleImg = ResourceManager::Load<Image>(L"Intro", L"..\\Resources\\Intro.bmp"); // 이미지의 키와 경로 정보를 받음
		start = ResourceManager::Load<Image>(L"start", L"..\\Resources\\Start_Button.bmp"); // 이미지의 키와 경로 정보를 받음
		start_M = ResourceManager::Load<Image>(L"start_M", L"..\\Resources\\Start_M.bmp"); // 이미지의 키와 경로 정보를 받음
		arrowAnimator = AddComponent<Animator>();
		
		Transform* tr = GetComponent<Transform>();
		tr->setPos(940,386);
		tr->setScale(2.4f, 2.3f);
	}

	void Title::Update()
	{
		GameObject::Update();
	}
	void Title::Render(HDC hdc)
	{

		Transform* trans = GetComponent<Transform>();	
		Vector2 pos = trans->getPos();

		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
		TransparentBlt(hdc, 970, 350, start->GetWidth() * 1.6, start->GetHeight() * 1.6, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 1056, 364, start_M->GetWidth() * 1.2, start_M->GetHeight() * 1.1, start_M->GetHdc(), 0, 0, start_M->GetWidth(), start_M->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 970, 450, start->GetWidth() * 1.6, start->GetHeight() * 1.6, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		TransparentBlt(hdc, 970, 550, start->GetWidth() * 1.6, start->GetHeight() * 1.6, start->GetHdc(), 0, 0, start->GetWidth(), start->GetHeight(), RGB(255, 0, 255));
		
		GameObject::Render(hdc);
	}
	void Title::Release()
	{
		GameObject::Release();
	}
}