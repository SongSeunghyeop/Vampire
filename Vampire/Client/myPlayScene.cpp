#include "myPlayScene.h"
#include "myScene.h"
#include "Dragon.h"

namespace ya
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		for (int i = 0; i < 3; i++)
		{
		Dragon* dragon = new Dragon(); // 플레이어 생성
		dragon->SetName(L"Player");
		AddGameObj(dragon, eLayerType::PLAYER);
		}

		myScene::Initialize();
	}
	void PlayScene::Update()
	{
		myScene::Update();
	}
	void PlayScene::Render(HDC hdc)
	{
		myScene::Render(hdc);
	}
	void PlayScene::Release()
	{
		myScene::Release();
	}
}