#include "myResourceManager.h"
#include "Enemy1.h"
#include "Time.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")
namespace my
{
	Vector2 Enemy1::getRandomPos()
	{
		static bool initialized = false;

		if (!initialized) {
			srand(time(NULL)); // 처음 한 번만 호출
			initialized = true;
		}
		Vector2 randomPos;
		randomPos.x = rand() % 1100 + 301; // 1부터 1000 사이의 랜덤한 정수 생성
		randomPos.y = rand() % 750 + 1;// 1부터 1000 사이의 랜덤한 정수 생성
		return randomPos;
	}

	Enemy1::Enemy1()
	{
		Vector2 rand = getRandomPos();

		EnemyPos = rand;
	}
	Enemy1::~Enemy1()
	{

	}
	void Enemy1::Initialize()
	{
		Enemy1_Img = ResourceManager::Load<Image>(L"Enemy1", L"..\\Resources\\Enemy1.bmp");
		GameObject::Initialize();
	}
	void Enemy1::Update()
	{
		Ppos = Krochi::getPlayerPos();

		GameObject::Update();

		if(EnemyPos.x > Ppos.x)
			EnemyPos.x -= 40.0f * Time::getDeltaTime();
		else if (EnemyPos.x < Ppos.x)
			EnemyPos.x += 40.0f * Time::getDeltaTime();
		if (EnemyPos.y > Ppos.y)
			EnemyPos.y -= 40.0f * Time::getDeltaTime();
		else if (EnemyPos.y < Ppos.y)
			EnemyPos.y += 40.0f * Time::getDeltaTime();

	}
	void Enemy1::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		TransparentBlt(hdc, EnemyPos.x, EnemyPos.y, 68,68, Enemy1_Img->GetHdc(), 0, 0, Enemy1_Img->GetWidth(), Enemy1_Img->GetHeight(), RGB(32, 32, 32));
	}
	void Enemy1::Release()
	{
		GameObject::Release();
	}
}