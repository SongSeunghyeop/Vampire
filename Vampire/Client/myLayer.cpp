#include "myLayer.h"

namespace my
{
	Layer::Layer()
	{

	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == NULL) continue;

			gameobj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == NULL) continue;

			gameobj->Update();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == NULL) continue;

			gameobj->Render(hdc);
		}
	}
	void Layer::Release()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == NULL) continue;

			gameobj->Release();
		}
	}
	void Layer::AddGameObject(GameObject* gameObj)
	{
		if (gameObj == nullptr)
			return;

		mGameObjects.push_back(gameObj);
	}
}