#pragma once
#include "MyGameObject.h"
#include "MyApplication.h"
#include "myImage.h" 
#include "myTransform.h"
#include "myCollider.h"
#include "myAnimator.h"
#include "Time.h"

namespace my
{
	class Animator;
	class Krochi : public GameObject
	{
	public:
		enum class ePlayerState
		{
			Move,
			Shoot,
			Death,
			Idle
		};

		Krochi();
		~Krochi();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();
		
		static Vector2 getPlayerPos() { return Krochi::Playerpos; }

	private:
		Animator* playerAnimator;
		ePlayerState mState;

		Image* playerImg_R;
		Image* playerImg_L;
		static Vector2 Playerpos;
		Vector2 winPos;

		void move_R();
		void move_L();
		void shoot();
		void death();
		void idle_R();
		void idle_L();
	};
}

