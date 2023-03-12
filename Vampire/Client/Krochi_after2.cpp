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
		Right_after = Krochi::getPlayerDirect();
	}
	Krochi_after2::~Krochi_after2()
	{

	}
	void Krochi_after2::Initialize()
	{
		playerImg_RA1 = ResourceManager::Load<Image>(L"PlayerRA1", L"..\\Resources\\Player_RightAfter.bmp");
		playerImg_LA1 = ResourceManager::Load<Image>(L"PlayerLA1", L"..\\Resources\\Player_LeftAfter.bmp");
		playerImg_N = ResourceManager::Load<Image>(L"PlayerN", L"..\\Resources\\Player_None.bmp");
		Damaged_R = ResourceManager::Load<Image>(L"DamagedAfter_R", L"..\\Resources\\Coll_RightAfter.bmp");
		Damaged_L = ResourceManager::Load<Image>(L"DamagedAfter_L", L"..\\Resources\\Coll_LeftAfter.bmp");

		Transform* tr = GetComponent<Transform>();
		tr->setPos(Krochi::getPlayerPos());

		playerAnimator = AddComponent<Animator>(); // 애니메이터 컴포넌트 배열에 동적할당 및 초기화
		playerAnimator->CreateAnimation(L"RightAfter", playerImg_RA1, Vector2::Zero, 3, 1, 3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"LeftAfter", playerImg_LA1, Vector2::Zero, 3, 1, 3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"None", playerImg_N, Vector2::Zero, 1, 1, 1, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"DamagedAfter_R", Damaged_R, Vector2::Zero, 3, 1, 3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"DamagedAfter_L", Damaged_L, Vector2::Zero, 3, 1, 3, 0.3f, 255, 0, 255);

		after_State = Krochi::ePlayerState::Idle;

		GameObject::Initialize();
	}
	void Krochi_after2::Update()
	{
		if (after_State == Krochi::ePlayerState::Idle)
		{
			idle();
		}
		if (after_State == Krochi::ePlayerState::Move)
		{
			move();
			delay = 0.0f;
		}
		GameObject::Update();
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

		tr->setPos(afterPos);

		while (delay <= 0.1f)
		{
			delay += 0.4 * Time::getDeltaTime();
		}
		playerAnimator->Play(L"None", true);

		if (Krochi::getPlayerState() == Krochi::ePlayerState::Move)
		{
			after_State = Krochi::ePlayerState::Move;
		}
	}

	void Krochi_after2::move()
	{
		Right_after = Krochi::getPlayerDirect();

		if (Right_after && !(Krochi::getPlayerColl()))
			playerAnimator->Play(L"RightAfter", true);

		if (!Right_after && !(Krochi::getPlayerColl()))
			playerAnimator->Play(L"LeftAfter", true);

		if (Right_after && (Krochi::getPlayerColl()))
			playerAnimator->Play(L"DamagedAfter_R", true);

		if (!Right_after && (Krochi::getPlayerColl()))
			playerAnimator->Play(L"DamagedAfter_L", true);


		Transform* tr = GetComponent<Transform>();

		if (afterPos.x < Krochi::getPlayerPos().x - 10)
		{
			afterPos.x += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.x > Krochi::getPlayerPos().x + 10)
		{
			afterPos.x -= 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y < Krochi::getPlayerPos().y - 10)
		{
			afterPos.y += 180.0f * Time::getDeltaTime();
		}
		if (afterPos.y > Krochi::getPlayerPos().y + 10)
		{
			afterPos.y -= 180.0f * Time::getDeltaTime();
		}

		tr->setPos(afterPos);

		if (Krochi::getPlayerState() == Krochi::ePlayerState::Idle)
		{
			after_State = Krochi::ePlayerState::Idle;
		}
	}
}