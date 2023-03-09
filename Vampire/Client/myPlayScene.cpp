#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		enemyPool = new EnemyPool(2); // 100���� �� ��ü�� �̸� ����
																  // EnemyPool Ŭ�������� ������ �ִ� enemy�迭�� 100���� ��ü�� ���� �Ҵ�
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
			Enemy1* enemy = enemyPool->GetEnemy(); // ���ʹ� Ǯ�� �̹� �����Ҵ�Ǿ����ִ� 100���� ���ʹ� ��ü�� �ϳ��� for���� ���鼭 �ʱ�ȭ
			                                                                           // �׷��ϱ� ���ʹ� Ǯ�� ������� �ϴ� ���ʹ� ��ü�� �̸� �������� �ϳ��� ���Խ�����
			enemy->setName(L"Enemy");
			AddGameObj(enemy, eLayerType::ENEMY);
			enemy->Initialize();
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Option);
			Input::SetKeyState(eKeyCode::ESC, eKeyState::None);
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
		CollisionManager::setLayer(eLayerType::PLAYER, eLayerType::ENEMY, true);
		//CollisionManager::setLayer(eLayerType::ENEMY, eLayerType::ENEMY, true);
	}
	void PlayScene::OnExit()
	{

	}
}