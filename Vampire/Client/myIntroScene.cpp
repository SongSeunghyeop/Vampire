#include "myIntroScene.h"
#include "myScene.h"
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
		Intro* intro = new Intro();
		intro->setName(L"Intro");
		AddGameObj(intro, eLayerType::BACKGROUND);
		Scene::Initialize();
	}
	void IntroScene::Update()
	{
		Scene::Update();

		for (UINT i = 0; i < (UINT)eKeyCode::LBUTTON; i++)
		{
        	if (Input::GetKeyState((eKeyCode)i) == eKeyState::Down)
			{
				SceneManager::LoadScene(eSceneType::Title); // �ٷ� ȭ�� ��ȯ
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