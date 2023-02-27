#include "myIntroScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Intro.h"
#include "CharactorSelect.h"

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
		Intro* intro = new Intro();
		intro->SetName(L"Title");
		AddGameObj(intro, eLayerType::FIELD);
		Scene::Initialize();
	}
	void IntroScene::Update()
	{
		Scene::Update();

		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
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