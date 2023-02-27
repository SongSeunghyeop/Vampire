#include "myPlayScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "myInput.h"

namespace my
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		krochi = new Krochi(); // 플레이어 생성
		enemy1 = new Enemy1(); // 에너미 생성
		field = new Field(); // 배경 생성

		krochi->SetName(L"Player");
		enemy1->SetName(L"Enemy1");
		field->SetName(L"Field");
		AddGameObj(field, eLayerType::FIELD);
		AddGameObj(enemy1, eLayerType::ENEMY);
		AddGameObj(krochi, eLayerType::PLAYER);

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
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{

	}
}