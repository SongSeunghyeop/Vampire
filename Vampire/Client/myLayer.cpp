#include "myLayer.h"

namespace my
{
	Layer::Layer()
	{

	}
	Layer::~Layer()
	{

	}

	void Layer::Initialize()
	{
		for (GameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Update();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Render(hdc);
		}
	}
	void Layer::Release()
	{
		for (GameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Release();
		}
	}
	void Layer::AddGameObj(GameObject* obj)
	{
		if (obj == NULL) return;

		mGameobj.push_back(obj);
	}
	void Layer::DelGameObj(GameObject* obj)
	{
		if (obj == NULL) return;
		mGameobj.pop_back();
	}
}