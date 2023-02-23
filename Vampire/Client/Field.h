#pragma once
#include "MyGameObject.h"
#include "myImage.h" 

namespace my
{
	class Field : public MyGameObject
	{
	public:
		Field();
		~Field();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		myImage* fieldImg;
	};
}

