#include "myIntroScene.h"
#include "mySceneManager.h"
#include "Intro.h"
#include "CharactorSelect.h"
#include "myCollisionManager.h"

namespace my
{

	IntroScene::IntroScene()
	{

	}
	IntroScene::~IntroScene()
	{

	}
	void IntroScene::Initialize()
	{
		object::Instantiate<Intro>(Vector2::Zero, eLayerType::BACKGROUND);
	}
	void IntroScene::Update()
	{
		Scene::Update();

		for (UINT i = 0; i < (UINT)eKeyCode::LBUTTON; i++)
		{
        	if (Input::GetKeyState((eKeyCode)i) == eKeyState::Down)
			{
				SceneManager::LoadScene(eSceneType::Title); // 바로 화면 전환
			}
		}
	}
	void IntroScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void IntroScene::Release()
	{
		Scene::Release();
	}

	void IntroScene::OnEnter()
	{

	}
	void IntroScene::OnExit()
	{

	}
}