#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		enemyPool = new EnemyPool(30); // 100���� �� ��ü�� �̸� ����
																  // EnemyPool Ŭ�������� ������ �ִ� enemy�迭�� 100���� ��ü�� ���� �Ҵ�
	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		field = new Field(); // ��� ����
		krochi = new Krochi(); // �÷��̾� ����
		//enemy1->SetName(L"Enemy1");
		krochi->SetName(L"Player");
		field->SetName(L"Field");
		AddGameObj(field, eLayerType::FIELD);
		AddGameObj(krochi, eLayerType::PLAYER);

		for (int i = 0; i < 30; i++) {
			Enemy1* enemy1 = enemyPool->GetEnemy(); // ���ʹ� Ǯ�� �̹� �����Ҵ�Ǿ����ִ� 100���� ���ʹ� ��ü�� �ϳ��� for���� ���鼭 �ʱ�ȭ
			                                                                           // �׷��ϱ� ���ʹ� Ǯ�� ������� �ϴ� ���ʹ� ��ü�� �̸� �������� �ϳ��� ���Խ�����
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
		delete enemyPool; // delete ���ʹ� Ǯ�� �ϸ� ���� �Ҵ��� ���ʹ� ��ü���� ���� �����
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{

	}
}