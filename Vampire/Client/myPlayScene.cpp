#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		enemyPool = new EnemyPool(30); // 100개의 적 객체를 미리 생성
																  // EnemyPool 클래스에서 가지고 있는 enemy배열에 100개의 객체를 동적 할당
	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		field = new Field(); // 배경 생성
		krochi = new Krochi(); // 플레이어 생성
		//enemy1->SetName(L"Enemy1");
		krochi->SetName(L"Player");
		field->SetName(L"Field");
		AddGameObj(field, eLayerType::FIELD);
		AddGameObj(krochi, eLayerType::PLAYER);

		for (int i = 0; i < 30; i++) {
			Enemy1* enemy1 = enemyPool->GetEnemy(); // 에너미 풀에 이미 동적할당되어져있는 100개의 에너미 객체로 하나씩 for문을 돌면서 초기화
			                                                                           // 그러니까 에너미 풀에 만들고자 하는 에너미 객체를 미리 만들어놓고 하나씩 대입시켜줌
			AddGameObj(enemy1, eLayerType::ENEMY);
		}

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::InGameMenu);
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::Release()
	{
		Scene::Release();
		delete enemyPool; // delete 에너미 풀을 하면 동적 할당한 에너미 객체들이 전부 사라짐
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{

	}
}