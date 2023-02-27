#include "myTitleScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Title.h"
#include "CharactorSelect.h"

namespace my
{
	TitleScene::TitleScene()
	{

	}
	TitleScene::~TitleScene()
	{

	}
	void TitleScene::Initialize()
	{
		Title *title = new Title();
		title->SetName(L"Title");
		AddGameObj(title, eLayerType::FIELD);
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (Input::GetKeyState((eKeyCode)i) == eKeyState::Down)
			{
				SceneManager::LoadScene(eSceneType::TitleUI); // 바로 화면 전환
			}
		}

		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::Release()
	{
		Scene::Release();
	}

	void TitleScene::OnEnter()
	{

	}
	void TitleScene::OnExit()
	{

	}
}