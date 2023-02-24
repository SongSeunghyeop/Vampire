#include "myResourceManager.h"
#include "Field.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"
#include "myTransform.h"

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
		GameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		BitBlt(hdc, pos.x, pos.y, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Field::Release()
	{
		GameObject::Release();
	}
}