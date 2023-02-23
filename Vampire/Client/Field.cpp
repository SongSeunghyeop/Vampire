#include "myResourceManager.h"
#include "Field.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"
#include "Transform.h"

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
		fieldImg = ResourceManager::Load<myImage>(L"Field", L"..\\Resources\\Field.bmp");

		MyGameObject::Initialize();
	}
	void Field::Update()
	{
		MyGameObject::Update();
	}
	void Field::Render(HDC hdc)
	{
		MyGameObject::Render(hdc);

		Transform* trans = GetComponent<Transform>();
		Vector2 pos = trans->getPos();

		BitBlt(hdc, pos.x, pos.y, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, SRCCOPY);
	}
	void Field::Release()
	{
		MyGameObject::Release();
	}
}