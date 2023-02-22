#pragma once
#include "MyGameObject.h"
#include "myImage.h" 

namespace my
{
	class Dragon : public MyGameObject
	{
	public:
		Dragon();
		~Dragon();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		myImage* playerImg;
	};
}

