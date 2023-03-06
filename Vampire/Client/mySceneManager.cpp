#include "mySceneManager.h"
#include "myPlayScene.h"
#include "myTitleScene.h"
#include "myIntroScene.h"
#include "TitleUI.h"
#include "InGameOption.h"

namespace my 
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::activeScene = {};

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // 할당을 해주고 전체를 0으로 초기화해준다 예를들어, resize(5,0)이면 5개의 배열을 0으로 초기화
																			 // 현재 max는 4개이므로 4개의 배열을 0으로 초기화
		mScenes[(UINT)eSceneType::Intro] = new IntroScene(); 
		mScenes[(UINT)eSceneType::Title] = new TitleScene(); 
		mScenes[(UINT)eSceneType::TitleUI] = new TitleUI(); 
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); 
		mScenes[(UINT)eSceneType::InGameMenu] = new InGameOption(); 

		mScenes[(UINT)eSceneType::Intro]->setName(L"INTRO");
		mScenes[(UINT)eSceneType::Title]->setName(L"TITLE");
		mScenes[(UINT)eSceneType::TitleUI]->setName(L"TITLEUI");
		mScenes[(UINT)eSceneType::Play]->setName(L"PLAY");
		mScenes[(UINT)eSceneType::InGameMenu]->setName(L"MENU");

		activeScene = mScenes[(UINT)eSceneType::Intro];

		for (Scene* scene : mScenes)
		{
			if (scene == NULL) continue;
			scene->Initialize();
 		}
	}

	void SceneManager::Update()
	{	
		activeScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Release();
		}
	}
	void SceneManager::LoadScene(eSceneType type) // 업데이트,렌더러의 대상을 바꾸어줌
	{
		//activeScene->OnExit();
		activeScene = mScenes[(UINT)type];
		//activeScene->OnEnter();
	}
}
