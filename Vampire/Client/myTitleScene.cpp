#include "myTitleScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Title.h"

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
		myScene::Initialize();
	}
	void TitleScene::Update()
	{
		myScene::Update();

		if (Input::GetKeyState(KeyCode::Q) == KeyState::Down)
		{
			mySceneManager::LoadScene(eSceneType::Play);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		myScene::Render(hdc);
	}
	void TitleScene::Release()
	{
		myScene::Release();
	}

	void TitleScene::OnEnter()
	{

	}
	void TitleScene::OnExit()
	{

	}
}