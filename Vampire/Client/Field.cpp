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
		Transform* tr = GetComponent<Transform>();
		Vector2 pPos = Krochi::getPlayerPos();
		pPos.x -= 500;
		pPos.y -= 250;

		tr->setPos(pPos);
		GameObject::Initialize();
	}
	void Field::Update()
	{
		GameObject::Update();
	}
	void Field::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		StretchBlt(hdc, 0, 0, 1500, 750, fieldImg->GetHdc(), 0, 0, 1000, 500, SRCCOPY);
	}
	void Field::Release()
	{
		GameObject::Release();
	}
}