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
		titleImg = ResourceManager::Load<Image>(L"Title", L"..\\Resources\\Title.bmp"); // 이미지의 키와 경로 정보를 받음

		GameObject::Initialize();
	}
	void Title::Update()
	{
		GameObject::Update();
	}
	void Title::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
		Rectangle(hdc, -1, -1, 3000, 1500);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, black);
		DeleteObject(oldbrush);
		StretchBlt(hdc, 150, 0, 1200, 750, titleImg->GetHdc(), 0, 0, titleImg->GetWidth(), titleImg->GetHeight(), SRCCOPY);
	}
	void Title::Release()
	{
		GameObject::Release();
	}
}