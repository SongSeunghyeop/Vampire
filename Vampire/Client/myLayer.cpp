#include "myLayer.h"

namespace my
{
	void myLayer::Initialize()
	{
		for (MyGameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Initialize();
		}
	}
	void myLayer::Update()
	{
		for (MyGameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Update();
		}
	}
	void myLayer::Render(HDC hdc)
	{
		for (MyGameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Render(hdc);
		}
	}
	void myLayer::Release()
	{
		for (MyGameObject* gameobj : mGameobj)
		{
			if (gameobj == NULL) continue;

			gameobj->Release();
		}
	}
	void myLayer::AddGameObj(MyGameObject* obj)
	{
		if (obj == NULL) return;

		mGameobj.push_back(obj);
	}
	myLayer::myLayer()
	{

	}
	myLayer::~myLayer()
	{

	}
}