#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "Transform.h"

namespace my
{
	class Title : public MyGameObject
	{
	public:
		Title();
		~Title();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		myImage* titleImg;
	};
}

