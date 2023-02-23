#include "mySceneManager.h"
#include "myPlayScene.h"
#include "myTitleScene.h"
#include "myMenuScene.h"

namespace my 
{
	std::vector<myScene*> mySceneManager::mScenes = {};
	myScene* mySceneManager::activeScene = {};

	void mySceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // �Ҵ��� ���ְ� ��ü�� 0���� �ʱ�ȭ���ش� �������, resize(5,0)�̸� 5���� �迭�� 0���� �ʱ�ȭ
																			 // ���� max�� 4���̹Ƿ� 4���� �迭�� 0���� �ʱ�ȭ
		mScenes[(UINT)eSceneType::Title] = new TitleScene(); // �÷��� ������ �����Ҵ�
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); // �÷��� ������ �����Ҵ�
		mScenes[(UINT)eSceneType::Menu] = new menuScene(); // �÷��� ������ �����Ҵ�
		mScenes[(UINT)eSceneType::Title]->SetName(L"TITLE");
		mScenes[(UINT)eSceneType::Play]->SetName(L"PLAY");
		mScenes[(UINT)eSceneType::Menu]->SetName(L"MENU");

		activeScene = mScenes[(UINT)eSceneType::Title];

		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Initialize();
 		}
	}

	void mySceneManager::Update()
	{
		activeScene->Update();
	}

	void mySceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}

	void mySceneManager::Release()
	{
		for (myScene* scene : mScenes)
		{
			if (scene == NULL) continue;

			scene->Release();
		}
	}
	void mySceneManager::LoadScene(eSceneType type)
	{
		activeScene->OnExit();
		activeScene = mScenes[(UINT)type];
		activeScene->OnEnter();
	}
}
