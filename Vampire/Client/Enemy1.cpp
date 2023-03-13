#include "myResourceManager.h"
#include "Enemy1.h"
#include "Time.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")
namespace my
{
	int Enemy1::getRandomPos()
	{
		static bool initialized = false;

		if (!initialized) {
			srand((UINT)time(NULL)); // 처음 한 번만 호출
			initialized = true;
		}
		int randomPos =  rand() % 300 + 500; // 1부터 1000 사이의 랜덤한 정수 생성
		return randomPos;
	}

	Enemy1::Enemy1()
	{

	}
	Enemy1::~Enemy1()
	{

	}

	void Enemy1::Initialize()
	{
		EnemyR_Img = ResourceManager::Load<Image>(L"EnemyR", L"..\\Resources\\Enemy_R.bmp");
		EnemyL_Img = ResourceManager::Load<Image>(L"EnemyL", L"..\\Resources\\Enemy_L.bmp");

		EnemyAnimator = AddComponent<Animator>();
		EnemyAnimator->CreateAnimation(L"RightWalk",EnemyR_Img,Vector2::Zero,1,1,1,0.3f, 254, 0, 255);
		EnemyAnimator->CreateAnimation(L"LeftWalk",EnemyL_Img,Vector2::Zero,1,1,1,0.3f, 254, 0, 255);

		Transform* tr = GetComponent<Transform>();
		EnemyPos.x = (float)Enemy1::getRandomPos();
		EnemyPos.y = (float)Enemy1::getRandomPos();
		tr->setPos(EnemyPos);
		tr->setScale(1.2f, 1.2f);

 		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(-28, -65));
		collider->setSize(Vector2(68 , 80));

		EnemyAnimator->Play(L"RightWalk", true);
		GameObject::Initialize();
	}
	void Enemy1::Update()
	{
		Transform* tr = GetComponent<Transform>();

		Ppos.x = Krochi::getPlayerPos().x + 14;
		Ppos.y = Krochi::getPlayerPos().y + 33;

		if (EnemyPos.x > Ppos.x)
		{
			if (!enemyColl) // 플레이어와 충돌
			{
			EnemyPos.x -= 100.0f * Time::getDeltaTime();
			EnemyAnimator->Play(L"LeftWalk", true);
			}
			else // 몬스터끼리 충돌 
			{
	
			}
		}
		if (EnemyPos.x < Ppos.x)
		{
			if (!enemyColl)
			{
				EnemyPos.x += 100.0f * Time::getDeltaTime();
				EnemyAnimator->Play(L"RightWalk", true);
			}
			else
			{
			
			}
		}
		if (EnemyPos.y > Ppos.y)
		{
			if (!enemyColl)
			{
				EnemyPos.y -= 100.0f * Time::getDeltaTime();
			}
			else
			{
				
			}
		}
		if (EnemyPos.y < Ppos.y)
		{
			if (!enemyColl)
			{
				EnemyPos.y += 100.0f * Time::getDeltaTime();
			}
			else
			{
				
			}
		}

		tr->setPos(EnemyPos);

		GameObject::Update();
	}
	void Enemy1::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Enemy1::Release()
	{
		GameObject::Release();
	}

	void Enemy1::onCollisionEnter(Collider* other)
	{
			enemyColl = true;
	}

	void Enemy1::onCollisionStay(Collider* other)
	{
			enemyColl = true;

			if (other->getOwner()->getState() == eState::Death)
			{
				enemyColl = false;
			}
	}

	void Enemy1::onCollisionExit(Collider* other)
	{
		enemyColl = false;
	}
}