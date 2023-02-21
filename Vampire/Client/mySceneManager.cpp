#include "mySceneManager.h"
#include "myPlayScene.h"

namespace ya 
{
	std::vector<myScene*> mySceneManager::mScenes = {};

	void mySceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max); // �Ҵ��� ���ְ� ��ü�� 0���� �ʱ�ȭ���ش� �������, resize(5,0)�̸� 5���� �迭�� 0���� �ʱ�ȭ
																			 // ���� max�� 4���̹Ƿ� 4���� �迭�� 0���� �ʱ�ȭ
		mScenes[(UINT)eSceneType::Play] = new PlayScene(); // �÷��� ������ �����Ҵ�
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
