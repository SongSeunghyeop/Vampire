#include "myResourceManager.h"
#include "Enemy1.h"
#include "Time.h"
#include "myInput.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")
namespace my
{
	Enemy1::Enemy1()
	{
		EnemyPos.x = 1000;
		EnemyPos.y = 500;
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
		GameObject::Update();

		//Transform* trans = GetComponent<Transform>();

		//trans->setPos(1000,500);
		//Vector2 pos = trans->getPos();
		
		EnemyPos.x -= 50.0f * Time::getDeltaTime();
		EnemyPos.y -= 50.0f * Time::getDeltaTime();

		//trans->setPos(pos.x, pos.y);
	}
	void Enemy1::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		//Transform* trans = GetComponent<Transform>();
		//Vector2 pos = trans->getPos();
		TransparentBlt(hdc, EnemyPos.x, EnemyPos.y, 68,68, Enemy1_Img->GetHdc(), 0, 0, Enemy1_Img->GetWidth(), Enemy1_Img->GetHeight(), RGB(32, 32, 32));
		//그려줄 HDC, 그림 시작 위치, 그림 그릴 크기, 백버퍼의 HDC, 복사할 그림의 시작 위치, 복사할 그림의 크기, 투명처리할 색깔
	}
	void Enemy1::Release()
	{
		GameObject::Release();
	}
}