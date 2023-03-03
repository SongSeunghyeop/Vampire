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

	}
	Krochi::~Krochi()
	{

	}

	void Krochi::Initialize()
	{
		playerImg_R = ResourceManager::Load<Image>(L"Player", L"..\\Resources\\Player_1_R.bmp");
		playerImg_L = ResourceManager::Load<Image>(L"Player2", L"..\\Resources\\Player_1_L.bmp");
		Transform* tr = GetComponent<Transform>();

		winPos.x = myapplication.getWindowPos().x / 2;
		winPos.y = myapplication.getWindowPos().y / 2;
		tr->setPos(winPos);

		playerAnimator = AddComponent<Animator>(); // 애니메이터 컴포넌트 배열에 동적할당 및 초기화
		playerAnimator->CreateAnimation(L"Idle_R", playerImg_R, Vector2::Zero, 3,1,1, Vector2::Zero, 0.3); // 스프라이트 배열로 쪼개진 하나의 애니메이션 생성
		playerAnimator->CreateAnimation(L"Idle_L", playerImg_L, Vector2::Zero, 3,1,1, Vector2::Zero, 0.3);
		playerAnimator->CreateAnimation(L"RightRun", playerImg_R, Vector2::Zero, 3,1,3, Vector2::Zero, 0.3);
		playerAnimator->CreateAnimation(L"LeftRun", playerImg_L, Vector2::Zero, 3,1,3, Vector2::Zero, 0.3);

		playerAnimator->Play(L"Idle_R", true);
		mState = ePlayerState::Idle;

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-10.0f,-33.0f));

		GameObject::Initialize();
	}
	void Krochi::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case my::Krochi::ePlayerState::Move:
			move_R();
			break;
		case my::Krochi::ePlayerState::Shoot:
			shoot();
			break;
		case my::Krochi::ePlayerState::Death:
			death();
			break;
		case my::Krochi::ePlayerState::Idle:
			idle_R();
			break;
		default:
			break;
		}
	}

	void Krochi::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Krochi::Release()
	{
		GameObject::Release();
	}
	void Krochi::move_R()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();
		playerAnimator->Play(L"RightRun", true);

		if (Input::GetKeyUp(eKeyCode::D)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyUp(eKeyCode::A))
		{
			mState = ePlayerState::Idle;
			//mAnimator->Play(L"Idle", true);
		}

		if (Input::GetKey(eKeyCode::A))
			Playerpos.x -= 180.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::D))
			Playerpos.x += 180.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::W))
			Playerpos.y -= 180.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::S))
			Playerpos.y += 180.0f * Time::getDeltaTime();

		tr->setPos(Playerpos);
	}
	void Krochi::move_L()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();
		playerAnimator->Play(L"LeftRun", true);

		if (Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyUp(eKeyCode::D))
		{
			mState = ePlayerState::Idle;
			//mAnimator->Play(L"Idle", true);
		}

		if (Input::GetKey(eKeyCode::A))
			Playerpos.x -= 200.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::D))
			Playerpos.x += 200.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::W))
			Playerpos.y -= 200.0f * Time::getDeltaTime();

		if (Input::GetKey(eKeyCode::S))
			Playerpos.y += 200.0f * Time::getDeltaTime();

		tr->setPos(Playerpos);
	}
	void Krochi::shoot()
	{
		/*Transform* tr = GetComponent<Transform>();
		if (Input::GetKey(eKeyCode::K))
		{
			Scene* curScene = SceneManager::GetActiveScene();
			BaseBullet* bullet = new BaseBullet();
			bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
			curScene->AddGameObeject(bullet, eLayerType::Bullet);
		}*/
	}

	void Krochi::death()
	{

	}
	void Krochi::idle_R()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();
		playerAnimator->Play(L"Idle_R", true);

		if (   Input::GetKey(eKeyCode::D) || Input::GetKeyDown(eKeyCode::D)
			|| Input::GetKey(eKeyCode::S) || Input::GetKeyDown(eKeyCode::S)
			|| Input::GetKey(eKeyCode::W) || Input::GetKeyDown(eKeyCode::W)
			|| Input::GetKey(eKeyCode::A) || Input::GetKeyDown(eKeyCode::A))
		{
			mState = ePlayerState::Move;
			//mAnimator->Play(L"FowardRun", true);
		}

		if (Input::GetKeyDown(eKeyCode::K))
		{
			/*mState = ePlayerState::Shoot;
			playerAnimator->Play(L"AimStraight", true);*/
		}
	}
	void Krochi::idle_L()
	{
		Transform* tr = GetComponent<Transform>();
		Playerpos = tr->getPos();
		playerAnimator->Play(L"Idle_L", true);


		if (Input::GetKey(eKeyCode::A) || Input::GetKeyDown(eKeyCode::A)
			|| Input::GetKey(eKeyCode::S) || Input::GetKeyDown(eKeyCode::S)
			|| Input::GetKey(eKeyCode::W) || Input::GetKeyDown(eKeyCode::W)
			|| Input::GetKey(eKeyCode::D) || Input::GetKeyDown(eKeyCode::D))
		{
			mState = ePlayerState::Move;
			//mAnimator->Play(L"FowardRun", true);
		}

		if (Input::GetKeyDown(eKeyCode::K))
		{
			/*mState = ePlayerState::Shoot;
			playerAnimator->Play(L"AimStraight", true);*/
		}
	}
}