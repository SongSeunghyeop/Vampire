#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "Transform.h"

namespace my
{
	class Menu : public MyGameObject
	{
	public:
		Menu();
		~Menu();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		myImage* menuImg;
	};
}

