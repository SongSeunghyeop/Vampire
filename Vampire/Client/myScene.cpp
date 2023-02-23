#include "myScene.h"

namespace my
{
	void myScene::Initialize()
	{
		for (myLayer& layer : mLayer)
		{
			layer.Initialize();
		}
	}

	void myScene::Update()
	{
		for (myLayer& layer : mLayer)
		{
			layer.Update();
		}
	}

	void myScene::Render(HDC hdc)
	{
		for (myLayer& layer : mLayer)
		{
			layer.Render(hdc);
		}
	}

	void myScene::Release()
	{
		for (myLayer& layer : mLayer)
		{
			layer.Release();
		}
	}

	void myScene::OnEnter()
	{

	}
	void myScene::OnExit()
	{

	}

	void myScene::AddGameObj(MyGameObject* obj, eLayerType Layer)
	{
		mLayer[(UINT)Layer].AddGameObj(obj);
	}

	myScene::myScene()
	{
		//mLayer.reserve(5);
		mLayer.resize((UINT)eLayerType::END);
	}

	myScene::~myScene()
	{

	}
}
