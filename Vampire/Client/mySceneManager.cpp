#include "mySceneManager.h"
#include "myIntroScene.h"
#include "myTitleScene.h"
#include "myOption.h"
#include "myPlayScene.h"

namespace my 
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::activeScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // 할당을 해주고 전체를 0으로 초기화해준다 예를들어, resize(5,0)이면 5개의 배열을 0으로 초기화
																			 // 현재 max는 4개이므로 4개의 배열을 0으로 초기화
		mScenes[(UINT)eSceneType::Intro] = new IntroScene(); 
		mScenes[(UINT)eSceneType::Title] = new TitleScene(); 
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); 
		mScenes[(UINT)eSceneType::Option] = new Option(); 

		mScenes[(UINT)eSceneType::Intro]->setName(L"INTRO");
		mScenes[(UINT)eSceneType::Title]->setName(L"TITLE");
		mScenes[(UINT)eSceneType::Play]->setName(L"PLAY");
		mScenes[(UINT)eSceneType::Option]->setName(L"OPTION");

		for (Scene* scene : mScenes)
		{
			if (scene == NULL) continue;

			activeScene = scene;
			scene->Initialize();
 		}

		activeScene = mScenes[(UINT)eSceneType::Intro];
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
		// 현재씬
		activeScene->OnExit();

		CollisionManager::clear();
		//다음씬
		activeScene = mScenes[(UINT)type];
		activeScene->OnEnter();

	}
}
