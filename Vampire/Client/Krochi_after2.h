#pragma once
#include "MyGameObject.h"
#include "MyApplication.h"
#include "Krochi.h"
#include "myImage.h" 
#include "myAnimator.h"
#include "myTransform.h"
#include "Time.h"

namespace my
{
	class Animator;
	class Krochi_after2 : public GameObject
	{
	public:

		Krochi_after2();
		~Krochi_after2();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Animator* playerAnimator;
		Krochi::ePlayerState after_State;

		Image* playerImg_RA1;
		Image* playerImg_LA1;
		Image* playerImg_N;
		Image* Damaged_R;
		Image* Damaged_L;

		Vector2 afterPos;
		bool Right_after;
		float delay;

		void move();
		void shoot();
		void death();
		void idle();
	};
}

