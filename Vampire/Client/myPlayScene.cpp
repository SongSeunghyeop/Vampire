#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		enemyPool = new EnemyPool(10); // 100���� �� ��ü�� �̸� ����
																  // EnemyPool Ŭ�������� ������ �ִ� enemy�迭�� 100���� ��ü�� ���� �Ҵ�
	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		field = new Field(); // ��� ����
		krochi = new Krochi(); // �÷��̾� ����
		krochi_after = new Krochi_after(); // �÷��̾� ����
		krochi_after2 = new Krochi_after2(); // �÷��̾� ����
		//enemy1->SetName(L"Enemy1");
		krochi->setName(L"Player");
		field->setName(L"Field");
		AddGameObj(field, eLayerType::FIELD);
		AddGameObj(krochi, eLayerType::PLAYER);
		AddGameObj(krochi_after, eLayerType::PLAYER_AFTER);
		AddGameObj(krochi_after2, eLayerType::PLAYER_AFTER2);

		for (int i = 0; i < 10; i++) {
			Enemy1* enemy1 = enemyPool->GetEnemy(); // ���ʹ� Ǯ�� �̹� �����Ҵ�Ǿ����ִ� 100���� ���ʹ� ��ü�� �ϳ��� for���� ���鼭 �ʱ�ȭ
			                                                                           // �׷��ϱ� ���ʹ� Ǯ�� ������� �ϴ� ���ʹ� ��ü�� �̸� �������� �ϳ��� ���Խ�����
			AddGameObj(enemy1, eLayerType::ENEMY);
		}

		CollisionManager::setLayer(eLayerType::PLAYER, eLayerType::ENEMY, true);

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