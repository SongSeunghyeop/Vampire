#include "myResourceManager.h"
#include "Field.h"
#include "Time.h"
#include "myImage.h"
#include "myTransform.h"
#include "Krochi.h"

extern my::Application myapplication;
namespace my
{
	Field::Field()
	{

	}
	Field::~Field()
	{

	}
	void Field::Initialize()
	{
		fieldImg = ResourceManager::Load<Image>(L"Field", L"..\\Resources\\Field.bmp");

		GameObject::Initialize();
	}
	void Field::Update()
	{
		GameObject::Update();
	}
	void Field::Render(HDC hdc)
	{
		Vector2 pos = Camera::CaluatePos(Vector2::Zero);

		StretchBlt(hdc, pos.x - 300, pos.y - 500, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		GameObject::Render(hdc);
 	}
	void Field::Release()
	{
		GameObject::Release();
	}
}