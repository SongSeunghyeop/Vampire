#include "InGameOption.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "Menu.h"

namespace my
{
	InGameOption::InGameOption()
	{

	}
	InGameOption::~InGameOption()
	{

	}
	void InGameOption::Initialize()
	{
		Menu* menu = new Menu();
		menu->SetName(L"Title");
		AddGameObj(menu, eLayerType::UI);
		Scene::Initialize();
	}
	void InGameOption::Update()
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
	void InGameOption::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void InGameOption::Release()
	{
		Scene::Release();
	}

	void InGameOption::OnEnter()
	{

	}
	void InGameOption::OnExit()
	{

	}
}