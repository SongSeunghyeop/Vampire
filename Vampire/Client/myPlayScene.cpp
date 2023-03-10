#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		enemyPool = new EnemyPool(2); // 100개의 적 객체를 미리 생성
																  // EnemyPool 클래스에서 가지고 있는 enemy배열에 100개의 객체를 동적 할당
	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		object::Instantiate<Field>(Vector2::Zero, eLayerType::BACKGROUND);
		object::Instantiate<Krochi>(Vector2::Zero, eLayerType::PLAYER);
		object::Instantiate<Krochi_after>(Vector2::Zero, eLayerType::PLAYERAFTER);
		object::Instantiate<Krochi_after2>(Vector2::Zero, eLayerType::PLAYERAFTER);

		for (int i = 0; i < 2; i++) {
			Enemy1* enemy = enemyPool->GetEnemy(); // 에너미 풀에 이미 동적할당되어져있는 100개의 에너미 객체로 하나씩 for문을 돌면서 초기화
			                                                                           // 그러니까 에너미 풀에 만들고자 하는 에너미 객체를 미리 만들어놓고 하나씩 대입시켜줌
			enemy->setName(L"Enemy");
			AddGameObj(enemy, eLayerType::ENEMY);
			enemy->Initialize();
		}

		pTime = 0.0f;
	}

	void PlayScene::Update()
	{
		pTime += 0.01f * Time::getDeltaTime();

		if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Option);
			Input::SetKeyState(eKeyCode::ESC, eKeyState::None);
		}
		
		if (pTime >= 0.02f)
		{
			object::Instantiate<BaseBullet>(Krochi::getPlayerPos(), eLayerType::EFFECT);
			pTime = 0.0f;
		}

		Scene::Update();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		Scene::Destroy();
	}
	void PlayScene::Release()
	{
		Scene::Release();
		delete enemyPool; // delete 에너미 풀을 하면 동적 할당한 에너미 객체들이 전부 사라짐
	}
	void PlayScene::OnEnter()
	{
		CollisionManager::setLayer(eLayerType::PLAYER, eLayerType::ENEMY, true);
		CollisionManager::setLayer(eLayerType::ENEMY, eLayerType::EFFECT, true);
	}
	void PlayScene::OnExit()
	{

	}
}