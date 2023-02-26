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
		if (Input::GetKeyState(eKeyCode::Q) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
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