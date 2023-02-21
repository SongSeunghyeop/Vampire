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
		Dragon* dragon = new Dragon(); // 플레이어 생성
		AddGameObj(dragon, eLayerType::PLAYER);

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