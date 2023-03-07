#pragma once
#include "MyGameObject.h"
#include "myImage.h" 
#include "myTransform.h"
#include "myAnimator.h"

namespace my
{
	class Title : public GameObject
	{
	public:
		Title();
		~Title();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Image* titleImg;
		Image* start;
		Image* start_M;
		Image* money;
		Image* Exit;
		Image* Option;
		Image* SelectUI;
		Animator* arrowAnimator;
	};
}

