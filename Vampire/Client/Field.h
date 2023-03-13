#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myApplication.h"

namespace my
{
	class Field : public GameObject
	{
	public:
		Field();
		~Field();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* fieldImg;
		int width_change;
		int height_change;
	};
}

