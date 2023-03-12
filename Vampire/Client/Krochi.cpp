#include "myResourceManager.h"
#include "Krochi.h"
#include "myInput.h"
#include "myImage.h"
#include "myPlayScene.h"

#pragma comment(lib, "msimg32.lib")

extern my::Application myapplication;
namespace my
{
	Vector2 Krochi::Playerpos;
	bool Krochi::Player_coll;

	Krochi::Krochi()
	{

	}
	Krochi::~Krochi()
	{

	}
	void Krochi::Initialize()
	{
		playerImg_R = ResourceManager::Load<Image>(L"PlayerR1", L"..\\Resources\\Player_RightRun.bmp");
		playerImg_L = ResourceManager::Load<Image>(L"PlayerL1", L"..\\Resources\\Player_LeftRun.bmp");
		damaged_R = ResourceManager::Load<Image>(L"damaged_R", L"..\\Resources\\Collision_RightRun.bmp");
		damaged_L = ResourceManager::Load<Image>(L"damaged_L", L"..\\Resources\\Collision_LeftRun.bmp");

		playerAnimator = AddComponent<Animator>(); // 애니메이터 컴포넌트 배열에 동적할당 및 초기화
		playerAnimator->CreateAnimation(L"Idle_R", playerImg_R, Vector2::Zero, 3,1,1, 0.3f,255,0,255); // 스프라이트 배열로 쪼개진 하나의 애니메이션 생성
		playerAnimator->CreateAnimation(L"Idle_L", playerImg_L, Vector2::Zero, 3, 1, 1, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"RightRun", playerImg_R, Vector2::Zero, 3,1,3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"LeftRun", playerImg_L, Vector2::Zero, 3,1,3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"Damaged_IdleR", damaged_R, Vector2::Zero, 3,1,1, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"Damaged_IdleL", damaged_L, Vector2::Zero, 3,1,1, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"Damaged_RunR", damaged_R, Vector2::Zero, 3,1,3, 0.3f, 255, 0, 255);
		playerAnimator->CreateAnimation(L"Damaged_RunL", damaged_L, Vector2::Zero, 3,1,3, 0.3f, 255, 0, 255);
		
		Transform* tr = GetComponent<Transform>();
		Playerpos = myapplication.getWindowPos() / 2;
   		tr->setPos(Playerpos);
		//Playerpos = tr->getPos();
		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(-13,-34));
		collider->setRGB(255, 0, 255);

		Right = true;
		PlayScene::player_health = 112;
		mState = ePlayerState::Idle;

		playerAnimator->Play(L"Idle_R", true);

		GameObject::Initialize();
	}
	void Krochi::Update()
	{
		switch (mState)
		{
		case my::Krochi::ePlayerState::Move:
			move();
			break;
		case my::Krochi::ePlayerState::Idle:
			idle();
			break;
		default:
			break;
		}
		GameObject::Update();
	}

	void Krochi::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Krochi::Release()
	{
		GameObject::Release();
	}
	void Krochi::idle()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();

		if (Right && !Krochi::Player_coll)
			playerAnimator->Play(L"Idle_R", true);
		if (!Right && !Krochi::Player_coll)
			playerAnimator->Play(L"Idle_L", true);
		if (Right && Krochi::Player_coll)
			playerAnimator->Play(L"Damaged_IdleR", true);
		if (!Right && Krochi::Player_coll)
			playerAnimator->Play(L"Damaged_IdleL", true);

		if (Input::GetKey(eKeyCode::A) || Input::GetKeyDown(eKeyCode::A))
		{
			Right = false;
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKeyDown(eKeyCode::D))
		{
			Right = true;
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::W) || Input::GetKeyDown(eKeyCode::W))
		{
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKeyDown(eKeyCode::S))
		{
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::A) && Input::GetKey(eKeyCode::D))
		{
			mState = ePlayerState::Idle;
		}
	}

	void Krochi::move()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();

		if (Right && !Krochi::Player_coll)
			playerAnimator->Play(L"RightRun", true);
		if(!Right && !Krochi::Player_coll)
			playerAnimator->Play(L"LeftRun", true);
		if (Right && Krochi::Player_coll)
			playerAnimator->Play(L"Damaged_RunR", true);
		if (!Right && Krochi::Player_coll)
			playerAnimator->Play(L"Damaged_RunL", true);

		if (Input::GetKeyUp(eKeyCode::A))
		{
			Right = false;
			mState = ePlayerState::Idle;
		}
		if (Input::GetKeyUp(eKeyCode::D))
		{
			Right = true;
			mState = ePlayerState::Idle;
		}
		if (Input::GetKeyUp(eKeyCode::W))
		{
			mState = ePlayerState::Idle;
		}
		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = ePlayerState::Idle;
		}
		
		if (Input::GetKey(eKeyCode::A) && Playerpos.x > 440)
		{
			Right = false;
			Playerpos.x -= 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::D) && Playerpos.x < 990)
		{
			Right = true;
			Playerpos.x += 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::W) && Playerpos.y > -150)
		{
			Playerpos.y -= 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::S) && Playerpos.y < 1199)
		{
			Playerpos.y += 180.0f * Time::getDeltaTime();
		}

	
		if (Input::GetKey(eKeyCode::A) && Input::GetKey(eKeyCode::D))
		{
			mState = ePlayerState::Idle;
		}

		tr->setPos(Playerpos);
	}

	void Krochi::onCollisionEnter(Collider* other)
	{
		Krochi::Player_coll = true;
	}

	void Krochi::onCollisionStay(Collider* other)
	{
		Krochi::Player_coll = true;
		PlayScene::player_health -= Time::getDeltaTime() * 7.0f;
	}
	
	void Krochi::onCollisionExit(Collider* other)
	{
		Krochi::Player_coll = false;
	}
}