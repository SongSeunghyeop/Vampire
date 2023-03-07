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
		int randomPos =  rand() % 300 + 700; // 1부터 1000 사이의 랜덤한 정수 생성
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
		Vector2 Enemy_Scale(0.8f, 0.8f);
		tr->setScale(Enemy_Scale);

		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(-28, -64));
		collider->setSize(Vector2(43, 50));

		GameObject::Initialize();
	}
	void Enemy1::Update()
	{
		Transform* tr = GetComponent<Transform>();
		EnemyPos = tr->getPos();
		Ppos.x = Krochi::getPlayerPos().x + 25;
		Ppos.y = Krochi::getPlayerPos().y + 30;

		if (EnemyPos.x > Ppos.x)
		{
			EnemyPos.x -= 30.0f * Time::getDeltaTime();
			EnemyAnimator->Play(L"LeftWalk", true);
		}
		if (EnemyPos.x < Ppos.x)
		{
			EnemyPos.x += 30.0f * Time::getDeltaTime();
			EnemyAnimator->Play(L"RightWalk", true);
		}
		if (EnemyPos.y > Ppos.y)
		{
			EnemyPos.y -= 30.0f * Time::getDeltaTime();
		}
		if (EnemyPos.y < Ppos.y)
		{
			EnemyPos.y += 30.0f * Time::getDeltaTime();
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
}