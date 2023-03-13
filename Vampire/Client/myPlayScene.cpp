#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{
		//enemyPool = new EnemyPool(2); // 100���� �� ��ü�� �̸� ����
																  // EnemyPool Ŭ�������� ������ �ִ� enemy�迭�� 100���� ��ü�� ���� �Ҵ�
	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		Krochi *krochi = object::Instantiate<Krochi>(Vector2::Zero, eLayerType::PLAYER);
		object::Instantiate<Field>(Vector2::Zero, eLayerType::BACKGROUND);
		object::Instantiate<Krochi_after>(Vector2::Zero, eLayerType::PLAYERAFTER);
		object::Instantiate<Krochi_after2>(Vector2::Zero, eLayerType::PLAYERAFTER);
		object::Instantiate<Level_bar>(Vector2::Zero, eLayerType::UI);
		object::Instantiate<Enemy1>(Vector2::Zero, eLayerType::ENEMY);
		object::Instantiate<Enemy1>(Vector2(500.0f,500.0f), eLayerType::ENEMY);
		Camera::setTarget(krochi);


		//for (int i = 0; i < 2; i++) {
		//	Enemy1* enemy = enemyPool->GetEnemy(); // ���ʹ� Ǯ�� �̹� �����Ҵ�Ǿ����ִ� 100���� ���ʹ� ��ü�� �ϳ��� for���� ���鼭 �ʱ�ȭ
		//	                                                                           // �׷��ϱ� ���ʹ� Ǯ�� ������� �ϴ� ���ʹ� ��ü�� �̸� �������� �ϳ��� ���Խ�����
		//	enemy->setName(L"Enemy");
		//	AddGameObj(enemy, eLayerType::ENEMY);
		//	enemy->Initialize();
		//}
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
			//object::Instantiate<BaseBullet>(Krochi::getPlayerPos(), eLayerType::EFFECT);
			object::Instantiate<BaseSkill>(Krochi::getPlayerPos() + Vector2(10.0f,0.0f), eLayerType::EFFECT);
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
	}
	void PlayScene::OnEnter()
	{
		CollisionManager::setLayer(eLayerType::PLAYER, eLayerType::ENEMY, true);
		CollisionManager::setLayer(eLayerType::ENEMY, eLayerType::EFFECT, true);
		CollisionManager::setLayer(eLayerType::ENEMY, eLayerType::ENEMY, true);

	}
	void PlayScene::OnExit()
	{

	}
}