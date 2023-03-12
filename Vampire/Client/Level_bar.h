#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myTransform.h"

namespace my
{
	class Level_bar : public GameObject
	{
	public:
		Level_bar();
		~Level_bar();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* level_bar;
		Image* Charactor;
		Image* health;
		Image* health_zero;
	};
}

