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
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::Q) == eKeyState::Down)
		{
			/*CharactorSelect* cs = new CharactorSelect();
			AddGameObj(cs, eLayerType::UI);
			cs->Initialize();*/
			SceneManager::LoadScene(eSceneType::Play);
		}
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