#include "myResourceManager.h"
#include "Krochi_after2.h"
#include "myInput.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")

extern my::Application myapplication;

namespace my
{
	Krochi_after2::Krochi_after2()
	{
		Right_after = Krochi::getDirect();
	}
	Krochi_after2::~Krochi_after2()
	{

	}
	void Krochi_after2::Initialize()
	{
		playerImg_RA1 = ResourceManager::Load<Image>(L"PlayerRA1", L"..\\Resources\\Player_RightAfter.bmp");
		playerImg_LA1 = ResourceManager::Load<Image>(L"PlayerLA1", L"..\\Resources\\Player_LeftAfter.bmp");
		playerImg_N = ResourceManager::Load<Image>(L"PlayerN", L"..\\Resources\\Player_None.bmp");

		Transform* tr = GetComponent<Transform>();
		afterPos.x = myapplication.getWindowPos().x / 2 - 30;
		afterPos.y = myapplication.getWindowPos().y / 2 - 30;

		tr->setPos(afterPos);

		playerAnimator = AddComponent<Animator>(); // �ִϸ����� ������Ʈ �迭�� �����Ҵ� �� �ʱ�ȭ
		playerAnimator->CreateAnimation(L"RightAfter", playerImg_RA1, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"RightIdleAfter", playerImg_RA1, Vector2::Zero, 3, 1, 1, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"LeftAfter", playerImg_LA1, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"LeftIdleAfter", playerImg_LA1, Vector2::Zero, 3, 1, 1, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"None", playerImg_N, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.3, 255, 0, 255);
		after_State = Krochi::ePlayerState::Idle;

		GameObject::Initialize();
	}
	void Krochi_after2::Update()
	{
		GameObject::Update();

		if (after_State == Krochi::ePlayerState::Idle)
		{
			idle();
		}
		if (after_State == Krochi::ePlayerState::Move)
		{
			move();
		}
	}

	void Krochi_after2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Krochi_after2::Release()
	{
		GameObject::Release();
	}
	void Krochi_after2::idle()
	{
		Right_after = Krochi::getDirect();

		Transform* tr = GetComponent<Transform>();
		afterPos = tr->getPos();

		if (afterPos.x < Krochi::getPlayerPos().x - 0.5)
		{
			afterPos.x += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.x > Krochi::getPlayerPos().x + 0.5)
		{
			afterPos.x -= 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y < Krochi::getPlayerPos().y - 0.5)
		{
			afterPos.y += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y > Krochi::getPlayerPos().y + 0.5)
		{
			afterPos.y -= 180.0f * Time::getDeltaTime();
		}
		else
			playerAnimator->Play(L"None", true);

		tr->setPos(afterPos);

		if (Krochi::getPlayerState() == Krochi::ePlayerState::Move)
		{
			after_State = Krochi::ePlayerState::Move;
		}
	}

	void Krochi_after2::move()
	{
		Right_after = Krochi::getDirect();

		Transform* tr = GetComponent<Transform>();

		if (afterPos.x < Krochi::getPlayerPos().x - 12)
		{
			afterPos.x += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.x > Krochi::getPlayerPos().x + 12)
		{
			afterPos.x -= 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y < Krochi::getPlayerPos().y - 12)
		{
			afterPos.y += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y > Krochi::getPlayerPos().y + 12)
		{
			afterPos.y -= 180.0f * Time::getDeltaTime();
		}

		tr->setPos(afterPos);

		if (Right_after)
			playerAnimator->Play(L"RightAfter", true);

		if (!Right_after)
			playerAnimator->Play(L"LeftAfter", true);

		if (Krochi::getPlayerState() == Krochi::ePlayerState::Idle)
		{
			after_State = Krochi::ePlayerState::Idle;
		}
	}
}