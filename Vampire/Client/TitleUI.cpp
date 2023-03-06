#include "TitleUI.h"
#include "myScene.h"
#include "mySceneManager.h"
#include "CharacterSelect.h"
#include "CharactorSelect.h"

namespace my
{
	TitleUI::TitleUI()
	{

	}
	TitleUI::~TitleUI()
	{

	}
	void TitleUI::Initialize()
	{
		CharacterSelect* cs = new CharacterSelect();
		cs->setName(L"Title");
		AddGameObj(cs, eLayerType::FIELD);
		Scene::Initialize();
	}
	void TitleUI::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (Input::GetKeyState((eKeyCode)i) == eKeyState::Down)
			{
				SceneManager::LoadScene(eSceneType::Play); // 바로 화면 전환
			}
		}
	}
	void TitleUI::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleUI::Release()
	{
		Scene::Release();
	}

	void TitleUI::OnEnter()
	{

	}
	void TitleUI::OnExit()
	{

	}
}