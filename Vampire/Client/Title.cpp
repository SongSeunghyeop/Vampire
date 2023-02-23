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
		titleImg = ResourceManager::Load<myImage>(L"Title", L"..\\Resources\\Title.bmp");

		MyGameObject::Initialize();
	}
	void Title::Update()
	{
		MyGameObject::Update();
	}
	void Title::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		BitBlt(hdc, pos.x, pos.y, titleImg->GetWidth(), titleImg->GetHeight(), titleImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Title::Release()
	{
		MyGameObject::Release();
	}
}