#include "myMenuScene.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Menu.h"

namespace my
{
	MenuScene::MenuScene()
	{

	}
	MenuScene::~MenuScene()
	{

	}
	void MenuScene::Initialize()
	{
		Menu* menu = new Menu();
		menu->SetName(L"Title");
		AddGameObj(menu, eLayerType::UI);
		Scene::Initialize();
	}
	void MenuScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::ESC) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
		if (Input::GetKeyState(eKeyCode::Q) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}
	}
	void MenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void MenuScene::Release()
	{
		Scene::Release();
	}

	void MenuScene::OnEnter()
	{

	}
	void MenuScene::OnExit()
	{

	}
}