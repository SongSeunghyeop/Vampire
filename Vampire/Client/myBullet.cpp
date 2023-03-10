#include "myBullet.h"
#include "myTransform.h"
#include "Time.h"
#include "myObject.h"

namespace my
{
	BaseBullet::BaseBullet()
		: mTime(0.0f)
	{
	}
	BaseBullet::~BaseBullet()
	{
	}
	void BaseBullet::Initialize()
	{
		Bullet = ResourceManager::Load<Image>(L"BaseBullet", L"..\\Resources\\baseBullet.bmp");
		R = rand() % 360 + 1;
		Transform * tr = GetComponent<Transform>();
		bulletPos = tr->getPos();

		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(0, 0));
		collider->setSize(Vector2(32, 32));
		collider->setRGB(0, 0, 255);
		GameObject::Initialize();
	}
	void BaseBullet::Update()
	{
		/*float x = cosf(-PI / 4.0f);
		float y = sinf(-PI / 4.0f);*/
		//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
		//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);

		Vector2 dir = Vector2(500.0f, 500.0f);
		dir.Normalize();
		Vector2 ro = math::Rotate(dir, R);

		Transform* tr = GetComponent<Transform>();
		bulletPos.x += 200.0f * ro.x * Time::getDeltaTime();
		bulletPos.y += 200.0f * ro.y * Time::getDeltaTime();
		tr->setPos(bulletPos);

		mTime += Time::getDeltaTime();

		if (mTime >4.0f)
		{
			object::Destory(this);
		}
		GameObject::Update();
	}
	void BaseBullet::Render(HDC hdc)
	{
		TransparentBlt(hdc, bulletPos.x, bulletPos.y, Bullet->GetWidth() * 1.8, Bullet->GetHeight() * 1.7,Bullet->GetHdc(),0,0,
			Bullet->GetWidth(), Bullet->GetHeight(), RGB(255, 0, 255));

		GameObject::Render(hdc);
	}
	void BaseBullet::Release()
	{

	}
}
