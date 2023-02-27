#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "Krochi.h"

namespace my
{
	class Enemy1 : public GameObject
	{
	public:
		Enemy1();
		~Enemy1();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* Enemy1_Img;
		Vector2 EnemyPos;
		Vector2 Ppos;
	};
}

