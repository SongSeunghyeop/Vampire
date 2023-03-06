#include "myResourceManager.h"
#include "Krochi.h"
#include "myInput.h"
#include "myImage.h"

#pragma comment(lib, "msimg32.lib")

extern my::Application myapplication;
namespace my
{
	Vector2 Krochi::Playerpos;

	Krochi::Krochi()
	{
		Right = true;
	}
	Krochi::~Krochi()
	{

	}
	void Krochi::Initialize()
	{
		playerImg_R = ResourceManager::Load<Image>(L"PlayerR1", L"..\\Resources\\Player_RightRun.bmp");
		playerImg_L = ResourceManager::Load<Image>(L"PlayerL1", L"..\\Resources\\Player_LeftRun.bmp");

		Transform* tr = GetComponent<Transform>();
		winPos.x = myapplication.getWindowPos().x / 2 - 30;
		winPos.y = myapplication.getWindowPos().y / 2 - 30;
    	tr->setPos(winPos);
		Playerpos = tr->getPos();
		playerAnimator = AddComponent<Animator>(); // 애니메이터 컴포넌트 배열에 동적할당 및 초기화
		playerAnimator->CreateAnimation(L"Idle_R", playerImg_R, Vector2::Zero, 3,1,1, Vector2::Zero, 0.3,255,0,255); // 스프라이트 배열로 쪼개진 하나의 애니메이션 생성
		playerAnimator->CreateAnimation(L"Idle_L", playerImg_L, Vector2::Zero, 3, 1, 1, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"RightRun", playerImg_R, Vector2::Zero, 3,1,3, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->CreateAnimation(L"LeftRun", playerImg_L, Vector2::Zero, 3,1,3, Vector2::Zero, 0.3, 255, 0, 255);
		playerAnimator->Play(L"Idle_R", true);
		mState = ePlayerState::Idle;

		Collider* collider = AddComponent<Collider>();
		collider->setCenter(Vector2(-13,-33));
		collider->setRGB(255, 0, 255);

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

		if (Right)
			playerAnimator->Play(L"Idle_R", true);
		if (!Right)
			playerAnimator->Play(L"Idle_L", true);

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
	}

	void Krochi::move()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();

		if (Right)
		{
			playerAnimator->Play(L"RightRun", true);
		}
		if(!Right)
			playerAnimator->Play(L"LeftRun", true);

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

		if (Input::GetKey(eKeyCode::A))
		{
			Right = false;
			Playerpos.x -= 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			Right = true;
			Playerpos.x += 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			Playerpos.y -= 180.0f * Time::getDeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			Playerpos.y += 180.0f * Time::getDeltaTime();
		}

		tr->setPos(Playerpos);
	}
}