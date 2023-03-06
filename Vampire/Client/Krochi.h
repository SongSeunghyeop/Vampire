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
		
		static Vector2 getPlayerPos() 
		{ 
			return Krochi::Playerpos;
		}
		static ePlayerState getPlayerState() { return Krochi::mState; }
		static bool getDirect() { return Krochi::Right; }
	private:
		static ePlayerState mState;
		static Vector2 Playerpos;
		static bool Right;

		Animator* playerAnimator;
		Image* playerImg_R;
		Image* playerImg_L;
		Vector2 winPos;

		void move();
		void shoot();
		void death();
		void idle();
	};
}

