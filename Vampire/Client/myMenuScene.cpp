#include "myMenuScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Menu.h"

namespace my
{
	menuScene::menuScene()
	{

	}
	menuScene::~menuScene()
	{

	}
	void menuScene::Initialize()
	{
		Menu* menu = new Menu();
		menu->SetName(L"Title");
		AddGameObj(menu, eLayerType::UI);
		myScene::Initialize();
	}
	void menuScene::Update()
	{
		myScene::Update();

		if (Input::GetKeyState(KeyCode::ESC) == KeyState::Down)
		{
			mySceneManager::LoadScene(eSceneType::Play);
		}
	}
	void menuScene::Render(HDC hdc)
	{
		myScene::Render(hdc);
	}
	void menuScene::Release()
	{
		myScene::Release();
	}

	void menuScene::OnEnter()
	{

	}
	void menuScene::OnExit()
	{

	}
}