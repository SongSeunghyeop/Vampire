#pragma once
#include "MyGameObject.h"
#include "MyApplication.h"
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

		virtual void onCollisionStay(class Collider* other) override;
		virtual void onCollisionExit(class Collider* other) override;
		virtual void onCollisionEnter(class Collider* other) override;

		
		static Vector2 getPlayerPos() { return Krochi::Playerpos; }
		static ePlayerState getPlayerState() { return Krochi::mState; }
		static bool getPlayerDirect() { return Krochi::Right; }
		static bool getPlayerColl() { return Krochi::Player_coll; }
		static void setPlayerColl(bool b) { Krochi::Player_coll = b; }

	private:

		static ePlayerState mState;
		static Vector2 Playerpos;
		static bool Player_coll;
		static bool Right;

		Animator* playerAnimator;
		Image* playerImg_R;
		Image* playerImg_L;
		Image* damaged_R;
		Image* damaged_L;

		Vector2 winPos;

		void move();
		void shoot();
		void death();
		void idle();
		void idleCompleteEvent();
	};
}

