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
			srand(time(NULL)); // 처음 한 번만 호출
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
		EnemyPos.x = Enemy1::getRandomPos();
		EnemyPos.y = Enemy1::getRandomPos();
		tr->setPos(EnemyPos);
		tr->setScale(1,1);
		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(-27, -67));
		collider->setSize(Vector2(53, 65));
		GameObject::Initialize();
	}
	void Enemy1::Update()
	{
		Transform* tr = GetComponent<Transform>();
		EnemyPos = tr->getPos();
		Ppos.x = Krochi::getPlayerPos().x + 15;
		Ppos.y = Krochi::getPlayerPos().y + 35;

		if (EnemyPos.x > Ppos.x && !coll)
		{
			EnemyPos.x -= 45.0f * Time::getDeltaTime();
			EnemyAnimator->Play(L"LeftWalk", true);
		}
		if (EnemyPos.x < Ppos.x && !coll)
		{
			EnemyPos.x += 45.0f * Time::getDeltaTime();
			EnemyAnimator->Play(L"RightWalk", true);
		}
		if (EnemyPos.y > Ppos.y && !coll)
		{
			EnemyPos.y -= 45.0f * Time::getDeltaTime();
		}
		if (EnemyPos.y < Ppos.y && !coll)
		{
			EnemyPos.y += 45.0f * Time::getDeltaTime();
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
		coll = true;
	}

	void Enemy1::onCollisionStay(Collider* other)
	{
		coll = true;
	}

	void Enemy1::onCollisionExit(Collider* other)
	{
		coll = false;
	}
}