#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myTransform.h"

namespace my
{
	class Krochi : public GameObject
	{
	public:
		Krochi();
		~Krochi();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();
		
		static Vector2 getPlayerPos() { return Krochi::Playerpos; }

	private:
		Image* playerImg;
		static Vector2 Playerpos;
	};
}

