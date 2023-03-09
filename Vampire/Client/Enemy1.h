#pragma once
#include "MyGameObject.h"
#include "myAnimator.h"
#include "myTransform.h"
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

		virtual void onCollisionStay(class Collider* other) override;
		virtual void onCollisionExit(class Collider* other) override;
		virtual void onCollisionEnter(class Collider* other) override;
		
		int getRandomPos();

	private:
		Image* EnemyR_Img;
		Image* EnemyL_Img;
		Vector2 EnemyPos;
		Vector2 Ppos;
		Animator *EnemyAnimator;
		bool coll;
	};
}

