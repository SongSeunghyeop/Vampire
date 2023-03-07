#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myTransform.h"

namespace my
{
	class CharacterSelect : public GameObject
	{
	public:
		CharacterSelect();
		~CharacterSelect();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* titleImg;
		Image* SelectUI;
		Image* start;
		Image* start_M;
	};
}

