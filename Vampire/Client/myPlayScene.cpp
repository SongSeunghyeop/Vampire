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
		dragon = new Dragon(); // 플레이어 생성
		Field* field = new Field(); // 배경 생성
		dragon->SetName(L"Player");
		field->SetName(L"Field");
		AddGameObj(field, eLayerType::FIELD);
		AddGameObj(dragon, eLayerType::PLAYER);

		myScene::Initialize();
	}
	void PlayScene::Update()
	{
		myScene::Update();

		if (Input::GetKeyState(KeyCode::ESC) == KeyState::Down)
		{
			mySceneManager::LoadScene(eSceneType::Menu);
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		myScene::Render(hdc);
	}
	void PlayScene::Release()
	{
		myScene::Release();
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{

	}
}