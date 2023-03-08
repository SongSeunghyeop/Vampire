#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myTransform.h"

namespace my
{
	class InGameMenu : public GameObject
	{
	public:
		InGameMenu();
		~InGameMenu();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* menuImg;

	};
}

