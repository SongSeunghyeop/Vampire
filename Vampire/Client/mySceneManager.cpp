#include "mySceneManager.h"
#include "myPlayScene.h"
#include "myTitleScene.h"
#include "myIntroScene.h"
#include "TitleSceneUI.h"
#include "InGameOption.h"

namespace my 
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::activeScene = {};

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // �Ҵ��� ���ְ� ��ü�� 0���� �ʱ�ȭ���ش� �������, resize(5,0)�̸� 5���� �迭�� 0���� �ʱ�ȭ
																			 // ���� max�� 4���̹Ƿ� 4���� �迭�� 0���� �ʱ�ȭ
		mScenes[(UINT)eSceneType::Intro] = new IntroScene(); 
		mScenes[(UINT)eSceneType::Title] = new TitleScene(); 
		mScenes[(UINT)eSceneType::TitleUI] = new TitleSceneUI(); 
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); 
		mScenes[(UINT)eSceneType::InGameMenu] = new InGameOption(); 

		mScenes[(UINT)eSceneType::Intro]->SetName(L"INTRO");
		mScenes[(UINT)eSceneType::Title]->SetName(L"TITLE");
		mScenes[(UINT)eSceneType::TitleUI]->SetName(L"TITLEUI");
		mScenes[(UINT)eSceneType::Play]->SetName(L"PLAY");
		mScenes[(UINT)eSceneType::InGameMenu]->SetName(L"MENU");

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
	void SceneManager::LoadScene(eSceneType type) // ������Ʈ,�������� ����� �ٲپ���
	{
		//activeScene->OnExit();
		activeScene = mScenes[(UINT)type];
		//activeScene->OnEnter();
	}
}
