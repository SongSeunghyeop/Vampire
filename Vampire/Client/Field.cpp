#include "myResourceManager.h"
#include "Field.h"
#include "Time.h"
#include "myCamera.h"

#include "Krochi.h"

extern my::Application myapplication;

namespace my
{
	Field::Field()
		:width_change(0)
		,height_change(0)
	{

	}
	Field::~Field()
	{

	}
	void Field::Initialize()
	{
		fieldImg = ResourceManager::Load<Image>(L"Field", L"..\\Resources\\Field2.bmp");

		GameObject::Initialize();
	}
	void Field::Update()
	{
		GameObject::Update();
	}
	void Field::Render(HDC hdc)
	{
		Vector2 pos = Camera::CaluatePos(Vector2::Zero);
		//Å©·©Å° ¹Ú½º
		StretchBlt(hdc, pos.x - (width_change -1) * 2048, pos.y - (height_change - 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change) * 2048, pos.y - (height_change - 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change +1) * 2048, pos.y - (height_change - 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		
		StretchBlt(hdc, pos.x - (width_change - 1) * 2048, pos.y - height_change * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change) * 2048, pos.y - height_change * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change + 1) * 2048, pos.y - height_change * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		
		StretchBlt(hdc, pos.x - (width_change - 1) * 2048, pos.y - (height_change + 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change) * 2048, pos.y - (height_change + 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);
		StretchBlt(hdc, pos.x - (width_change + 1) * 2048, pos.y - (height_change + 1) * 2048, fieldImg->GetWidth(), fieldImg->GetHeight(), fieldImg->GetHdc(), 0, 0, fieldImg->GetWidth(), fieldImg->GetHeight(), SRCCOPY);

		if (Krochi::getPlayerPos().x  < -2048 * width_change)
		{
			width_change++;
		}
		if (Krochi::getPlayerPos().x  > ( -2048 * width_change) + 2048)
		{
			width_change--;
		}
		if (Krochi::getPlayerPos().y < - 2048 * height_change)
		{
			height_change++;
		}
		if (Krochi::getPlayerPos().y > (-2048 * height_change) + 2048)
		{
			height_change--;
		}
 	}
	void Field::Release()
	{
		GameObject::Release();
	}
}