#include "mySceneManager.h"
#include "myPlayScene.h"
#include "myTitleScene.h"
#include "myMenuScene.h"

namespace my 
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::activeScene = {};

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // 할당을 해주고 전체를 0으로 초기화해준다 예를들어, resize(5,0)이면 5개의 배열을 0으로 초기화
																			 // 현재 max는 4개이므로 4개의 배열을 0으로 초기화
		mScenes[(UINT)eSceneType::Title] = new TitleScene(); // 플레이 씬부터 동적할당
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); // 플레이 씬부터 동적할당
		mScenes[(UINT)eSceneType::Menu] = new MenuScene(); // 플레이 씬부터 동적할당
		mScenes[(UINT)eSceneType::Title]->SetName(L"TITLE");
		mScenes[(UINT)eSceneType::Play]->SetName(L"PLAY");
		mScenes[(UINT)eSceneType::Menu]->SetName(L"MENU");

		activeScene = mScenes[(UINT)eSceneType::Title];

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
	void SceneManager::LoadScene(eSceneType type)
	{
		activeScene->OnExit();
		activeScene = mScenes[(UINT)type];
		activeScene->OnEnter();
	}
}
