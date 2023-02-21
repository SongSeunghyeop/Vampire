#include "mySceneManager.h"
#include "myPlayScene.h"

namespace ya 
{
	std::vector<myScene*> mySceneManager::mScenes = {};

	void mySceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // 할당을 해주고 전체를 0으로 초기화해준다 예를들어, resize(5,0)이면 5개의 배열을 0으로 초기화
																			 // 현재 max는 4개이므로 4개의 배열을 0으로 초기화
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); // 플레이 씬부터 동적할당
		mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER");

		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Initialize();
		}
	}

	void mySceneManager::Update()
	{
		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Update();
		}
	}

	void mySceneManager::Render(HDC hdc)
	{
		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Render(hdc);
		}
	}

	void mySceneManager::Release()
	{
		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Release();
		}
	}
}
